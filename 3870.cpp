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
	int l,r,sum;
	IL int size()
	{
		return r-l+1;
	}
	bool lazy;
	#define size(x) b[x].size()
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define sum(x) b[x].sum
	#define lazy(x) b[x].lazy
}b[400010];
IL void upd(int p)
{
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
void spread(int p)
{
	if(lazy(p))
	{
		lazy(p<<1)^=1;
		lazy(p<<1|1)^=1;
		sum(p<<1)=size(p<<1)-sum(p<<1);
		sum(p<<1|1)=size(p<<1|1)-sum(p<<1|1);
		lazy(p)=0;
	}
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		sum(p)=0;
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
void change(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		lazy(p)^=1;
		sum(p)=size(p)-sum(p);
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) change(p<<1,l,r);
	if(r>mid) change(p<<1|1,l,r);
	upd(p);
}
int ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return sum(p);
	}
	spread(p);
	int mid=l(p)+r(p)>>1,ans=0;
	if(l<=mid) ans+=ask(p<<1,l,r);
	if(r>mid) ans+=ask(p<<1|1,l,r);
	return ans;
}
int main()
{
	n=read();
	m=read();
	build(1,1,n);
	for(int i=1,op,x,y;i<=m;i++)
	{
		op=read();
		x=read();
		y=read();
		if(op==0)
		{
			change(1,x,y);
		}
		else write(ask(1,x,y));
	}
	
	return 0;
}


