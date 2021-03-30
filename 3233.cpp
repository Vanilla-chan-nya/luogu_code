/**************************************************************
 * Problem: 3233
 * Author: Vanilla_chan
 * Date: 20210328
 * E-Mail: Vanilla_chan@outlook.com
**************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
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
		for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar(' ');
	}
};
using namespace oi;
#define inf 1000000000
#define N 300010
struct graph
{
	int cnt;
	int head[N],nxt[N<<1],ver[N<<1];
	graph()
	{
		cnt=0;
		memset(head,0,sizeof(head));
	}
	void clear()
	{
		cnt=0;
		//memset(head,0,sizeof(head));
	}
	void insert(int x,int y)
	{
		nxt[++cnt]=head[x];
		head[x]=cnt;
		ver[cnt]=y;

		nxt[++cnt]=head[y];
		head[y]=cnt;
		ver[cnt]=x;
	}
}g1,g2;
int n,m,tot;
int dep[N],f[N][20],dfn[N],sze[N];
void dfs(int x)
{
	dfn[x]=++tot;
	sze[x]=1;
	for(int i=g1.head[x];i;i=g1.nxt[i])
	{
		int v=g1.ver[i];
		if(v==f[x][0]) continue;
		dep[v]=dep[x]+1;
		f[v][0]=x;
		for(int j=1;j<20;j++)
		{
			f[v][j]=f[f[v][j-1]][j-1];
		}
		dfs(v);
		sze[x]+=sze[v];
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) x^=y^=x^=y;
	for(int i=19;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
int top,st[N];
void insert(int x)
{
	if(top==0)
	{
		st[++top]=x;
		return;
	}
	int y=lca(x,st[top]);
	if(y==st[top])
	{
		st[++top]=x;
		return;
	}
	while(top>1&&dep[y]<dep[st[top-1]])
	{
		g2.insert(st[top-1],st[top]);
		top--;
	}
	if(dep[y]<dep[st[top]])
	{
		g2.insert(y,st[top]);
		top--;
	}
	if(!top||st[top]!=y)
	{
		st[++top]=y;
	}
	st[++top]=x;
}
int ans[N],g[N],dp[N];
void calc(int x,int y)
{
	int p=y,q=y;
	for(int i=19;i>=0;i--)
	{
		if(dep[f[p][i]]>dep[x]) p=f[p][i];
	}
	ans[g[x]]-=sze[p];
	for(int i=19;i>=0;i--)
	{
		int l=dep[y]-dep[f[q][i]]+dp[y],r=dep[f[q][i]]-dep[x]+dp[x];
		if(dep[f[q][i]]>dep[x]&&(l<r||(l==r&&g[y]<g[x]))) q=f[q][i];
	}
	ans[g[y]]+=sze[q]-sze[y];
	ans[g[x]]+=sze[p]-sze[q];
}
bool book[N];
void dfs1(int x,int fa)
{
	dp[x]=inf;
	for(int i=g2.head[x];i;i=g2.nxt[i])
	{
		int v=g2.ver[i];
		if(v==fa) continue;
		dfs1(v,x);
		int dis=dep[v]-dep[x];
		if(dp[v]+dis<dp[x]) dp[x]+=dis,g[x]=g[v];
		else if(dp[v]+dis==dp[x]) g[x]=min(g[x],g[v]);
	}
	if(book[x]) dp[x]=0,g[x]=x;
}
void dfs2(int x,int fa)
{
	for(int i=g2.head[x];i;i=g2.nxt[x])
	{
		int v=g2.ver[i];
		if(v==fa) continue;
		int dis=dep[v]-dep[x];
		if(dp[x]+dis<dp[v]) dp[v]=dp[x]+dis,g[v]=g[x];
		else if(dp[x]+dis==dp[v]) g[v]=min(g[v],g[x]);
		calc(x,v);
		dfs2(v,x);
	}
	ans[g[x]]+=sze[g[x]];
	book[x]=0;
	g2.head[x]=0;//clear
}
int tmp[N],gj[N];
int a,b;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)
	{
		a=read();
		b=read();
		g1.insert(a,b);
	}
	dep[1]=1;
	dfs(1);
	int T=read();
	bool flag;
	while(T--)
	{
		flag=1;
		top=0;
		g2.cnt=0;
		g2.clear();
		m=read();
		for(int i=1;i<=m;i++)
		{
			gj[i]=read();
			book[gj[i]]=1;
			ans[gj[i]]=0;
		}
		if(book[1]==0) gj[++m]=1,flag=0;
		for(int i=1;i<=m;i++) tmp[i]=gj[i];
		sort(gj+1,gj+m+1,cmp);
		for(int i=1;i<=m;i++) insert(gj[i]);
		if(top) while(--top) g2.insert(st[top],st[top+1]);
		dfs1(1,0);
		dfs2(1,0);
		for(int i=1;i<=m;i++)
		{
			if(tmp[i]!=1||flag) write(ans[tmp[i]]);
		}
		putchar('\n');
	}
	return 0;
}


