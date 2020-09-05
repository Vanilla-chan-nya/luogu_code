#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#define LL long long
using namespace std;
int a[100][100];
bool succ;
bool xb[100][10],yb[100][10],zb[100][10];
int exist(int x,int y){return x/3*3+y/3;}
void dfs(int x,int y)
{
	if(succ) return;
	if(y==9){
		if(x==8){
			succ=1;
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++) cout<<a[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl;
			return;
		}
		dfs(x+1,0);
		return;
	}
	if(a[x][y]!=0) dfs(x,y+1);
	else for(int i=1;i<=9;i++)
	{
		if(xb[x][i]==0&&yb[y][i]==0&&zb[exist(x,y)][i]==0){
			xb[x][i]=1;
			yb[y][i]=1;
			zb[exist(x,y)][i]=1;
			a[x][y]=i;
			dfs(x,y+1);
			xb[x][i]=0;
			yb[y][i]=0;
			zb[exist(x,y)][i]=0;
			a[x][y]=0;
		}
	}
}
int main()
{
	succ=0;
	memset(a,0,sizeof(a));
	memset(xb,0,sizeof(xb));
	memset(yb,0,sizeof(yb));
	memset(zb,0,sizeof(zb));
	for(int i=0;i<9;i++) 
	for(int j=0;j<9;j++)
	{
		cin>>a[i][j];
		if(a[i][j]) xb[i][a[i][j]]=1,yb[j][a[i][j]]=1,zb[exist(i,j)][a[i][j]]=1;
	}
	dfs(0,0);
	return 0;
}

