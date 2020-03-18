//#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<ctime>
#define IL inline
using namespace std;
int d,ans,n;
int p[1000001],diff[1000000];
int main()
{
	freopen("1296.in","r",stdin);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		scanf("%d",p+i);
		diff[i-1]=p[i]-p[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(diff[i-1]<=d)
		{
			for(int j=1;p[i+j]-p[i]<=d&&i+j<=n;j++)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}


