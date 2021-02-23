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
int n,m,r,mod;
#define N 100010
int sze[N],dep[N],f[N];
int head[N],nxt[N*2],ver[N*2],cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	
	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
}
int dfn[N],dfncnt,son[N],top[N],rev[N];
int w[N];
void dfs1(int x,int fa)
{
	f[x]=fa;
	sze[x]=1;
	dep[x]=dep[f[x]]+1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x]) continue;
		dfs1(ver[i],x);
		sze[x]+=sze[ver[i]];
		if(sze[ver[i]]>sze[son[x]]) son[x]=ver[i];
	}
}
/*
extra-calc son of root in dfs2
*/
void dfs2(int x)
{
	dfn[x]=++dfncnt;
	rev[dfncnt]=x;
	if(son[x]) top[son[x]]=top[x],dfs2(son[x]);
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x]||ver[i]==son[x]) continue;// == if(!top[ver[i]]) continue;
		top[ver[i]]=ver[i];
		dfs2(ver[i]);
	}
}
struct node
{
	int l,r,v;
	int lazy;
	IL int size()
	{
		return r-1+1;
	}
	#define l(p) b[p].l
	#define r(p) b[p].r
	#define v(p) b[p].v
	#define lazy(p) b[p].lazy
	#define size(p) b[p].size()
}b[4*N];
void spread(int p)
{
	if(lazy(p))
	{
		v(p<<1)+=lazy(p)*size(p<<1);
		v(p<<1|1)+=lazy(p)*size(p<<1|1);
		lazy(p<<1)+=lazy(p);
		lazy(p<<1|1)+=lazy(p);
		lazy(p)=0;
	}
}
void upd(int p)
{
	spread(p);
	v(p)=v(p<<1)+v(p<<1|1);
	v(p)%=mod;
}
void build(int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if(l==r)
	{
		v(p)=w[rev[l]];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
void add(int p,int l,int r,int w)
{
	if(l<=l(p)&&r(p)<=r)
	{
		v(p)+=w*size(p);
		lazy(p)+=w;
		return;
	}
	int mid=l(p)+r(p)>>1;
	if(l<=mid) add(p<<1,l,r,w);
	if(r>mid) add(p<<1|1,l,r,w);
}
int sum(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return v(p);
	}
	spread(p);
	int mid=l(p)+r(p)>>1,ans=0;
	if(l<=mid) ans+=sum(p<<1,l,r);
	if(r>mid) ans+=sum(p<<1|1,l,r);
	return ans;
}
int ask1(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans+=sum(1,dfn[top[x]],dfn[x]);
		ans%=mod;
		x=f[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	ans+=sum(1,dfn[y],dfn[x]);
	return ans;
}
void add1(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		add(1,dfn[top[x]],dfn[x],z);
		x=f[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	add(1,dfn[y],dfn[x],z);
}
int ask2(int x)
{
	return sum(1,dfn[x],dfn[x]+sze[x]-1);
}
void add2(int x,int z)
{
	add(1,dfn[x],dfn[x]+sze[x]-1,z);
}
int main()
{
	n=read();
	m=read();
	r=read();
	mod=read();
	for(int i=1;i<=n;i++)
	{
		w[i]=read();
	}
	for(int i=1,a,b;i<n;i++)
	{
		a=read();
		b=read();
		insert(a,b);
	}
	dfs1(1,0);
	dfs2(1);
	build(1,1,n);
	for(int i=1,op,x,y,z;i<=m;i++)
	{
		op=read();
		x=read();
		if(op==1)
		{
			y=read();
			z=read();
			add1(x,y,z);
		}
		else if(op==2)
		{
			y=read();
			write(ask1(x,y));
		}
		else if(op==3)
		{
			z=read();
			add2(x,z);
		}
		else
		{
			write(ask2(x));
		}
	}
	return 0;
}

