#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf = 0x3f3f3f;
int n,m;
bool vis[182][182];
int p[182][182];
int move[4][2]={
		1,0,
		0,1,
		0,-1,
		-1,0,
};
int search(int,int);
int mf(int x,int y)
{
	int minans=inf,ans=0;
	for(int i=0;i<4;i++){
		ans=search(x+move[i][0],y+move[i][1]);
		if(ans==-1) continue;
		minans=min(min(minans,ans),p[x][y]);
	}
	return p[x][y]=minans;
}
int search(int x,int y)
{
	if(vis[x][y]) 
		return -1;
	vis[x][y]=1;
	if(x==0||y==0||x==n+1||y==m+1) 
		return -1;
	if(p[x][y]==-1)
		return 0;
	if(p[x][y]<=inf/2) 
		return p[x][y]+1;
	int minans=mf(x,y);
	vis[x][y]=0;
	return minans+1;
}
int main()
{
	cin>>n>>m;
	char t;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		t=getchar();
		if(t==' '||t=='\n') 
		{
			j--;
			continue;
		}
		if(t=='1') p[i][j]=-1;
		else p[i][j]=inf;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			memset(vis,0,sizeof(vis));
			search(i,j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			cout<<p[i][j]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
