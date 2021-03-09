/**************************************************************
 * Problem: 7419
 * Author: Vanilla_chan
 * Date: 20210306
**************************************************************/
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
#define N 1000010
int n,t;
LL ans,len;
#define mod 998244353ll
#define ny2 499122177ll
#define ny4 748683265ll
#define ny8 873463809ll
LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
LL pow2[N<<3];
LL s1[N<<3],s2[N<<3];
LL inv[N<<5];
int i;
void init()
{
	pow2[0]=1;
	pow2[1]=2;
	for(i=1;i<=2000010;i++)
	{
		pow2[i]=pow2[i-1]*2%mod;
	}
	for(i=1;i<=1000010;i++)
	{
		s1[i]=(ny4+ny2)%mod+mod-qpow(pow2[i+1],mod-2);
		s1[i]=(s1[i]%mod+mod)%mod;
	}
	for(i=1;i<=1000010;i++)
	{
		s1[i]+=s1[i-1];
		s1[i]%=mod;
	}
	for(i=1;i<=1000000;i++)
	{
		s2[i]=pow2[2*i]+pow2[2*i+1]-pow2[i+1];
		s2[i]=(s2[i]%mod+mod)%mod;
	}
	for(i=1;i<=1000000;i++)
	{
		s2[i]=s2[i]*ny8%mod;
		s2[i]+=s2[i-1];
		s2[i]%=mod;
	}

}
int main()
{
	init();
	//freopen("temp.in","r",stdin);
	//freopen("temp.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		ans=pow2[2*n]*s1[n]%mod-s2[n]+mod;
		write(ans%mod);
	}
	return 0;
}

