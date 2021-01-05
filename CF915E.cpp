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
struct node
{
	int l,r;
	int sum;
	bool lazy,k;
	int ls,rs;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define sum(x) b[x].sum
	#define lazy(x) b[x].lazy
	#define k(x) b[x].k
	#define ls(x) b[x].ls
	#define rs(x) b[x].rs
}b[4000100];
int cnt;
IL void upd(int p)
{
	sum(p)=sum(ls(p))+sum(rs(p));
}
void spread(int p)
{
	if(lazy(p))
	{
		if(l(p)!=r(p))
		{
			if(ls(p)) sum(p<<1)=r(p<<1)-l(p<<1)+1;
			sum(p<<1|1)=r(p<<1|1)-l(p<<1|1)+1;
			sum(p<<1)*=k(p);
			sum(p<<1|1)*=k(p);
			lazy(p<<1)=1;
			lazy(p<<1|1)=1;
			k(p<<1)=k(p<<1|1)=k(p);
		}
		k(p)=0;
		lazy(p)=0;
	}
}
void change(int p,int l,int r,int k)
{
	if(l<=l(p)&&r(p)<=r)
	{
		lazy(p)=1;
		k(p)=k;
		sum(p)=r(p)-l(p)+1;
		sum(p)*=k;
		return;
		
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) change(p<<1,l,r,k);
	if(r>mid) change(p<<1|1,l,r,k);
	upd(p);
}
int n,m;
int main()
{
	n=read();
	m=read();
	build(1,1,n);
	int k,l,r;
	while(m--)
	{
		l=read();
		r=read();
		k=read();
		change(1,l,r,k-1);
		write(sum(1));
	}
	return 0;
}

