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
int head[20010],nxt[200010],ver[20010];
int cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	
	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
}
int n,m;
int dfn[20010],dfncnt;
int low[20010];
bool online[20010];
int stac[20010],top;
int color[20010],col;
void tarjan(int x)
{
	dfn[x]=low[x]=++dfncnt;
	online[x]=1;
	stac[++top]=x;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!dfn[ver[i]])
		{
			tarjan(ver[i]);
			low[x]=min(low[x],low[ver[i]]);
		}
		else if(online[ver[i]])
		{
			low[x]=min(low[x],dfn[ver[i]]);
		}
	}
	if(dfn[x]==low[x])
	{
		col++;
		while(stac[top]!=x) color[stac[top]]=col,online[stac[top]]=0,top--;
		color[stac[top]]=col,online[stac[top]]=0,top--;
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1,a,b;i<=m;i++)
	{
		a=read();
		b=read();
		insert(a,b);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	int ans=0;for(int i=1;i<=n;i++) if(dfn[i]==low[i]) ans++;
	write(ans);
	for(int i=1;i<=n;i++) if(dfn[i]==low[i]) cout<<i<<" ";
	return 0;
}


