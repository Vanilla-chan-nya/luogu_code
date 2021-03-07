/**************************************************************
 * Problem: 3391(FHQ-Treap)
 * Author: Vanilla_chan
 * Date: 20210305
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
#define N 100010
struct Treap
{
	int ls[N],rs[N],val[N],k[N],sze[N];
	bool flag[N];
	int root,cnt;
	int node(int x)
	{
		val[++cnt]=x;
		sze[cnt]=1;
		k[cnt]=rand();
		return cnt;
	}
	void spread(int p)
	{
		if(flag[p])
		{
			swap(ls[p],rs[p]);
			if(ls[p]) flag[ls[p]]^=1;
			if(rs[p]) flag[rs[p]]^=1;
			flag[p]=0;
		}
		
	}
	void upd(int x)
	{
		sze[x]=sze[ls[x]]+sze[rs[x]]+1;
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x^y;
		if(k[x]<k[y])
		{
			spread(x);
			rs[x]=merge(rs[x],y);
			upd(x);
			return x;
		}
		else
		{
			spread(y);
			ls[y]=merge(x,ls[y]);
			upd(y);
			return y;
		}
	}
	void split(int i,int k,int& x,int& y)
	{
		if(!i)
		{
			x=y=0;
			return;
		}
		spread(i);
		if(sze[ls[i]]<k)
		{
			x=i;
			split(rs[i],k-sze[ls[i]]-1,rs[i],y);
		}
		else
		{
			y=i;
			split(ls[i],k,x,ls[i]);
		}
		upd(i);
	}
	void out(int x)
	{
		spread(x);
		if(ls[x]) out(ls[x]);
		cout<<val[x]<<" ";
		if(rs[x]) out(rs[x]);
	}
}tree;
int n,m;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		tree.root=tree.merge(tree.root,tree.node(i));
	}
	for(int i=1,l,r,a,b,c;i<=m;i++)
	{
		l=read();
		r=read();
		tree.split(tree.root,l-1,a,b);
		tree.split(b,r-l+1,b,c);
		tree.flag[b]^=1;
		tree.root=tree.merge(a,tree.merge(b,c));
	}
	tree.out(tree.root);
	return 0;
}


