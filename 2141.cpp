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

int a[101];
bool b[20005];

int main()
{
	int n,t=0;cin>>n;
	for(int i=0;i<n;i++) cin>>a[i],b[a[i]]=1;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
		if(b[a[i]+a[j]]) t++,b[a[i]+a[j]]=0;
	cout<<t;
	return 0;
}

