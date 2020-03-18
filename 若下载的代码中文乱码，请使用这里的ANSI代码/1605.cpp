#include<iostream>
#include<cstdio>
#define IL inline
#define re register
using namespace std;
int n,m,t,sx,sy,fx,fy,ans;
int vis[6][6];
int map[6][6];
int move[4][2]={
0,1,
1,0,
0,-1,
-1,0
};
IL void dfs(int x,int y)
{
	if(x<=0||y<=0||x>n||y>m||vis[x][y]) return;
	vis[x][y]=1;
	if(x==fx&&y==fy){
		ans++;vis[x][y]=0;return;
	}
	for(int way=0;way<4;way++)
	{
		if(vis[x+move[way][0]][y+move[way][1]]||map[x+move[way][0]][y+move[way][1]]) continue;
		dfs(x+move[way][0],y+move[way][1]);
	}
	vis[x][y]=0;
}
int main()
{
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	int tx,ty;
	for(int i=1;i<=t;i++) cin>>tx>>ty,map[tx][ty]=1;
	dfs(sx,sy);
	cout<<ans;
	return 0;
}



