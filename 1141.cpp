#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define IL inline
#define re register
using namespace std;
IL int read()
{
    re int res=0;
    re char ch=getchar();
    while(ch<'0'||ch>'1')
        ch=getchar();
    res=ch^48;
    return res;
}
int n,m;
int move[4][2]={1,0,-1,0,0,1,0,-1};
bool vis[1000][1000];
int map[1000][1000];
int memory[1000][1000];
IL int dfs(int x,int y,int ans)
{
	if(x<0||x>=n||y<0||y>=n) return 0;
	vis[x][y]=1;
	int maxans=ans;
	for(int i=0;i<4;i++)
	{
		if(vis[x+move[i][0]][y+move[i][1]]||map[x+move[i][0]][y+move[i][1]]==map[x][y]) continue;
		maxans=max(maxans,dfs(x+move[i][0],y+move[i][1],ans+1));
	}
	vis[x][y]=0;
	return memory[x][y]=maxans;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		map[i][j]=read();
	int i,j;
	while(m--)
	{
		cin>>i>>j;
		cout<<dfs(i-1,j-1,1)<<endl;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}




