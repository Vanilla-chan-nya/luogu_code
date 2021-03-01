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
int n,k;
LL ans;
int head[200010],nxt[200010],ver[200010],w[200010];
int ecnt;
void insert(int x,int y,int z)
{
	nxt[++ecnt]=head[x];
	head[x]=ecnt;
	ver[ecnt]=y;
	w[ecnt]=z;
	
	nxt[++ecnt]=head[y];
	head[y]=ecnt;
	ver[ecnt]=x;
	w[ecnt]=z;
}
bool book[100010];
int sze[100010];
int sum,rt,son[100010];
void weight(int x,int fa) {
	size[x]=1;
	son[x]=0;
	for(int i=head[x];i;i=nxt[i]) {
		int v=ver[i];
		if(v==fa||book[v]) continue;
		weight(v,x);
		sze[x]+=sze[v];
		if(sze[v]>son[x]) son[x]=sze[v];
	}
	if(sum-sze[x]>sze[son[x]]) son[x]=sum-sze[x];
	if(son[x]<son[rt]) rt=x;
}
void gets(int x,int fa)
{
	dis[++tot]=diss[x];
	for(int i=head[x];i;i=nxt[i])
	{
		int v=ver[i];
		if(vis[v]||v==fa) continue;
		diss[v]=diss[x]+w[i];
		gets(v,x);
	}
}
void calc(int x)
{
	int p=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=ver[i];
		if(book[v]) continue;
		tot=0;diss[v]=w[i];
		gets(v,x);
		
	}
}
int main()
{
//	freopen("P4178_1.in","r",stdin);
	cin>>n;
	for(int i=1,a,b,c;i<n;i++)
	{
		cin>>a>>b>>c;
		insert(a,b,c);
	}
	cin>>k;
	sum=n;
	weight(1,0);
	solve(rt);
	cout<<ans;
	return 0;
}


