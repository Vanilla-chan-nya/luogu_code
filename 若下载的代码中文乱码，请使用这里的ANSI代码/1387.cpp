#include<bits/stdc++.h>
using namespace std;
bool dt[101][101];
int m,n,maxans=1;
int func(int a,int b)
{
	if(!dt[a][b]) return 1;
	if(min(n-a+1,m-b+1)<=maxans) return 1;
	int k;
	for(k=1;k+a<n&&k+b<m;k++)
	{
		bool flag=1;
		for(int i=a;i<a+k;i++)
		for(int j=b;j<b+k;j++)
		{
			if(dt[i][j]==0) flag=0;
			if(flag==0) break;
		}
		if(flag==0) break;
	}
	return k-1;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		cin>>dt[i][j];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		maxans=max(maxans,func(i,j));
	cout<<maxans;
	return 0;
}
