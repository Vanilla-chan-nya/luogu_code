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
void exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
LL sum,p,k,a,x,y,kn;
int n;
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
int main()
{
	n=read();
	p=read();
	kn=k=read();
	for(int i=1;i<=n;i++)
	{
		a=read();
		x=0;
		exgcd(a,p,x,y);
		x=(x%p+p)%p;
		sum+=qpow(k,i)*x;
	}
	write(sum);
	return 0;
}


