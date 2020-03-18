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
using namespace std;

IL int read()
{
    re int res=0;
    re char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
    return res;
}
struct edge{
	int x;
	int y;
	int nex;
}node[2000001];
queue<int>v;
int dist[1000001];
int way[1000001];
bool in[1000001];
int head[1000001];
int cnt;
int n,m;
IL void spfa()
{
	int now=1;
	v.push(1);
	in[now]=1;
	dist[1]=0;
	way[1]=1;
	while(!v.empty())
	{
		now=v.front();
		v.pop();
		in[now]=0;
		for(re int i=head[now];i;i=node[i].nex)
		{
			if(dist[node[i].y]>=dist[node[i].x]+1)
			{
				if(dist[node[i].y]==dist[node[i].x]+1) {
					way[node[i].y]+=way[node[i].x];
				}
				else way[node[i].y]=way[node[i].x];
				dist[node[i].y]=dist[node[i].x]+1;
				if(way[node[i].y]>=100003) way[node[i].y]-=100003;
				if(!in[node[i].y]) v.push(node[i].y),in[node[i].y]=1;
			}
		}
	}
}
IL void add(int a,int b)
{
	cnt++;
	node[cnt].x=a;
	node[cnt].y=b;
	node[cnt].nex=head[a];
	head[a]=cnt;
}
int main()
{
	memset(dist,0x3f,sizeof(dist));
    n=read(),m=read();
    int tx,ty;
    for(int i=1;i<=m;i++)
    {
    	tx=read();
    	ty=read();
    	add(tx,ty);
    	add(ty,tx);
	}
	spfa();
	for(int i=1;i<=n;i++)
		cout<<way[i]<<endl;
    return 0;
}

