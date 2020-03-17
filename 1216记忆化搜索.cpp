//记忆化搜索 
#include<iostream>
#include<cstring>
using namespace std;
int f[1000][1000],a[1000][1000]; 
int r;
int dfs(int x,int y)
{
	if(f[x][y]==-1)//-1为边界 
	{
		if(x==r)
			f[x][y]=a[x][y];
	}
	else
		f[x][y]=max(dfs(x+1,y),dfs(x+1,y+1));
	return f[x][y];	
}
int main(){
	cin>>r;
	memset(f,0,sizeof(f));
	for(int i=0;i<r;i++)//行 
	for(int j=0;j<i+1;j++)//列 
	{
		cin>>a[i][j];
		if(i>=r)
			f[i][j]=-1; 
	} 
	cout<<dfs(0,0);
	
	return 0;
}
