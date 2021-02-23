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
struct node
{
	int l,r;
	double s,c;
	LL lazy;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define s(x) b[x].s
	#define c(x) b[x].c
	#define lazy(x) b[x].lazy
}b[800010];
int a[200010];
void upd(int p)
{
	s(p)=s(p<<1)+s(p<<1|1);
	c(p)=c(p<<1)+c(p<<1|1);
}
void upd(int p,double s,double c)
{
	double ss=s(p),cc=c(p);
	s(p)=ss*c+cc*s;
	c(p)=cc*c-ss*s;
}
void spread(int p)
{
	if(lazy(p))
	{
		upd(p<<1,sin(lazy(p)),cos(lazy(p)));
		upd(p<<1|1,sin(lazy(p)),cos(lazy(p)));
		lazy(p<<1)+=lazy(p);
		lazy(p<<1|1)+=lazy(p);
		lazy(p)=0;
	}
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		s(p)=sin(a[l]);
		c(p)=cos(a[l]);
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
void change(int p,int l,int r,int k)
{
	if(l<=l(p)&&r(p)<=r)
	{
		upd(p,sin(k),cos(k));
		lazy(p)+=k;
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) change(p<<1,l,r,k);
	if(r>mid) change(p<<1|1,l,r,k);
	upd(p);
}
double ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return s(p);
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	double ans=0;
	if(l<=mid) ans+=ask(p<<1,l,r);
	if(r>mid) ans+=ask(p<<1|1,l,r);
	return ans;
}
int n,m;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	m=read();
	LL op,x,y,k;
	while(m--)
	{
		op=read();
		x=read();
		y=read();
		if(op==1)
		{
			k=read();
			change(1,x,y,k);
		}
		else if(op==2) printf("%.1lf\n",ask(1,x,y));
	}
	return 0;
}


