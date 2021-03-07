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
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
#define N 50010
int prime[N],cnt,mu[N];
bool book[N];
LL sum[N],s[N];
void init()
{
	sum[1]=mu[1]=1;
	for(int i=2;i<=50000;i++)
	{
		if(!book[i]) prime[++cnt]=i,book[i]=1,mu[i]=-1;
		for(int j=1;j<=cnt&&i*prime[j]<=50000;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
		sum[i]=sum[i-1]+mu[i];
	}
	for(int i=1;i<=50000;i++)
	{
		for(int l=1,r=0;l<=i;l=r+1)
		{
			r=i/(i/l);
			s[i]+=(1ll*r-l+1)*(i/l);
		}
	}
}
int t;
LL ans;
int n,m,top;
int main()
{
	t=read();
	init();
	while(t--)
	{
		n=read();
		m=read();
		ans=0;
		top=min(n,m);
		for(int l=1,r;l<=top;l=r+1)
		{
			r=min(n/(n/l),m/(m/l));
			ans+=(sum[r]-sum[l-1])*s[n/r]*s[m/r];
		}
		write(ans);
	}
	
	return 0;
}


