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
#define N 500010
#define S 800
int n,m,s,block,L[N],R[N],belong[N],zs[S][S],cnt[N],a[N],sum[N],pos[N];
vector<int>vec[N];
int lastans;
map<int,int>ys;
int main()
{
	freopen("5048.in","r",stdin);
	freopen("5048-hsh.out","w",stdout);
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
		ys[a[i]=read()]=0;
	}
	int rank=1;
	for(map<int,int>::iterator it=ys.begin();it!=ys.end();it++)
	{
		it->second=rank;
		rank++;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=ys[a[i]];
		vec[a[i]].push_back(i);
		pos[i]=vec[a[i]].size()-1;
	}
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
				zs[i][j]=max(zs[i][j],cnt[a[k]]);
			}
		}
	}
	int ans=0;
	for(int t=1,x,y;t<=m;t++)
	{
		x=read();
		y=read();
		x^=ans;
		y^=ans;
		if(x>y) swap(x,y);
		ans=0;
		if(belong[y]-belong[x]<=3)
		{
			for(int i=x;i<=y;i++) sum[a[i]]=0;
			for(int i=x;i<=y;i++)
			{
				sum[a[i]]++;
				ans=max(ans,sum[a[i]]);
			}
		}
		else
		{
			ans=zs[belong[x]+1][belong[y]-1];
			for(int i=x,now;i<=R[belong[x]];i++)
			{
				now=pos[i];
				while(now+ans<vec[a[i]].size()&&vec[a[i]][now+ans]<=y) ans++;         
			}
			for(int i=L[belong[y]],now;i<=y;i++)
			{
				now=pos[i];
				while(now-ans>=0&&vec[a[i]][now-ans]>=x) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

