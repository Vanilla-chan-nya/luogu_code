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
#define N 300010
#define M 600010
int n;
int head[N],nxt[M],ver[M];
int dis[N];
int cnt;
void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	
	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
}
int dep[N],sze[N],f[N][21];
void dfs1(int x)
{
	dep[x]=dep[f[x][0]]+1;
	sze[x]=1;
	for(int j=1;j<=20;j++) f[x][j]=f[f[x][j-1]][j-1];
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x][0]) continue;
		dfs1(ver[i]);
		sze[x]+=sze[ver[i]];
	}
}
void pre()
{
	dep[1]=1;
	dfs1(1);
	
}
bool book[N];
void dfs1(int x)
{
	
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) insert(a,b);
	pre();
	return 0;
}


