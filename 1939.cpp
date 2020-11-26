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
map<LL,LL>his;
LL t,n,p=1000000007;
IL LL pow2(LL x)
{
	return x%p*x%p;
}
LL f(LL x)
{
//	cout<<"f x="<<x<<endl;
	if(x<4) return 1;
	if(his.find(x)!=his.end()) return his[x]%=p;
	LL a=f((x>>1)+1),b=f(x>>1),c=f((x>>1)-1);
	if(x&1)
	{
		return his[x]=(pow2(a)+2*b%p*c%p)%p;
	}
	else
	{
		return his[x]=((2*a%p*b%p+p-pow2(b)%p)%p+pow2(c)%p)%p;
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<f(n)<<endl;;
	}
	return 0;
}

