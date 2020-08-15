#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
using namespace std;

const string yz="yizhong";

bool book[101][101];
string map[101];
int n;

int delta[8][2]={1,0, 1,1, 0,1, -1,1, -1,0, -1,-1, 0,-1, 1,-1};

void dfs(int a,int b,int depth,int way)
{
	if(a>=n||a<0||b>=n||b<0) return;
	if(map[a][b]!=yz[depth]) return;
	if(depth==6){
		for(int i=0;i<7;i++)
		book[a-i*delta[way][0]][b-i*delta[way][1]]=1;
		return;
	}
	dfs(a+delta[way][0],b+delta[way][1],depth+1,way);
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>map[i];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int t=0;t<8;t++)
	dfs(i,j,0,t);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) if(book[i][j]) cout<<map[i][j]; else cout<<"*";
		cout<<endl;
	}
	
	return 0;
}


