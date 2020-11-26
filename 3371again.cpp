#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<climits>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#define re register
#define debug printf("Now is %d\n",__LINE__);
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar(' ');
}
int n,m,s,dis[10010],cnt;
int head[500010],ver[500010],nxt[500010],w[500010];
bool book[10010];
void insert(int x,int y,int z){nxt[++cnt]=head[x],head[x]=cnt,ver[cnt]=y,w[cnt]=z;}
struct node{int s;};
IL bool operator <(const node & x,const node & y){return dis[x.s]<dis[y.s];}
int main()
{
	n=read(),m=read(),s=read();
	for(int a,b,c;m;m--) a=read(),b=read(),c=read(),insert(a,b,c);
	priority_queue<node>q;
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	dis[s]=0;
	q.push((node){s});
	int x;
	while(!q.empty())
	{
		x=q.top().s,q.pop();
		if(book[x]==1) continue;
		book[x]=1;
		for(int i=head[x],v;i;i=nxt[i])
		{
			v=ver[i];
			if(dis[x]+w[i]<dis[v])
			{
				dis[v]=dis[x]+w[i];
				q.push((node){v});
			}
		}
	}
	for(int i=1;i<=n;i++) write(dis[i]);
	return 0;
}
