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
int n;
int x[100],y[100],r[100];
int X1,Y1,X2,Y2;
double dis1(int x,int y)
{
	return sqrt((X1-x)*(X1-x)+(Y1-y)*(Y1-y));
}
double dis2(int x,int y)
{
	return sqrt((X2-x)*(X2-x)+(Y2-y)*(Y2-y));
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
		cin>>y[i];
	for(int i=1;i<=n;i++)
		cin>>r[i];
	cin>>X1>>Y1>>X2>>Y2;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bool now=0;
		now^=dis1(x[i],y[i])<r[i];
		now^=dis2(x[i],y[i])<r[i];
		ans+=now;
	}
	cout<<ans;
	return 0;
}




