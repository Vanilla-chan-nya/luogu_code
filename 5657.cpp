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

int main()
{
	ULL n,k;
	cin>>n>>k;
	k=(k/2)^k;
	while(n--) cout<<(k>>n&1);
	return 0;
}

