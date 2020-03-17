#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf = 0x3f3f3f;
int n,m;
int p[182][182];
/*
3 4
0001
0011
0110
*/
int search(int x,int y)
{
	if(p[x][y]==-1) 
		return 0;
	if(p[x][y]<=inf/2)
		return p[x][y];
	int minans=inf,ans=inf;
	for(int i=1; ;i++)
	{
		if(x+i>n&&x-i<=0&&y+i>m&&y-i<=0) 
			break;
		if(p[x+i][y]<=inf/2&&x+i<=n)
			ans=min(p[x+i][y],ans);
		if(p[x-i][y]<=inf/2&&x-i>0)
			ans=min(p[x-i][y],ans);
		if(p[x][y+i]<=inf/2&&y+i<=m)
			ans=min(p[x][y+i],ans);
		if(p[x][y-i]<=inf/2&&y-i>0)
			ans=min(p[x][y-i],ans);
		if(ans<=inf/2)
		{
			minans=ans+i;
			break;
		}
	}
	return minans+1;
}
void extended(int x,int y)
{
	for(int i=1; ;i++)
	{
		if(x+i>n&&x-i<=0&&y+i>m&&y-i<=0) 
			break;
		if(p[x+i][y]<=inf/2&&x+i<=n&&p[x+1][y]!=-1)
			p[x+i][y]=min(i,p[x+i][y]);
		if(p[x-i][y]<=inf/2&&x-i>0&&p[x-1][y]!=-1)
			p[x-i][y]=min(i,p[x-i][y]);
		if(p[x][y+i]<=inf/2&&y+i<=m&&p[x][y+1]!=-1)
			p[x][y+i]=min(i,p[x][y+i]);
		if(p[x][y-i]<=inf/2&&y-i>0&&p[x][y-1]!=-1)
			p[x][y-i]=min(i,p[x][y-i]);
	}
}
int main()
{
	cin>>n>>m;
	char t;
	memset(p,inf,sizeof(p));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		t=getchar();
		if(t==' '||t=='\n') 
		{
			j--;
			continue;
		}
		if(t=='1') {
			p[i][j]=-1;
			extended(i,j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<search(i,j)<<" ";
		cout<<endl;
	}
	return 0;
}
