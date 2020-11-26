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
using namespace std;
// 3 7 9 7 ÷ÿ ππ 
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
    int g=0;
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}

int n,m;
int a[200010];
struct node{
	int p,l,r,ll,rr,v;
	/*
	ll:The leftest l/r kuohao , 0/1/2
	rr:tongshang
	*/
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define v(x) b[x].r
	#define ll(x) b[x].ll
	#define rr(x) b[x].rr
}b[800010]; 
void upd(int p)
{
	v(p)=v(p*2)+v(p*2+1);
	if(rr(p*2)==2&&ll(p*2+1)==1) v(p)++;
	if(ll(p*2)) ll(p)=ll(p*2);
	else ll(p)=ll(p*2+1);
	if(rr(p*2+1)) rr(p)=rr(p*2+1);
	else rr(p)=rr(p*2);
}
void build(int p,int l,int r)
{
	cout<<"build l="<<l<<" r="<<r<<" p="<<p<<endl;
	l(p)=l;r(p)=r;
	if(l==r)
	{
		if(a[l]==1) ll(p)=rr(p)=1;
		if(a[l]==2) ll(p)=rr(p)=2; 
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	upd(p);
}
void change(int p,int x,int k)
{
	if(l(p)==r(p))
	{
		a[l(p)]=k;
		v(p)=0;
		if(k==1) ll(p)=rr(p)=1;
		else if(k==2) rr(p)=ll(p)=2;
		else rr(p)=ll(p)=0;
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) change(p*2,x,k);
	else change(p*2+1,x,k);
	upd(p);
}
int ask(int l,int r,int p)
{
	cout<<"l="<<l<<" r="<<r<<" p="<<p<<endl;
	if(l==l(p)&&r==r(p)) return v(p);
	int mid=(l(p)+r(p))>>1,val=0;
	if(r<=mid) return ask(l,r,p*2);
	if(l>mid) return ask(l,r,p*2+1);
	val=ask(l,mid,p*2);
	val+=ask(mid+1,r,p*2+1);
	if(l<=rr(p*2)&&r>=ll(p*2+1)&&rr(p*2)==1&&ll(p*2+1)==2) val++;
	return val;
}
int main()
{
	n=read();
	m=read();
	int t,x,y;
	char ch;
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
			}while(ch!=' '&&ch!='\n');
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
//	for(int i=1;i<=4*n;i++)
//	{
////		cout<<"p="<<i<<" l="<<l(i)<<" r="<<r(i)<<" v="<<v(i)<<" lr="<<lr(i)<<" rl="<<rl(i)<<" ll="<<ll(i)<<" rr="<<rr(i)<<endl;
//	}
	return 0;
}

