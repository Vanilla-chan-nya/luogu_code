/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 10010

int n;
vector<int>e[N];
int degree[N];
queue<int>q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		debug
		while(x)
		{
			e[i].push_back(x);
			degree[x]++;
			cin>>x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(degree[i]==0) q.push(i);
	}
	while(q.size())
	{
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		debug
		for(int i=0;i<e[x].size();i++)
		{
			degree[e[x][i]]--;
			//cout<<"now degree "<<e[x][i]<<" ="<<degree[e[x][i]]<<endl;
			if(degree[e[x][i]]==0)
			{
				q.push(e[x][i]);
			}
		}
	}
	
	return 0;
}
