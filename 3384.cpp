/**************************************************************
 * Problem: 3384
 * Author: Vanilla_chan
 * Date: 20210306
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
int n,m,r,mod;
int a[N];
int head[N],ver[N<<1],nxt[N<<1],cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;

	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
}
int f[N],sze[N],son[N],dep[N];
void dfs1(int x)
{
	sze[x]=1;
	dep[x]=dep[f[x]]+1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x]) continue;
		f[ver[i]]=x;
		dfs1(ver[i]);
		sze[x]+=sze[ver[i]];
		if(sze[son[x]]<sze[ver[i]]) son[x]=ver[i];
	}
}
int top[N];
int dfn[N],dfncnt,id[N];
void dfs2(int x,int tt)
{
	dfn[++dfncnt]=x;
	id[x]=dfncnt;
	top[x]=tt;
	if(!son[x]) return;
	dfs2(son[x],tt);
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x]||ver[i]==son[x]) continue;
		dfs2(ver[i],ver[i]);
	}
}
struct node
{
	int l,r,v,lazy;
#define l(x) b[x].l
#define r(x) b[x].r
#define v(x) b[x].v
#define lazy(x) b[x].lazy
}b[N<<2];
IL void upd(int p)
{
	v(p)=v(p<<1)+v(p<<1|1);
	v(p)%=mod;
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		v(p)=a[dfn[l]]%mod;
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
		lazy(p<<1)+=lazy(p);
		lazy(p<<1|1)+=lazy(p);
		v(p<<1)+=lazy(p)*(r(p<<1)-l(p<<1)+1);
		v(p<<1|1)+=lazy(p)*(r(p<<1|1)-l(p<<1|1)+1);
		v(p<<1)%=mod;
		v(p<<1|1)%=mod;
		lazy(p)=0;
	}
}
void add(int p,int l,int r,int k)
{
	//debug cout<<"p="<<p<<" l="<<l(p)<<" r="<<r(p)<<endl;
	if(l<=l(p)&&r(p)<=r)
	{
		lazy(p)+=k;
		lazy(p)%=mod;
		v(p)+=k*(r(p)-l(p)+1);
		v(p)%=mod;
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) add(p<<1,l,r,k);
	if(r>mid) add(p<<1|1,l,r,k);
	upd(p);
}
int ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return v(p);
	}
	spread(p);
	int mid=l(p)+r(p)>>1,ans=0;
	if(l<=mid) ans+=ask(p<<1,l,r);
	if(r>mid) ans+=ask(p<<1|1,l,r);
	return ans%mod;
}
LL ans;
int main()
{
	cin>>n>>m>>r>>mod;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1,a,b;i<n;i++)
	{
		a=read();
		b=read();
		insert(a,b);
	}
	dep[r]=1;
	dfs1(r);
	dfs2(r,r);
	build(1,1,n);
	int op,x,y,z;
	while(m--)
	{
		debug
		op=read();
		x=read();
		if(op==1)
		{
			y=read();
			z=read();

			z%=mod;
			while(top[x]!=top[y])
			{
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				add(1,id[top[x]],id[x],z);
				x=f[top[x]];
			}
			if(dep[x]>dep[y]) swap(x,y);
			add(1,id[x],id[y],z);
		}
		else if(op==2)
		{
			y=read();
			ans=0;
			while(top[x]!=top[y])
			{
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				ans+=ask(1,id[top[x]],id[x]);
				ans%=mod;
				x=f[top[x]];
			}
			if(dep[x]>dep[y]) swap(x,y);
			ans+=ask(1,id[x],id[y]);
			write(ans%mod);
		}
		else if(op==3)
		{
			z=read();
			add(1,id[x],id[x]+sze[x]-1,z);
		}
		else if(op==4)
		{
			write(ask(1,id[x],id[x]+sze[x]-1));
		}
	}
	return 0;
}


