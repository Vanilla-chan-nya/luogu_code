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
#define debug
#else
#define debug printf("Now is %d\n",__LINE__);
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
int f[10010];
struct edge
{
	int x,y,z;
	bool operator<(const edge & b)const
	{
		return z>b.z;
	}
};
vector<edge>e;
int getf(int x)
{
	if(f[x]==x) return x;
	return (f[x]=getf(f[x]));
}
void merge(int x,int y)
{
	x=getf(x),y=getf(y);
	f[x]=y;
}
bool ask(int x,int y)
{
	return getf(x)==getf(y);
}
int head[10010],nxt[10010],ver[10010],w[10010];
int cnt;
void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	w[cnt]=z;
	
	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
	w[cnt]=z;
}
int fa[10010][29],dep[10010],mn[10010][29];
//mn:min(if you go up)
void dfs(int x)
{
//	cout<<"now="<<x<<endl;
	debug
	dep[x]=dep[fa[x][0]]+1;
	for(int i=1;i<29;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
		mn[x][i]=min(mn[x][i-1],mn[fa[x][i-1]][i-1]);
	}
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]!=fa[x][0])
		{
			fa[ver[i]][0]=x;
			mn[ver[i]][0]=w[i];
			dfs(ver[i]);
		}
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int ans=100000;
	for(int i=28;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y]) ans=min(ans,mn[x][i]),x=fa[x][i];
	}
//	cout<<"half="<<x<<endl;
	if(x==y) return ans;
	for(int i=28;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i]) ans=min(ans,min(mn[x][i],mn[y][i])),x=fa[x][i],y=fa[y][i];
	}
	ans=min(ans,min(mn[x][0],mn[y][0]));
//	cout<<"LCA="<<fa[x][0]<<endl;
	return ans;
}
int main()
{
	freopen("P1967_13.in","r",stdin);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		e.push_back(edge{read(),read(),read()});
	}
	sort(e.begin(),e.end());
	for(int i=0,cnt1=0,x,y,z;i<m;i++)
	{
		x=e[i].x;
		y=e[i].y;
		z=e[i].z;
		if(!ask(x,y)) merge(x,y),cnt1++,insert(x,y,z);
		if(cnt1==n-1) break;
	}
	debug
	for(int i=1;i<=n;i++) if(f[i]==i) dfs(i);
	int t=read(),a,b;
	while(t--)
	{
		a=read(),b=read();
		if(!ask(a,b)) write(-1);
		else write(LCA(a,b));
	}
	return 0;
}


