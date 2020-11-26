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
#define ULL unsigned long long
#define re register
using namespace std;
const int le='A',ri='z';
int cnt,kind,n,s=100;
bool ver[1000][1000];
int degree[1000];
void insert(int u,int v)
{
	ver[u][v]=ver[v][u]=1;
	degree[u]++;
	degree[v]++;
}
bool book[1000][1000];
bool succ;
vector<int>vec;
void dfs(int depth,int now)
{
	if(succ) return; 
	if(depth==n){
		succ=1;
		for(int i=0;i<vec.size();i++) cout<<(char)(vec[i]+le);
		return;
	}
	for(int i=0;i<58;i++)
	{
		if(ver[now][i])
		if(!book[now][i]&&!book[i][now])
		{
			book[now][i]=1;
			book[i][now]=1;
			vec.push_back(i);
			dfs(depth+1,i);
			book[now][i]=0;
			book[i][now]=0;
			vec.pop_back();
		}
	}
}
int main()
{
//	freopen("P1341_2.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	int start=0;
	string t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		insert(t[1]-'A',t[0]-'A');
		s=min(s,t[0]-'A');
		s=min(s,t[1]-'A');
	}
	int sum=0;
	for(int i=0;i<58;i++) if(degree[i]&1) {
		if(!sum) start=i;
		sum++;
	}
	if(sum!=0&&sum!=2) return cout<<"No Solution"&&0;
	if(!sum) start=s;
	vec.push_back(start);
	dfs(0,start);
	return 0;
}

