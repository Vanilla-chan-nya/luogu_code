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

typedef long long LL;

IL int read()
{
	int ans=0;
	bool fu=0;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') fu=1,ch=getchar();
	while(ch<='9'&&ch>='0') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	if(fu) ans*=-1;
	return ans;
}

LL k,n,sum;



int main()
{
	cin>>n>>k;
	for(LL l=1,r=1;l<=k;l=r+1,r=k/(k/l)-1) sum+=(r-l+1)*k-((l+r)*(r-l+1)/2*(k/l));
	cout<<sum;
	return 0;
}

