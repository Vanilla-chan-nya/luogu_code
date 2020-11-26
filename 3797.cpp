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
#define ULL unsigned long long
#define re register
using namespace std;
//https://www.luogu.com.cn/blog/wjyyy/solution-p3797
template<class T>inline void read(T&x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    re int g=0;
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m;
int a[200010],L[800010],R[800010],V[800010],RL[800010],LR[800010],RR[800010],LL[800010];
#define l(x) L[x]
#define r(x) R[x]
#define v(x) V[x]
#define lr(x) LR[x]
#define rl(x) RL[x]
#define ll(x) LL[x]
#define rr(x) RR[x]
#define mid ((l+r)>>1)
#define Mid ((l(p)+r(p))>>1) 
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
IL void upd(int p)
{
	v(p)=v(p<<1)+v(p<<1|1);
	if(rl(p<<1)>rr(p<<1)&&lr(p<<1|1)<ll(p<<1|1)) v(p)++;
	ll(p)=min(ll(p<<1),ll(p<<1|1));
	lr(p)=min(lr(p<<1),lr(p<<1|1));
	rr(p)=max(rr(p<<1),rr(p<<1|1));
	rl(p)=max(rl(p<<1),rl(p<<1|1));
}
void build(int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if(l(p)==r(p)){
		v(p)=0;
		ll(p)=(a[l(p)]==1?l(p):233333);
		lr(p)=(a[l(p)]==2?l(p):233333);
		rr(p)=(a[l(p)]==2?l(p):0);
		rl(p)=(a[l(p)]==1?l(p):0);
		return;
	}
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
void change(int p,int x,int k)
{
	if(l(p)==r(p))
	{
		a[l(p)]=k;
		v(p)=0;
		ll(p)=(a[l(p)]==1?l(p):233333);
		lr(p)=(a[l(p)]==2?l(p):233333);
		rr(p)=(a[l(p)]==2?l(p):0);
		rl(p)=(a[l(p)]==1?l(p):0);
		return;
	}
	if(x<=Mid) change(p<<1,x,k);
	else change(p<<1|1,x,k);
	upd(p);
}
int ask(int l,int r,int p)
{
	if(l==l(p)&&r==r(p)) return v(p);
	if(r<=Mid) return ask(l,r,p<<1);
	if(l>Mid) return ask(l,r,p<<1|1);
	if(l<=rl(p<<1)&&r>=lr(p<<1|1)&&rl(p<<1)>rr(p<<1)&&ll(p<<1|1)>lr(p<<1|1)) return ask(l,Mid,p<<1)+1+ask(Mid+1,r,p<<1|1);
	return ask(l,Mid,p<<1)+ask(Mid+1,r,p<<1|1);
}
int main()
{
	n=read();
	m=read();
	re int t,x,y;
	re char ch;
	a[1]=1,a[n]=2;
	build(1,1,n);
	while(m--)
	{
		t=read();
		if(t==1)
		{
			x=read();
			do{
				ch=getchar();
			}while(ch==' '||ch=='\n');//这个地方坑死人啦！ 
			if(ch=='(') change(1,x,1);
			else if(ch==')') change(1,x,2);
			else change(1,x,0);
		}
		else
		{
			x=read();
			y=read();
			write(ask(x,y,1));
		}
	}
	return 0;
}
