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


int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define N 6000010
int mu[N],prime[N],cnt,sum[N];
bool book[N];
void init()
{
	mu[1]=1;
	for(LL i=2;i<=6000000;i++)
	{
		if(!book[i]) prime[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&prime[j]*i<=6000000;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0) break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=6000000;i++)
	{
		sum[i]=sum[i-1]+mu[i];
	}
}
LL ask(int x,int y)
{
	LL ans=0;
	int top=min(x,y);
	for(int l=1,r=0;l<=top;l=r+1)
	{
		r=min(x/(x/l),y/(y/l));
		ans+=(sum[r]-sum[l-1])*(1ll*x/(l))*(1ll*y/(l));
        cout<<"l="<<l<<" r="<<r<<endl;
	}
	return ans;
}
int t,a,b;
int main()
{
	cin>>t;
	init();
	while(t--)
	{
		cin>>a>>b;
		cout<<ask(a,b)<<endl;
	}
	
	return 0;
}

