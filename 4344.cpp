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
//区间修改为0
//区间求和
//区间覆盖？
//区间最长连续0 
struct node
{
	int l,r,v;
	int lazy;
	
	int lmax,rmax,zmax;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define v(x) b[x].v
	#define lazy(x) b[x].lazy
	
	#define v0(x) (r(x)-l(x)+1-v(x))
	
	#define lmax(x) b[x].lmax
	#define rmax(x) b[x].rmax
	#define zmax(x) b[x].zmax
}b[800010];
int n,m;
node upd(node a,node b)
{
	return (node){a.l,b.r,a.v+b.v,0,(a.lmax==a.r-a.l+1)?a.lmax+b.lmax:a.lmax,(b.rmax==b.r-b.l+1)?b.rmax+a.rmax:b.rmax,max(max(a.zmax,b.zmax),a.rmax+b.lmax)};
}
void upd(int p)
{
	v(p)=v(p<<1)+v(p<<1|1);
	lmax(p)=lmax(p<<1);
	if(lmax(p<<1)==r(p<<1)-l(p<<1)+1) lmax(p)+=lmax(p<<1|1);
	rmax(p)=rmax(p<<1|1);
	if(rmax(p<<1|1)==r(p<<1|1)-l(p<<1|1)+1) rmax(p)+=rmax(p<<1);
	zmax(p)=max(max(zmax(p<<1),zmax(p<<1|1)),rmax(p<<1)+lmax(p<<1|1));
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		v(p)=lmax(p)=rmax(p)=zmax(p)=1;
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
void spread(int p)
{
	if(lazy(p))
	{
		lazy(p<<1)=lazy(p<<1|1)=lazy(p);
		lazy(p)--;
		if(lazy(p))
		{
			v(p<<1)=v(p<<1|1)=lmax(p<<1)=lmax(p<<1|1)=rmax(p<<1)=rmax(p<<1|1)=zmax(p<<1)=zmax(p<<1|1)=0;
		}
		else
		{
			v(p<<1)=lmax(p<<1)=rmax(p<<1)=zmax(p<<1)=r(p<<1)-l(p<<1)+1;
			v(p<<1|1)=lmax(p<<1|1)=rmax(p<<1|1)=zmax(p<<1|1)=r(p<<1|1)-l(p<<1|1)+1;
		}
		lazy(p)=0;
	}
}
void change(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		v(p)=lmax(p)=rmax(p)=zmax(p)=0;
		lazy(p)=1;
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) change(p<<1,l,r);
	if(r>mid) change(p<<1|1,l,r);
	upd(p);
}
void change_first(int p,int l,int r,int &last)
{
	if(last<=0) return;
	if(l<=l(p)&&r(p)<=r&&v0(p)<=last)
	{
		v(p)=lmax(p)=rmax(p)=zmax(p)=r(p)-l(p)+1;
		lazy(p)=2;
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) change_first(p<<1,l,r,last);
	if(r>mid) change_first(p<<1|1,l,r,last);
	upd(p);
}
int ask_one(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return v(p);
	}
	spread(p);
	int ans=0,mid=l(p)+r(p)>>1;
	if(l<=mid) ans+=ask_one(p<<1,l,r);
	if(r>mid) ans+=ask_one(p<<1|1,l,r);
	return ans;
}
node ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return b[p];
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(r<=mid) return ask(p<<1,l,r);
	if(l>mid) return ask(p<<1|1,l,r);
	return upd(ask(p<<1,l,r),ask(p<<1|1,l,r)); 
}
int main()
{
	n=read();
	m=read();
	build(1,1,n);
	int op,l,r,ans;
	while(m--)
	{
		op=read();
		if(op==0)
		{
			l=read();
			r=read();
			change(1,l,r);
		}
		else if(op==1)
		{
			l=read();
			r=read();
			ans=ask_one(1,l,r);
			change(1,l,r);
			l=read();
			r=read();
			change_first(1,l,r,ans);
		}
		else
		{
			l=read();
			r=read();
			write(ask(1,l,r).zmax);
		}
	}
	return 0;
}


