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
using namespace std;

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

int gcd(int a,int b)
{
	for(;b!=0;swap(a,b),b%=a);
	return a;
}

int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}

int a0,a1,b0,b1,ans;

int main()
{
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>a0>>a1>>b0>>b1;
		for(int i=1;i<=b1;i++)
		{
			if(gcd(a0,i)==a1&&lcm(i,b0)==b1) ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}


