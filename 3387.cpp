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
int n,m;
int dis[10010];
int low[10010],dfn[10010],col[10010],colcnt;
int dfncnt;
int stac[10010],top;
struct edge
{
	int x,v;
	edge(int xx=0,int vv=0)
	{
		x=xx,v=vv;
	}
}b[100010];
int bcnt;
struct G
{
	int head[10010],nxt[100010],ver[100010];
	int sum[10010];
	int cnt;
	void insert(int x,int y)
	{
		nxt[++cnt]=head[x];
		head[x]=cnt;
		ver[cnt]=y;
	}
}Ga,Gb;
void tarjan(int x)
{
	low[x]=dfn[x]=++dfncnt;
	stac[++top]=x;
	for(int i=Ga.head[x],v;i;i=Ga.nxt[i])
	{
		v=Ga.ver[i];
		if(!dfn[v]) tarjan(v),low[x]=min(low[x],low[v]);
		else if(!col[v])
		{
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x])
	{
		colcnt++;
		
		while(stac[top]!=x) col[stac[top]]=colcnt,Gb.sum[colcnt]+=Ga.sum[stac[top]],Ga.sum[stac[top]]=0,top--;
		col[stac[top]]=colcnt;
		Gb.sum[colcnt]+=Ga.sum[stac[top]];
		top--;
	}
}
int in[10010];
queue<int>q;
int main()
{
	freopen("P3387_1.in","r",stdin);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) Ga.sum[i]=read();
	for(int i=1,x,y;i<=m;i++)
	{
		x=read();
		y=read();
		b[++bcnt]=edge(x,y);
		Ga.insert(x,y);
	}
	debug
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1,x,v;i<=m;i++)
	{
		x=col[b[i].x],v=col[b[i].v];
		if(x==v) continue;
		Gb.insert(x,v);
		in[v]++;
	}
	debug
	for(int i=1;i<=colcnt;i++)
	{
		dis[i]=Gb.sum[i];
		if(!in[i]) q.push(i);
	}
	int x;
	while(q.size())
	{
		x=q.front();
		q.pop();
		for(int i=Gb.head[x];i;i=Gb.nxt[i])
		{
			in[Gb.ver[i]]--;
			dis[Gb.ver[i]]=max(dis[Gb.ver[i]],dis[x]+Gb.sum[Gb.ver[i]]);
			if(!in[Gb.ver[i]]) q.push(Gb.ver[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=colcnt;i++)
	{
		ans=max(ans,dis[i]);
	}
	write(ans);
	return 0;
}


