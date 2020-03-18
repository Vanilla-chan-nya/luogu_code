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

int n,t,last,ans,maxans;

int main()
{
	cin>>n;
	cin>>t;
	for(int i=1;i<n;i++){
		last=t;cin>>t;
		if(t>last) ans++;
		else ans=1; 
		maxans=max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}

