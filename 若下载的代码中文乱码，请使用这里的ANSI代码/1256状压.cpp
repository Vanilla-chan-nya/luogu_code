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
        res=(res<<1)+(ch^48),ch=getchar();
    return res;
}
struct edge{
	int x;
	int y;
}node;
queue<edge>q;
int dt[200];
int move[4][2]={
1,0,
-1,0,
0,1,
0,-1
};
int n,m;
bool vis[200][200];
IL int bfs(int x,int y)
{
	if(dt[x]>>y&1) return 0;
	q.push((edge){x,y});
	vis[x][y]=1;
	edge now;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(dt[now.x]>>now.y&1) return abs(x-now.x)+abs(y-now.y);
		for(int i=0;i<4;i++)
		{
			if(now.x+move[i][0]<0||now.x+move[i][0]>=n||now.y+move[i][1]<0||now.y+move[i][1]>=m||vis[now.x+move[i][0]][now.y+move[i][1]]) continue;
			q.push((edge){now.x+move[i][0],now.y+move[i][1]});
			vis[now.x+move[i][0]][now.y+move[i][1]]=1;
		}
	}
	return -1;
}
int main()
{
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) dt[i]=read();
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			cout<<bfs(i,j)<<" ";
			memset(vis,0,sizeof(vis));
			while(!q.empty()) q.pop();
		}
		cout<<endl;
	}
	return 0;
}




