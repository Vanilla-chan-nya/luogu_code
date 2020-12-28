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

int dep[100010],fa[100010],size[100010],son[100010];
int head[100010],nxt[100010],ver[100010];
int dfn[100010],top[100010];
int w[100010],wt[100010];
int n,cnt1,cnt2;
struct node
{
	int l,r;
	int v;
	#define l(x) b[x].l
	#define r(X) b[x].r
}b[2000100]
void insert(int x,int y)
{
	nxt[++cnt1]=head[x];
	head[x]=cnt1;
	ver[cnt1]=y;
}
void dfs1(int depth,int x,int father)
{
	dep[x]=depth;
	fa[x]=father;
	size[x]=1;
	int maxn=-1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==father) continue;
		dfs1(depth+1,ver[i],x);
		size[x]+=size[ver[i]];
		if(maxn<size[ver[i]]) son[x]=ver[i],maxn=size[ver[i]];
	}
}
void dfs2(int x,int tp)
{
	dfn[x]=++cnt2;
	wt[cnt2]=w[x];
	top[x]=tp;
	if(!son[x]) return;
	dfs2(son[x],tp);
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==fa[x]||ver[i]==son[i]) continue;
		dfs2(ver[i],ver[i]);
	}
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		
		
		return;
	}
}
int n,m,r,p;
int main()
{
	n=read();
	
	
	return 0;
}

