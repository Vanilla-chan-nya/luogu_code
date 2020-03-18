#include<iostream>
#include<cmath>
using namespace std;
long long n,x,l=1,r=2e9,m;
int main()
{
	cin>>n;
	while(l<r)
	{
		m=(l+r)/2;
		if(m*log10(1.0*m)+1<n) l=m+1;
		else r=m;
	}
	cout<<l;
	return 0;
}
