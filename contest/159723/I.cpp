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


LL dp[10][200];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				for(int q=0;q<=9;q++)
				{
					dp[i+1][j+q]+=dp[i][j];
				}
			}
		}
		LL ans=0;
		for(int q=1;q<=9;q++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j+q<=k;j++)
				{
					ans+=dp[i][j];
				}
			}
		}
		cout<<ans<<endl;
		
		
	}
	return 0;
}
