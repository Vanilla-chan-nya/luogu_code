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
int dep[500010];
int head[500010],ver[1000010],nxt[1000010];
int cnt;
int n,m,s;
IL void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	ver[cnt]=y;
	head[x]=cnt;
	
	nxt[++cnt]=head[y];
	ver[cnt]=x;
	head[y]=cnt;
}
int dfn[1000010][20];
int l[500010],r[500010];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	dfn[++cnt][0]=x;
	l[x]=cnt;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]!=fa)
		{
			dfs(ver[i],x);
			dfn[++cnt][0]=x;
		}
	}
	r[x]=cnt;
}
int lg[1000010];
int i,j;
IL void pre()
{
	lg[1]=0;
	for(i=2;i<=cnt;i++) lg[i]=lg[i>>1]+1;
	for(j=1;j<20;j++)
	{
		for(i=1;i+(1<<j)-1<=cnt;i++)
		{
			if(dep[dfn[i][j-1]]<dep[dfn[i+(1<<(j-1))][j-1]]) dfn[i][j]=dfn[i][j-1];
			else dfn[i][j]=dfn[i+(1<<(j-1))][j-1];
		}
	}
}
int lca(int x,int y)
{
	if(l[x]>l[y]) x^=y^=x^=y;
	if(r[x]>=r[y]) return x;
	x=l[x],y=r[y];
	if(dep[dfn[x][lg[y-x+1]]]<dep[dfn[y-(1<<lg[y-x+1])+1][lg[y-x+1]]]) return dfn[x][lg[y-x+1]];
	return dfn[y-(1<<lg[y-x+1])+1][lg[y-x+1]];
}
int main()
{
	n=read();
	m=read();
	s=read();
	for(i=1;i<n;i++) insert(read(),read());
	cnt=0;
	dfs(s,0);
//	for(int i=1;i<=cnt;i++) cout<<dfn[i][0]<<" ";
	pre();
	while(m--)
	{
		write(lca(read(),read()));
	}
	return 0;
}


