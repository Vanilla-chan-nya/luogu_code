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

vector<int> ver[10001]; 
int dis[10001];
int n,m;

void dfs(int a,int b){
	for(int j=0;j<ver[a].size();j++){
		if(dis[ver[a][j]]<a) dis[ver[a][j]]=a,dfs(ver[a][j],b);
	}
}

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		ver[b].push_back(a);
	}
	for(int i=1;i<=n;i++) dis[i]=i;
	for(int i=n;i>0;i--){
		dfs(i,i);
	}
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	return 0;
}

