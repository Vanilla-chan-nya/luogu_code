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

IL int read()
{
    re int res=0;
    re char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
    return res;
}
int n;
int f[10][10];
int dp[10][10][10];
int main()
{
	n=read();
	int tx=read(),ty=read(),tz=read();
	while(tx!=0||ty!=0||tz!=0)
	{
		f[tx][ty]=tz;
		cin>>tx;
		cin>>ty;
		cin>>tz;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n&&i+j-k>0;k++)
	{
		int now=0;
		now=max(now,dp[i-1][j][k]+f[i][j]+f[k][i+j-k]);
		now=max(now,dp[i][j-1][k]+f[i][j]+f[k][i+j-k]);
		now=max(now,dp[i-1][j][k-1]+f[i][j]+f[k][i+j-k]);
		now=max(now,dp[i][j-1][k-1]+f[i][j]+f[k][i+j-k]);
		if(i==k) now-=f[k][i+j-k];
		dp[i][j][k]=now;
	}
	cout<<dp[n][n][n];
    return 0;
}

