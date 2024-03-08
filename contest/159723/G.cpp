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



#define N 1010

int n;
bool ANS[N][N],ming[N][N];

int judge(int x,int y)
{
	int zero=0,fail=0;
	for(int i=1;i<=4;i++)
	{
		if(ming[y][i]==0)
		{
			zero++;
			if(ANS[x][i]) fail=1;
			
		}
		else{
			if(ANS[x][i]==0) return 0;
		}
	}
	if(zero==4) return 0; 
	if(fail) return 3;
	return 6;
	
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=4;j++) cin>>ANS[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=4;j++) cin>>ming[i][j];
		}
		int maxans=0;
		for(int x=0;x<n;x++)
		{
			int ans=0;
			for(int y=1;y<=n;y++)
			{
				ans+=judge((x+y-1)%n+1,y);
				
			}
			cout<<ans<<" ";
		}
//		cout<<maxans;
		
	}
	return 0;
}
