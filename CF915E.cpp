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
	node(int ll=0,int rr=0)
	{
		l=ll;
		r=rr;
		sum=r-l+1;
		lazy=k=ls=rs=0;
	}
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
	if(!ls(p)) b[ls(p)=++cnt]=node(l(p),l(p)+r(p)>>1);
	if(!rs(p)) b[ls(p)=++cnt]=node((l(p)+r(p)>>1)+1,r(p));
	sum(p)=sum(ls(p))+sum(rs(p));
}
void spread(int p)
{
	debug cout<<"spread "<<p<<endl;
	if(lazy(p))
	{
		if(l(p)!=r(p))
		{
			if(!ls(p))
			{
				int mid=l(p)+r(p)>>1;
				b[ls(p)=++cnt]=node(l(p),mid);
			}
			if(!rs(p)) 
			{
				int mid=l(p)+r(p)>>1;
				b[rs(p)=++cnt]=node(mid+1,r(p));
			}
			sum(ls(p))=r(ls(p))-l(ls(p))+1;
			sum(rs(p))=r(rs(p))-l(rs(p))+1;
			sum(ls(p))*=k(p);
			sum(rs(p))*=k(p);
			lazy(ls(p))=1;
			lazy(rs(p))=1;
			k(ls(p))=k(rs(p))=k(p);
		}
		k(p)=0;
		lazy(p)=0;
	}
}
void change(int p,int l,int r,int k)
{
	debug cout<<"now="<<p<<" lp="<<l(p)<<" rp="<<r(p)<<endl;
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
	if(l<=mid)
	{
		if(!ls(p))
		{
			b[ls(p)=++cnt]=node(l(p),mid);
		}
		change(ls(p),l,r,k);
	}
	if(r>mid)
	{
		if(!rs(p)) 
		{
			b[rs(p)=++cnt]=node(mid+1,r(p));
		}
		change(rs(p),l,r,k);
	}
	upd(p);
}
int n,m;
int main()
{
	n=read();
	m=read();
	b[cnt=1]=node(1,n);
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

