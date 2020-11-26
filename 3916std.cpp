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
#define LL long long
using namespace std;

vector<int>v[100010];
int ans[100010];
int n,m;
void dfs(int x,int k)
{
	if(ans[x]<k){
		ans[x]=k;
		for(int i=0;i<v[x].size();i++)
		{
			dfs(v[x][i],ans[x]);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) ans[i]=i; 
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[b].push_back(a);
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<v[i].size();j++)
		dfs(v[i][j],i);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}


