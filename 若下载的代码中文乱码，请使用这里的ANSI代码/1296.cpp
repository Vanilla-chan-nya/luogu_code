//#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<ctime>
#include<windows.h>
#define IL inline
using namespace std;
int d,ans,n,minp=0x3f3f3f3f,maxp=-1;
int p[100000001];
int main()
{
	freopen("1296.in","r",stdin);
	cin>>n>>d;
	int t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		p[t]++;
		minp=min(minp,t);
		maxp=max(maxp,t);
//		diff[i]=p[i]-p[i-1];
	}
	
	for(int i=minp;i<=maxp;i++)
	{
		if(p[i])
		for(int j=1;j<=d&&i+j<=maxp;j++)
		{
			if(p[i+j]) ans+=p[i]*p[i+j];
		}
		if(p[i]>1) ans+=p[i]*(p[i]-1)/2;
	}
	cout<<ans;
	return 0;
}


