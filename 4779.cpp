#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<climits>
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
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m,s,cnt;
int ver[1000010],head[1000010],nxt[1000010],w[1000010];
IL void insert(int u,int v,int wi)
{
	cnt++;
	nxt[cnt]=head[u];
	ver[cnt]=v;
	head[u]=cnt;
	w[cnt]=wi;
}
bool book[1000010];
int dis[1000010];
struct node{
	int p;
};
IL bool operator <(const node &x,const node &y) {
	return dis[x.p]>dis[y.p];
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read(),s=read();
	for(re int i=1;i<=m;i++) dis[i]=INT_MAX;
//	memset(dis,INT_MAX,sizeof(dis));
	for(re int i=0,a,b,c;i<m;i++)
	{
		read(a),read(b),read(c);
		insert(a,b,c);
	}
	priority_queue<node>q;
	q.push((node){s});
	dis[s]=0;
	while(!q.empty())
	{
		re int x=q.top().p;
		q.pop();
		book[x]=0;
		for(re int k=head[x];k;k=nxt[k])
		{
			int v=ver[k];
			if(dis[v]>dis[x]+w[k])
			{
				dis[v]=dis[x]+w[k];
				if(!book[v]) q.push((node){v}),book[v]=1;
			}
		}
	}
	for(re int i=1;i<=n;i++) cout<<dis[i]<<" ";
	return 0;
}

