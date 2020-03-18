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

map<pair<int,int>,bool>table;
//bool table[10001][10001];
int dis[10001];
bool vis[10001];
int n,m;

int dfs(int now,int depth){
	if(depth>=10) return 0;
	vis[now]=1;
	dis[now]=now;
	for(int i=1;i<=n;i++)
	{
		if(table[make_pair(now,i)]){
			dis[now]=max(dfs(i,depth+1),dis[now]);
		}
	}
	return dis[now];
}

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		table[make_pair(a,b)]=1;
	}
	for(int k=1;k<=10;k++)
	for(int s=n;s>0;s--){
		dfs(s,1);
	}
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	return 0;
}

