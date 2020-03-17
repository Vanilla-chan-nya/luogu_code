#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int xmove[4]={1,0,-1,0};
int ymove[4]={0,1,0,-1};
int map1[105][105];
int m,n,minans=inf;
void dfs(int x,int y,int ans,bool flag)
{
	if(y>m||x>m||x<1||y<1) return;
	if(map1[x][y]==0) return;
	if(ans>minans) return;
	if(x==m&&y==m) 
	{
		if(minans>ans)
			minans=ans;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+xmove[i],ny=y+ymove[i];
		if(map1[nx][ny]==map1[x][y])
			dfs(nx,ny,ans,0);
		else
		{
			if(map1[nx][ny])
				dfs(nx,ny,ans+1,0);
			if(!flag)
			{
				map1[nx][ny]=map1[x][y];
				dfs(nx,ny,ans+2,1);
				map1[nx][ny]=0;
			}
		}
	}
	return;
}
int main()
{
	cin>>m>>n;
	memset(map1,0,sizeof(map1));
	int ta,tb,tc;
	for(int i=0;i<n;i++)
	{
		cin>>ta>>tb>>tc;
		map1[ta][tb]=tc+1;
	}
	dfs(1,1,0,0);
	if(minans==inf) cout<<-1;
	else cout<<minans;
//	cout<<(minans==inf)?-1:minans;
	return 0;
}
