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
int main()
{
	int n;cin>>n;
	int t;
	for(int i=0;i<n;i++){
		cin>>a[i];t=0;
		for(int j=0;j<i;j++) if(a[j]<a[i]) t++;
		cout<<t<<" ";
	}
	
	return 0;
}

