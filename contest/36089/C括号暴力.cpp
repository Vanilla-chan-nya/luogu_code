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
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

int n,k;
string str;
int calc(int l,int r)
{
	int L=0,ans=0;
	for(int i=l;i<=r;i++)
	{
		if(str[i]=='(') L++;
		else L--;
		if(L<0)L++,ans++;
	}
	return ans+L;
}
int rec(int k,int l,int r)
{
	if(k==0) return calc(l,r);
	int ans=0;
	for(int i=l;i<=r;i++)
	for(int j=i;j<=r;j++)
	{
		ans+=rec(k-1,i,j);
	}
	return ans;
}
int main()
{
	cin>>n>>k>>str;
	
	cout<<rec(k,0,n-1);
	return 0;
}

