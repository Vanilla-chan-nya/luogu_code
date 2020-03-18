#include<iostream>
#include<cstring>
#include<cmath>
#define IL inline
using namespace std;
int n;
bool succ;
int num[26];
bool vis[26];
string str[3];
int let[3][26];
int use[26];
void dfs(int x,int w,bool d)
{
	if(w<0) {
		succ=1;
		for(int i=0;i<n;i++) cout<<num[i]<<" ";
	}
	if(succ) return;
	if(x==2){
		if(vis[let[x][w]]){
			if((num[let[x][0]]+num[let[x][1]]+d)%n==num[let[x][2]]) dfs(0,w-1,(num[let[x][0]]+num[let[x][1]]+d)>=n);
			return;
		}
		num[let[x][2]]=(num[let[x][0]]+num[let[x][1]]+d)%n;
		vis[num[let[x][2]]]=1;
		dfs(0,w-1,(num[let[x][0]]+num[let[x][1]]+d)>=n);
		num[let[x][2]]=0;
		vis[num[let[x][2]]]=0;
	}
	else{
		if(vis[let[x][w]])
			dfs(x+1,w,d);
		else{
			vis[let[x][w]]=1;
			for(int i=0;i<n;i++)
			{
				if(use[i]) continue;
				use[i]=1;
				num[let[x][w]]=i;
				dfs(x+1,w,d);
				use[i]=0;
			}
			vis[let[x][w]]=0;
		}
	}
}



int main()
{
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>str[i];
		for(int j=0;j<n;j++) let[i][j]=str[i][j]-'A';
	}
	dfs(0,n-1,0);
	return 0;
}
