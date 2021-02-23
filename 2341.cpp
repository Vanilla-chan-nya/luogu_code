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
int low[100010],dfn[100010],col[100010],colcnt,colsze[100010];
int dfncnt;
int stac[100010],top;
int head[100010],nxt[500010],ver[500010];
int from[100010];
int cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	from[cnt]=x;
	head[x]=cnt;
	ver[cnt]=y;
}
void tarjan(int x)
{
	low[x]=dfn[x]=++dfncnt;
	stac[++top]=x;
	for(int i=head[x],v;i;i=nxt[i])
	{
		v=ver[i];
		if(!dfn[v]) tarjan(v),low[x]=min(low[x],low[v]);
		else if(!col[v])
		{
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x])
	{
		colcnt++;
		while(stac[top]!=x) col[stac[top]]=colcnt,colsze[colcnt]++,top--;
		col[stac[top]]=colcnt;
		colsze[colcnt]++;
		top--;
	}
}
int out[1000010];
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
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=nxt[i])
		{
			if(col[x]!=col[ver[i]])
			{
				out[col[x]]++;
			}
		}
	}
	int tmp=0,ans=0;
	for (int i=1;i<=colcnt;i++)
	if (!out[i])
		ans=colsze[i],tmp++;
	if (tmp==1) printf("%d\n",ans);
	else printf("0\n"); 
	return 0;
}

