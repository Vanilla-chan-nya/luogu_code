#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
using namespace std;

template<class T>inline void read(T&x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define N 40010
#define S 300
int n,m,s,block,L[N],R[N],belong[N],zs[S][S],cnt[N],a[N],f[S][N],sum[N];
int rys[N];
int lastans;
map<int,int>ys;
int main()
{
	n=read();m=read();
	s=sqrt(n);
	block=n/s;
	for(int i=1;i<=s;i++)
	{
		L[i]=n/s*(i-1)+1;
		R[i]=n/s*i;
	}
	R[s]=n;
	for(int i=1;i<=s;i++)
	{
		for(int j=L[i];j<=R[i];j++)
		{
			belong[j]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ys[a[i]]=0;
	}
	int rank=1;
	for(map<int,int>::iterator it=ys.begin();it!=ys.end();it++)
	{
		rys[rank]=it->first;
		it->second=rank;
		rank++;
	}
	for(int i=1;i<=n;i++) a[i]=ys[a[i]];
//	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	for(int i=1;i<=s;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=s;j++)
		{
			zs[i][j]=zs[i][j-1];
			for(int k=L[j];k<=R[j];k++)
			{
				cnt[a[k]]++;
				if(cnt[a[k]]>cnt[zs[i][j]] || (cnt[a[k]]==cnt[zs[i][j]]&&a[k]<zs[i][j])) zs[i][j]=a[k];
			}
		}
	}
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=ys.size();j++) f[i][j]=f[i-1][j];
		for(int j=L[i];j<=R[i];j++)
		{
			f[i][a[j]]++;
		}
	}
	for(int t=1,x,y;t<=m;t++)
	{
		cin>>x>>y;
		x=(x+lastans-1)%n+1;
		y=(y+lastans-1)%n+1;
		if(x>y) x^=y^=x^=y;
		LL ans=0;
		if(belong[y]-belong[x]<=3)
		{
			for(int i=x;i<=y;i++) sum[a[i]]=0;
			for(int i=x;i<=y;i++)
			{
				sum[a[i]]++;
				if(sum[a[i]]>sum[ans] || (sum[a[i]]==sum[ans]&&a[i]<ans)) ans=a[i];
			}
		}
		else
		{
			ans=zs[belong[x]+1][belong[y]-1];
			sum[ans]=0;
			for(int i=x;i<=R[belong[x]];i++)
			{
				sum[a[i]]=0;
			}
			for(int i=L[belong[y]];i<=y;i++)
			{
				sum[a[i]]=0;
			}
			for(int i=x;i<=R[belong[x]];i++)
			{
				sum[a[i]]++;
				if(f[belong[y]-1][a[i]]-f[belong[x]][a[i]]+sum[a[i]]>f[belong[y]-1][ans]-f[belong[x]][ans]+sum[ans] || (f[belong[y]-1][a[i]]-f[belong[x]][a[i]]+sum[a[i]]==f[belong[y]-1][ans]-f[belong[x]][ans]+sum[ans]&&a[i]<ans)) ans=a[i];
			}
			for(int i=L[belong[y]];i<=y;i++)
			{
				sum[a[i]]++;
				if(f[belong[y]-1][a[i]]-f[belong[x]][a[i]]+sum[a[i]]>f[belong[y]-1][ans]-f[belong[x]][ans]+sum[ans] || (f[belong[y]-1][a[i]]-f[belong[x]][a[i]]+sum[a[i]]==f[belong[y]-1][ans]-f[belong[x]][ans]+sum[ans]&&a[i]<ans)) ans=a[i];
			}
		}
		cout<<(lastans=rys[ans])<<endl;
	}
	return 0;
}


