#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define IL inline
using namespace std;
IL long long gcd(long long a,long long b)
{
	if(!b) return a;
	if(!(a|0)&&!(b|0)) return 2*gcd(a>>1,b>>1);
	if(!(a|0)&&(b&1)) return gcd(a>>1,b);
	if((a&1)&&!(b|0)) return gcd(a,b>>1);
	return gcd(b,a%b);
}
long long x,y,p,q,ans;
int main()
{
	cin>>x>>y;
	if(y%x){cout<<0; return 0;}
	for(p=x;p<=y;p++)
		if(x*y%p==0)
			if(gcd(p,x*y/p)==x)
				ans++;
	cout<<ans;
	return 0;
}


