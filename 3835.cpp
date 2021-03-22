/**************************************************************
 * Problem: 3835
 * Author: Vanilla_chan
 * Date: 20210312
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
#define N 500010
struct Node
{
	int ls,rs;
	int key,val,sze;
#define ls(x) b[x].ls
#define rs(x) b[x].rs
#define key(x) b[x].key
#define val(x) b[x].val
#define sze(x) b[x].sze
}b[N*100];
int root[N],cnt=1;
int copy(int x)
{
	b[++cnt]=b[x];
	return cnt;
}
void upd(int x)
{
	if(x)
	{
		sze(x)=sze(ls(x))+sze(rs(x))+1;
	}
}
int node(int v)
{
	cnt++;
	ls(cnt)=rs(cnt)=0;
	key(cnt)=rand();
	sze(cnt)=1;
	val(cnt)=v;
	return cnt;
}
void split(int i,int k,int& x,int& y)
{
	if(!i)
	{
		x=y=0;
		return;
	}
	if(val(i)<=k)
	{
		x=copy(i);
		split(rs(x),k,rs(x),y);
	}
	else
	{
		y=copy(i);
		split(ls(y),k,x,ls(y));
	}
	upd(x);
	upd(y);
}
int merge(int x,int y)
{
	if(!x||!y) return x^y;
	int r=0;
	if(key(x)<key(y))
	{
		r=copy(x);
		rs(r)=merge(rs(r),y);
		upd(r);
		return r;
	}
	else
	{
		r=copy(y);
		ls(r)=merge(x,ls(r));
		upd(r);
		return r;
	}
}
void insert(int ver,int v)
{
	int x,y;
	split(root[ver],v,x,y);
	root[ver]=merge(merge(x,node(v)),y);
}
void del(int ver,int v)
{
	int x,y,z;
	split(root[ver],v,y,z);
	split(y,v-1,x,y);
	y=merge(ls(y),rs(y));
	root[ver]=merge(merge(x,y),z);
}
int kth(int x,int k)
{
	while(1)
	{
		if(k<=sze(ls(x))) x=ls(x);
		else if(k==sze(ls(x))+1) return x;
		else k-=sze(ls(x))+1,x=rs(x);
	}
}
int rnk(int ver,int v)
{
	int x,y,ans;
	split(root[ver],v-1,x,y);
	ans=sze(x)+1;
	//root[ver]=merge(x,y);
	return ans;
}
int pre(int ver,int v)
{
	int x,y;
	split(root[ver],v-1,x,y);
	if(!x) return -2147483647;
	while(rs(x)) x=rs(x);
	//root[ver]=merge(x,y);
	return x;
}
int nxt(int ver,int v)
{
	int x,y;
	split(root[ver],v,x,y);
	if(!y) return 2147483647;
	while(ls(y)) y=ls(y);
	//root[ver]=merge(x,y);
	return y;
}
int q,ver,op,x;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	q=read();
	for(int i=1;i<=q;i++)
	{
		ver=read();
		op=read();
		x=read();
		root[i]=root[ver];
		if(op==1)
		{
			insert(i,x);
		}
		else if(op==2)
		{
			del(i,x);
		}
		else if(op==3)
		{
			write(rnk(i,x));
		}
		else if(op==4)
		{
			write(val(kth(root[i],x)));
		}
		else if(op==5)
		{
			write(val(pre(i,x)));
		}
		else if(op==6)
		{
			write(val(nxt(i,x)));
		}
	}
	return 0;
}


