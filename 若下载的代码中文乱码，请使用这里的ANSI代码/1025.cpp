#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int use[10000];
void dfs(int depth,int sum,int prev)
{
	if(depth>=k||sum>=n){
		if(sum==n&&depth==k)ans++;
		return;
	}
	for(int i=prev;sum+i<=n;i++)
	{
			use[depth+1]=i;
			dfs(depth+1,sum+i,i);
			use[depth+1]=0;
	}
}
int main()
{
	cin>>n>>k;
	dfs(0,0,1);
	cout<<ans;
}
