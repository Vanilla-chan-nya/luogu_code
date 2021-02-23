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
	int f,ls,rs,v,dist;
	#define f(x) b[x].f
	#define ls(x) b[x].ls
	#define rs(x) b[x].rs
	#define v(x) b[x].v
	#define dist(x) b[x].dist
}b[100010];
int getf(int x)
{
	if(f(x)==x) return x;
	return f(x)=getf(f(x));
}
int merge(int x,int y)
{
	if(!x) return y;
	if(!y) return x;
	if(v(x)>v(y)||(v(x)==v(y)&&x>y)) swap(x,y);//let x<y
	rs(x)=merge(rs(x),y);
	if(dist(rs(x))>dist(ls(x))) swap(ls(x),rs(x));//liftist heap
//	f(ls(x))=f(rs(x))=f(x)=x;
	if(!rs(x)) dist(x)=0;
	else dist(x)=dist(rs(x))+1;
	return x;
}
void pop(int x)
{
	v(x)=-1;
	f(ls(x))=ls(x);
	f(rs(x))=rs(x);
	f(ls(x))=f(rs(x))=f(x)=merge(ls(x),rs(x));
}
int n,m;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++) v(i)=read(),f(i)=i;
	dist(0)=-1;
	for(int i=1,op,x,y;i<=m;i++)
	{
		op=read();
		if(op==1)
		{
			x=read();
			y=read();
			if(v(x)==-1||v(y)==-1) continue;
			x=getf(x);
			y=getf(y);
			if(x!=y) f(x)=f(y)=merge(x,y);
		}
		else
		{
			x=read();
			if(v(x)==-1) write(-1);
			else x=getf(x),write(v(x)),pop(x);
		}
	}
	return 0;
}


