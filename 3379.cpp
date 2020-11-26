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
using namespace std;

template<class T>inline void read(T&x)

{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
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
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m,s,cnt;
int head[1000010],nxt[1000010],ver[1000010];
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
}
int depth[500010];
int f[500010][21]; 
void dfs(int dep,int now,int last)
{
	depth[now]=dep;
	f[now][0]=last;
	for(int i=1;i<=20;i++) f[now][i]=f[f[now][i-1]][i-1];
	for(int i=head[now];i;i=nxt[i]) if(ver[i]!=last)dfs(dep+1,ver[i],now);
}
void pre()
{
	dfs(1,s,0);
}
int LCA(int a,int b)
{
	//0
	if(depth[a]<depth[b]) swap(a,b);
	//1
	for(int i=20;i>=0;i--)
		if(depth[f[a][i]]>=depth[b]) a=f[a][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--)
	{
		if(f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	}
	return f[a][0];
}
int main()
{
	cin>>n>>m>>s;
	for(int i=1,a,b;i<n;i++)
	{
		cin>>a>>b;
		insert(a,b);
		insert(b,a);
	}
	pre();
	int a,b;
	while(m--)
	{
		cin>>a>>b;
		write(LCA(a,b));
	}
	return 0;
}

