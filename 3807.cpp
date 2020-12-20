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
LL p;
LL fact[200010];
LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=a*ans%p;
		b>>=1;
		a=a*a%p;
	}
	return ans;
}
void pre()
{
	fact[0]=1;
	for(re int i=1;i<=p+10;i++)
	{
		fact[i]=fact[i-1]*i%p;
	}
	
}
LL C(LL n,LL m)
{
	if(m>n) return 0;
	return fact[n]*qpow(fact[m],p-2)%p*qpow(fact[n-m],p-2)%p;
}
LL lucas(LL n,LL m)
{
	if(m==0) return 1;
	return C(n%p,m%p)*lucas(n/p,m/p)%p;
}

int n,m,t;
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		p=read();
		pre();
//		cout<<fact[2]<<" "<<fact[4]<<endl;
		write(lucas(n+m,n));
	}
	return 0;
}


