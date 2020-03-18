#include<bits/stdc++.h>
using namespace std;
inline unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(b==0) return a;
	if(b==1) return 1;
	if(a%2==0&&b%2==0) return 2*gcd(a/2,b/2);
	if(a%2==1&&b%2==0) return gcd(a,b/2);
	if(a%2==0&&b%2==1) return gcd(a/2,b);
	if(a%2==1&&b%2==1) return gcd(b,a%b);
//	return (b==0)?a:gcd(b,a%b);
}
unsigned long long t,a,b,j,g,l,flag;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>g>>l;
		j=g*l;
		flag=1;
		for(int a=1;a*a<=j;a++)
		{
			if(j%a==0)
			if(gcd(a,j/a)==g){
				cout<<a<<" "<<j/a<<endl;
				flag=0;
				break;
			}
		}
		if(flag) cout<<"-1\n";
	}

	return 0;
}


