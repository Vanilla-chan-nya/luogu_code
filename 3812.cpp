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
int n,m,ans;
ULL a[600];
ULL p[63];
void insert(ULL x)
{
	for(int i=62;i>=0;i--)
	{
		if((x>>i)&1)
		{
			if(p[i]==0)
			{
				p[i]=x;
				break;
			}
			else
			{
				x^=p[i];
			}
		}
	} 
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		insert(a[i]);
	}
	ULL ans=0;
	for(int i=62;i>=0;i--)
	{
		if((ans^p[i])>ans) ans^=p[i];
	}
	cout<<ans;
	return 0;
}

