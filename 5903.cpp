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
#define ui unsigned int
ui s;

inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}
#define N 500010
#define M 1000010
int n,q;
int head[N],ver[M],nxt[M];
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
LL out;
LL ans;
int rt;
int f[N][30],dep[N],top[N],h[N],hson[N];
vector<int>up[N],down[N];
void dfs1(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<30;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==fa) continue;
		dfs1(ver[i],x);
		if(h[x]<h[ver[i]])
		{
			h[x]=h[ver[i]];
			hson[x]=ver[i];
		}
	}
	h[x]++;
}
void dfs2(int x,int ttop)
{
	down[ttop].push_back(x);
	top[x]=ttop;
	if(!hson[x]) return;
	dfs2(hson[x],ttop);
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x][0]||ver[i]==hson[x]) continue;
		up[ver[i]].push_back(ver[i]);
		for(int j=1;j<=h[ver[i]];j++)
		{
			up[ver[i]].push_back(f[up[ver[i]].back()][0]);
		}
		dfs2(ver[i],ver[i]);
	}
}
int main()
{
	cin>>n>>q>>s;
	for(int i=1,a;i<=n;i++)
	{
		a=read();
		if(a) insert(a,i);
		else rt=i;
	}
	dfs1(rt,0);
	up[rt].push_back(rt);
	for(int i=1;i<=h[rt];i++) up[rt].push_back(f[up[rt].back()][0]);
	dfs2(rt,rt);
	for(int i=1,x,k;i<=q;i++)
	{
		x=(get(s)^ans)%n+1;
		k=(get(s)^ans)%dep[x];
		if(k==0)
		{
			ans=x;
			out^=1ll*i*x;
			continue;
		}
		int to_dep=dep[x]-k;
		x=f[x][(int)log2(k)];
		x=top[x];
		int now_dep=dep[x];
		if(now_dep<to_dep)
		{
			x=down[x][to_dep-now_dep];
		}
		else
		{
			x=up[x][now_dep-to_dep];
		}
		ans=x;
		out^=1ll*x*i;
	}
	write(out);
	return 0;
}


