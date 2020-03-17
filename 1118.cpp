#include<iostream>
#include<cstring>
using namespace std;

bool succ;

int n,k;

int ans[15];

bool vis[15];

int sjx[13][13];

void yh(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++){
		sjx[i][j]=sjx[i-1][j]+sjx[i-1][j-1];if(j==1||j==i) sjx[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) cout<<sjx[i][j]<<" ";
		cout<<endl;
	}
}

int count(){
	int sum=0;
	for(int i=1;i<=n;i++) sum+=ans[i]*sjx[n][i];
	return sum;
}

void dfs(int now,int depth){
	
	if(succ||count()>k) return;
	cout<<count()<<endl; for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
	if(depth>n){
			if(depth>n&&count()==k){
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			succ=1;
			}
	return;
	}
	for(int i=1;i<=n;i++)
	if(!vis[i]){
		ans[depth+1]=i;
		vis[i]=1;
		dfs(i,depth+1);
		vis[i]=0;
		ans[depth+1]=0;
	}
	
	ans[now]=0;
}

int main(){
	cin>>n>>k;
	yh();
	for(int i=1;i<=n;i++)
	vis[i]=1,ans[1]=i,dfs(i,1),memset(vis,0,sizeof(vis)),memset(ans,0,sizeof(ans));
	return 0;
}
