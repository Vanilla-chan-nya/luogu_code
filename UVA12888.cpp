//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define IL inline
using namespace std;
inline unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(a==1) return 1;
	if(b==0) return a;
	if(b==1) return 1;
	if(a%2==0&&b%2==0) return 2*gcd(a/2,b/2);
	if(a%2==1&&b%2==0) return gcd(a,b/2);
	if(a%2==0&&b%2==1) return gcd(a/2,b);
	if(a%2==1&&b%2==1) return gcd(b,a%b);
//	return (b==0)?a:gcd(b,a%b);
}
int n,m,t;
int main()
{
	freopen("UVA12888table.txt","w",stdout);
//	cin>>t;
//	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<(gcd(i,j)==1);
			} 
			cout<<endl;
		}
		
	}
	return 0;
}


