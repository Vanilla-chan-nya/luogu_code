#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
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

inline LL read()
{
	LL x=0,fu=1;
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
#define p 998244353
LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
LL fact[5000010],D[5000010];
LL C(LL n,LL m)
{
	if(n<m) return 1;
	return fact[n]*qpow(fact[m],p-2)%p*qpow(fact[n-m],p-2)%p;
}
void pre()
{
	fact[0]=1;
	for(re LL i=1;i<=5000000;i++) fact[i]=fact[i-1]*i%p;
	D[0]=1;
	D[1]=0;
	for(LL i=2;i<=5000000;i++)
	{
		D[i]=2*i%p*(2*i-2)%p*(D[i-1]+2*(i-1)%p*D[i-2]%p)%p;
	}
}
int main()
{
	pre();
	int t=read();
	while(t--)
	{
		int n,k;
		n=read();
		k=read();
		write(qpow(C(n,k)%p,2)*D[n-k]%p*qpow(2,k)%p*fact[k]%p);
	}
	
	return 0;
}


