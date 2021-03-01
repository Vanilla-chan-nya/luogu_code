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
int n,m;
struct node
{
	int l,r,v;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define v(x) b[x].v
}b[4010];
int gcd(int a,int b)
{
	if(b) return gcd(b,a%b);
	return a;
}
void upd(int p)
{
	v(p)=gcd(v(p<<1),v(p<<1|1));
}
void build(int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if(l==r)
	{
		v(p)=read();
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
int ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return v(p);
	}
	int mid=l(p)+r(p)>>1,ans=0;
	if(l<=mid) ans=gcd(ask(p<<1,l,r),ans);
	if(r>mid) ans=gcd(ask(p<<1|1,l,r),ans);
	return ans;
}
int main()
{
	n=read();
	m=read();
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		write(ask(1,a,b));
	}
	return 0;
}


