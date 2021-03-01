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
	if(!x)
	{
		putchar('0');
		return;
	}
	int g=0;
	do{G[++g]=x&1;x/=2;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define N 10010
#define M 100010
int n,m,q;
struct G
{
	int cnt;
	int from[M],head[N],ver[M],nxt[M];
	void insert(int x,int y)
	{
		nxt[++cnt]=head[x];
		head[x]=cnt;
		ver[cnt]=y;
		from[cnt]=x;
	}
}ga,gb;
int stac[N],top;
int dfn[N],dfncnt,low[N],col[N],colcnt;
void tarjan(int x,int f)
{
	stac[++top]=x;
	dfn[x]=low[x]=++dfncnt;
	for(int i=ga.head[x];i;i=ga.nxt[i])
	{
		if(ga.ver[i]==f) continue;
		if(!dfn[ga.ver[i]])
		{
			tarjan(ga.ver[i],x);
			low[x]=min(low[x],low[ga.ver[i]]);
		}
		else if(!col[ga.ver[i]])
		{
			low[x]=min(low[x],dfn[ga.ver[i]]);
		}
	}
	if(dfn[x]==low[x])
	{
		colcnt++;
		col[x]=colcnt;
		while(stac[top]!=x)
		{
			col[stac[top]]=colcnt;
			top--;
		}
		top--;
	}
}
int sze[N],son[N],dep[N],f[N];
void dfs1(int x,int fa)
{
	sze[x]=1;
	f[x]=fa;
	dep[x]=dep[fa]+1;
	for(int i=gb.head[x];i;i=gb.nxt[i])
	{
		if(gb.ver[i]==f[x]) continue;
		dfs1(gb.ver[i],x);
		if(sze[son[x]]<sze[gb.ver[i]])
		{
			son[x]=gb.ver[i];
		}
	}
}
int tp[N];
void dfs2(int x,int t)
{
	tp[x]=t;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=gb.head[x];i;i=gb.nxt[i])
	{
		if(gb.ver[i]==f[x]||gb.ver[i]==son[x]) continue;
		dfs2(gb.ver[i],gb.ver[i]);
	}
}
int LCA(int x,int y)
{
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]]) x^=y^=x^=y;
		x=f[tp[x]];
	}
	if(dep[x]>dep[y]) x^=y^=x^=y;
	return x;
}
int main()
{
	n=read();
	m=read();
	for(int i=1,a,b;i<=m;i++)
	{
		a=read();
		b=read();
		ga.insert(a,b);
		ga.insert(b,a);
	}
	tarjan(1,0);
	for(int x=1;x<=n;x++)
	{
		for(int i=ga.head[x];i;i=ga.nxt[i])
		{
			if(col[x]!=col[ga.ver[i]])
			{
				gb.insert(col[x],col[ga.ver[i]]);
			}
		}
	}
	//another add_edge way
	/*
	for(int i=1;i<=ga.cnt;i++)
	{
		if(col[ga.from[i]]!=col[ga.ver[i]])
		{
			gb.insert(col[ga.from[i]],col[ga.ver[i]]);
		}
	}
	*/
	dfs1(1,0);
	dfs2(1,1);
	q=read();
	for(int i=1,x,y;i<=q;i++)
	{
		x=read();
		y=read();
		x=col[x];
		y=col[y];
		write(dep[x]+dep[y]-2*dep[LCA(x,y)]+1);
	}
	return 0;
}


