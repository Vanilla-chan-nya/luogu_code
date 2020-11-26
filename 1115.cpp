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
int n;
int a[200010],m[200010];
int main()
{
	cin>>n;
	int ans=-100000;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		a[i]=max(a[i],a[i-1]+a[i]); 
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]);
	}
	cout<<ans; 
	return 0;
}
