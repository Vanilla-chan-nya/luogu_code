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
using namespace std;
/*
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif


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
*/
#define N 50010
bool book[N];
int prime[N],mu[N],sum[N],cnt,k;
int i,j;
void init()
{
	mu[1]=1;
	for(i=2;i<=50000;i++)
	{
		if(!book[i]) mu[i]=-1,prime[++cnt]=i;
		for(j=1;j<=cnt&&i*prime[j]<=50000;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0) break;
			else mu[i*prime[j]]=-mu[i];
		}
	}
	for(i=1;i<=50000;i++) sum[i]=sum[i-1]+mu[i];
}
IL int min(const int& x,const int& y)
{
	if(x<y) return x;
	return y;
}
LL ask(int x,int y)
{
	int top=min(x,y);
	LL ans=0;
	for(int l=1,r=0;l<=top;l=r+1)
	{
		r=min(x/(x/l),y/(y/l));
		ans+=(sum[r]-sum[l-1])*(x/(1ll*l*k))*(1ll*y/(l*k));
	}
	return ans;
}
int t;
int a,b,c,d;
int main()
{
	scanf("%d",&t);
	init();
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("%lld\n",(ask(b,d)-ask(b,c-1)-ask(a-1,d)+ask(a-1,c-1)));
	}
	return 0;
}


