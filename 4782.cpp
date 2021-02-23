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
int n,m;
int head[2000010],ver[4000010],nxt[4000010];
int cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
}
int low[2000010],dfn[2000010],dfncnt;
bool online[2000010];
int stac[2000010],top;
int f[2000010],fcnt;
void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++dfncnt;
	stac[++top]=x;
	online[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!dfn[ver[i]])
		{
			tarjan(ver[i],x);
			low[x]=min(low[x],low[ver[i]]);
		}
		else
		if(!f[ver[i]])
//		if(online[ver[i]]&&ver[i]!=fa)
		{
			low[x]=min(low[x],dfn[ver[i]]);
		}
	}
	if(dfn[x]==low[x])
	{
		f[x]=++fcnt;
		while(stac[top]!=x) f[stac[top--]]=fcnt;
		top--;
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1,a,va,b,vb;i<=m;i++)
	{
		a=read();
		va=read();
		b=read();
		vb=read();
		if(va&&vb) insert(a+n,b),insert(b+n,a);
		if(!va&&vb) insert(a,b),insert(b+n,a+n);
		if(va&&!vb) insert(a+n,b+n),insert(b,a);
		if(!va&&!vb) insert(a,b+n),insert(b,a+n);
	}
	for(int i=1;i<=n+n;i++) if(!dfn[i]) tarjan(i,0);
	for(int i=1;i<=n;i++) if(f[i]==f[i+n])
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	cout<<"POSSIBLE"<<endl;
	for(int i=1;i<=n;i++) cout<<(f[i]<f[i+n])<<" ";
	return 0;
}


