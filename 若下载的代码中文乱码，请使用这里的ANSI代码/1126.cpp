#include<iostream>
using namespace std;
long long b,p,k,ans;
int main()
{
	cin>>b>>p>>k;
	cout<<b<<"^"<<p<<" mod "<<k<<"=";
	ans=1;
	while(p>0)
	{
		if(p&1)
			ans*=b;
		p>>=1;
		b*=b;
		b%=k;
		ans%=k;
	}
	cout<<ans%k;
	return 0;
}
