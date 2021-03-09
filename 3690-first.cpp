/**************************************************************
 * Problem: 3690-first
 * Author: Vanilla_chan
 * Date: 20210308
**************************************************************/
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
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m;
#define N 1000010
#define check(x) (rs[f[(x)]]==(x))
int f[N],ls[N],rs[N],flag[N];
int xsum[N],val[N];
bool isroot(int p)
{
	return ls[f[p]]!=p&&rs[f[p]]!=p;
}
void spread(int p)
{
	if(!p||!flag[p]) return;
	flag[ls[p]]^=1;
	flag[rs[p]]^=1;
	flag[p]=0;
	swap(ls[p],rs[p]);
}
void upd(int x)
{
	xsum[x]=xsum[ls[x]]^xsum[rs[x]]^val[x];
}
void rotate(int x)
{
	int y=f[x],z=f[y],b=ls[y]==x?rs[x]:ls[x];
	if(!isroot(y))
	{
		if(ls[z]==y) ls[z]=x;
		else rs[z]=x;
	}
	f[x]=z;
	f[y]=x;
	if(b) f[b]=y;
	if(ls[y]==x) ls[y]=b,rs[x]=y;
	else rs[y]=b,ls[x]=y;
	
	upd(y);upd(x);
}
int stac[N],top;
void splay(int x)
{
	stac[top=1]=x;
	for(int i=x;!isroot(i);i=f[i]) stac[++top]=f[i];
	while(top) spread(stac[top--]);
	while(!isroot(x))
	{
		if(!isroot(f[x]))
		{
			if(check(x)==check(f[x])) rotate(f[x]);
			else rotate(x);
		}
		rotate(x);
	}
}
void access(int x)
{
	for(int y=0;x;y=x,x=f[x])
	{
		splay(x);
		rs[x]=y;
		upd(x);
		//if(y) f[y]=x;
	}
}
void make_root(int x)
{
	access(x);
	splay(x);
	flag[x]^=1;
}
int find_root(int x)//???getf(x),?????????
{
	access(x);
	splay(x);
	while(ls[x]) x=ls[x],spread(x);
	splay(x);
	return x;
}
void split(int x,int y)//????x->y
{
	make_root(x);
	access(y);
	splay(y);
}
bool link(int x,int y)//??
{
	make_root(x);//
	if(find_root(y)==x) return 0;//???????
	f[x]=y;//????,????
	return 1;
}
void cut(int x,int y)//????(x,y)???
{
	split(x,y);
	
	/*make_root(x);
	access(y);
	splay(y);*/
	
	if(ls[y]==x)//????????
	ls[y]=f[x]=0;
}
int op,x,y;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++) val[i]=xsum[i]=read();
	while(m--)
	{
		op=read();
		x=read();
		y=read();
		if(op==0)
		{
			split(x,y);
			write(xsum[y]);
		}
		else if(op==1)
		{
			link(x,y);
		}
		else if(op==2)
		{
			cut(x,y);
		}
		else if(op==3)
		{
			access(x);
			splay(x);
			val[x]=y;
			upd(x);
		}
	}
	
	return 0;
}


