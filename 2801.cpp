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
#define N 1000010
int n,m,block,s,L[N],R[N],belong[N];
int sum[N],a[N];
int ys[N];
IL void sort(int x)
{
	for(int i=L[x];i<=R[x];i++) ys[i]=a[i];
	sort(ys+L[x],ys+R[x]+1);
//	cout<<"sort:"<<L[x]<<" "<<R[x]<<endl;
}
IL int count(int x,LL c)
{
	c-=sum[x];
	int l=L[x],r=R[x],mid,ans=0;
	while(l<=r)
	{
		mid=l+r>>1;
		if(ys[mid]>=c)
			r=mid-1,ans=R[x]-mid+1;
		else
			l=mid+1;
	}
	return ans;
}
int main()
{
	n=read();m=read();
	block=sqrt(n);
	s=n/block;
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
		a[i]=read();
	}
	for(int i=1;i<=s;i++)
	{
		sort(i);
	}
	for(int i=1,x,y,c;i<=m;i++)
	{
		char op;
		cin>>op>>x>>y>>c;
		if(op=='M')
		{
			if(belong[x]==belong[y])
			{
				for(int j=x;j<=y;j++) a[j]+=c;
				sort(belong[x]);
			}
			else
			{
				for(int j=x;j<=R[belong[x]];j++) a[j]+=c;
				for(int j=L[belong[y]];j<=y;j++) a[j]+=c;
				for(int j=belong[x]+1;j<=belong[y]-1;j++) sum[j]+=c;
				sort(belong[x]);
				sort(belong[y]);
			}
		}
		else
		{
			int ans=0;
			if(belong[x]==belong[y])
			{
				for(int j=x;j<=y;j++)
				{
					if(a[j]+sum[belong[x]]>=c) ans++;
				}
			}
			else
			{
				for(int j=x;j<=R[belong[x]];j++) if(a[j]+sum[belong[x]]>=c) ans++;
				for(int j=L[belong[y]];j<=y;j++) if(a[j]+sum[belong[y]]>=c) ans++;
				for(int j=belong[x]+1;j<=belong[y]-1;j++)
				{
					ans+=count(j,c);
				}
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}


