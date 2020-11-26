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
#define re register
#define debug printf("Now is %d\n",__LINE__);
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;

template<class T>inline void read(T&x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	re int x=0,fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m; 
int a[500010];
struct node{
	int l,r,sum,lm,rm,m;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define lm(x) b[x].lm
	#define rm(x) b[x].rm
	#define sum(x) b[x].sum
	#define m(x) b[x].m
	#define mid ((l+r)>>1)
	#define Mid ((l(p)+r(p))>>1)
}b[2000040];
IL void upd(node & now,node & ll,node & rr)
{
	now.sum=ll.sum+rr.sum;
	now.lm=max(ll.lm,ll.sum+rr.lm);
	now.rm=max(rr.rm,rr.sum+ll.rm);
	now.m=max(max(ll.m,rr.m),ll.rm+rr.lm);
}
void build(int p,int l,int r)
{
	l(p)=l;r(p)=r;
	if(l==r)
	{
		lm(p)=rm(p)=sum(p)=m(p)=a[l];
		return;
	}
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(b[p],b[p<<1],b[p<<1|1]);
}
void change(int p,int x,int k)
{
	if(l(p)==r(p))
	{
		lm(p)=rm(p)=sum(p)=m(p)=a[l(p)]=k;
		return;
	}
	if(x>Mid) change(p<<1|1,x,k);
	else change(p<<1,x,k);
	upd(b[p],b[p<<1],b[p<<1|1]);
}
node & ask(int p,int l,int r)
{
	if(l(p)==r(p)) return b[p];
	if(r<=Mid) return ask(p<<1,l,r);
	else if(l>Mid) return ask(p<<1|1,l,r);
	node now;
	upd(now,ask(p<<1,l,Mid),ask(p<<1|1,Mid+1,r));
	return now;
}
int main()
{
	freopen("P4513_4.in","r",stdin);
	freopen("4513_4.out","w",stdout);
	n=read();m=read();
	for(re int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	re int t,x,y;
	build(1,1,n);
	while(m--)
	{
		t=read();x=read();y=read();
		if(t==1)
		{
			write(ask(1,min(x,y),max(x,y)).m);
		}
		else
		{
			change(1,x,y);
		}
	}
	return 0;
}

