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
	int l,r,v;
	bool lazy;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define v(x) b[x].v
	#define lazy(p) b[x].lazy
}b[500010*4];
char ch[500010];
void upd(int p)
{
	if(v(p<<1)==v(p<<1|1)) v(p)=v(p<<1);
	else v(p)=-1;
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		v(p)=ch[l]-'A';
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
		lazy(p<<1)=lazy(p<<1|1)=1;
		v(p<<1)=v(p<<1|1)=v(p);
		lazy(p)=0;
	}
}
void change(int p,int l,int r,int k)
{
	if(l<=l(p)&&r(p)<=r)
	{
		lazy(p)=1;
		v(p)=k;
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) change(p<<1,l,r,k);
	if(r>mid) change(p<<1|1,l,r,k);
	upd(p);
}
bool same;
int color;
void ask_same(int p,int l,int r)
{
	if(!same) return;
	if(l<=l(p)&&r(p)<=r)
	{
		
	}
}
int main()
{
	n=read();
	scanf("%s",ch+1);
	m=read();
	int x,y;
	char t,op;
	while(m--)
	{
		t=getchar();
		while(t!='A'&&t!='B') t=getchar();
		if(t=='A')
		{
			x=read();
			y=read();
			if(x<y) x^=y^=x^=y;
			op=getchar();
			while(op!='A'&&op!='B') op=getchar();
			op-='A';
			change(1,x,y,op);
		}
		else
		{
			x=read();
			y=read();
			if(x<y) x^=y^=x^=y;
			same=1;
			color=0;
			ask_same(1,x,y);
			if(color==-1) same=0;
			if(same)
			{
				if(x!=1&&y!=n)
				{
					if(ask(x-1)!=ask(y+1)) same=0;
				}
			}
			if(same) printf("Yes\n");
			else printf("No\n");
		}
		
	}
	return 0;
}


