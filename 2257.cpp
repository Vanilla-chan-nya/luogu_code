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

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define N 10000010
bool book[N];
int prime[N],mu[N],g[N],cnt;
LL sum[N];
void init()
{
	mu[1]=1;
	for(int i=2;i<=10000000;i++)
	{
		if(!book[i]) prime[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*prime[j]<=10000000;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0) break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int j=1;j<=cnt;j++)
	{
		for(int i=1;i*prime[j]<=10000000;i++)
		{
			g[i*prime[j]]+=mu[i];
		}
	}
	for(int i=1;i<=10000000;i++) sum[i]=sum[i-1]+g[i];
}
LL ask(int x,int y)
{
	LL ans=0;
	int top=min(x,y);
	for(int l=1,r;l<=top;l=r+1)
	{
		r=min(x/(x/l),y/(y/l));
		ans+=(sum[r]-sum[l-1])*(1ll*x/l)*(1ll*y/l);
	}
	return ans;
}
int t;
int main()
{
	t=read();
	init();
	while(t--)
	{
		write(ask(read(),read()));
	}

	return 0;
}


