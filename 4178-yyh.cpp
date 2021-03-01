#include<bitsdc++.h>
using namespace std;
struct node{
    int to,w,nxt;
}e[600010];
int query[300010],q[300010],cnt,n,m,sum,size[300010],tot,h[300010],son[300010],rt,ans[30000010],dis[300010],diss[300010],test[300010];
bool vis[300010];
void add(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].nxt=h[u];
    e[cnt].w=w;
    h[u]=cnt;
}
void weight(int x,int fa)
{
    size[x]=1;son[x]=0;
    for (int i=h[x];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||vis[v]) continue;
        weight(v,x);
        size[x]+=size[v];
        son[x]=max(son[x],size[v]);
    }
    son[x]=max(son[x],sum-size[x]);
    if(son[x]<son[rt])rt=x;
}
void gets(int x,int fa)
{
    dis[++tot]=diss[x];
    for(int i=h[x];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[v]||v==fa)continue;
        diss[v]=diss[x]+e[i].w;
        gets(v,x);
    }
}
void calc(int x)
{   
	int p=0;
	for(int i=h[x];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(vis[v]) continue;
		tot=0,diss[v]=e[i].w;
		gets(v,x);
		for(int j=tot;j>=1;j--)
		for(int k=1;k<=m;k++)
			if(query[k]>=dis[j]) test[k]|=ans[query[k]-dis[j]];
		for(int j=tot;j>=1;j--)q[++p]=dis[j],ans[dis[j]]=1;
	}
	for(int i=1;i<=p;i++) ans[q[i]]=0;
}
void solve(int x)
{
	vis[x]=ans[0]=1;calc(x);
	for(int i=h[x];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(vis[v]) continue;
		sum=size[v];
		son[rt=0]=INT_MAX;
		weight(v,0),solve(rt);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
    for (int i=1,u,v,w;i<n;i++)
    {
    	scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=m;i++)
    scanf("%d",&query[i]);
    sum=son[0]=n;
    weight(1,0);
    solve(rt);
    for(int i=1;i<=m;i++)
    if(test[i])printf("AYE\n");
   	else printf("NAY\n");
    return 0;
}
