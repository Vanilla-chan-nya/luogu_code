/**************************************************************
 * Problem: 3919
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
#define N 1000010
struct Node
{
	int ls,rs;
	int val;
	Node(int ll=0,int rr=0,int vv=0)
	{
		ls=ll;
		rs=rr;
		val=vv;
	}
#define val(x) b[x].val
#define ls(x) b[x].ls
#define rs(x) b[x].rs
}b[N*40];
int a[N];
int root[N],cnt;
int copy(int x)
{
	b[++cnt]=b[x];
	return cnt;
}
void build(int &p,int l,int r)
{
	p=++cnt;
	if(l==r)
	{
		val(p)=a[l];
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void change(int &p,int pre,int l,int r,int x,int v)
{
	p=copy(pre);
	if(l==r)
	{
		val(p)=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
	{
		change(ls(p),ls(pre),l,mid,x,v);
	}
	else
	{
		change(rs(p),rs(pre),mid+1,r,x,v);
	}
}
int ask(int p,int l,int r,int x)
{
	if(l==r)
	{
		return val(p);
	}
	int mid=l+r>>1;
	if(x<=mid) return ask(ls(p),l,mid,x);
	else return ask(rs(p),mid+1,r,x);
}
int n,m;
int ver,op,x,v;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	build(root[0],1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ver,&op,&x);
		if(op==1)
		{
			v=read();
			change(root[i],root[ver],1,n,x,v);
		}
		else
		{
			printf("%d\n",ask(root[ver],1,n,x));
			root[i]=root[ver];
		}
	}
	return 0;
}


