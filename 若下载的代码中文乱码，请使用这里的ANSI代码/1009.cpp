#include<iostream>
using namespace std;
int n;
const int maxn=10001;
int t[maxn],s[maxn];
int main()
{
	cin>>n;
	t[0]=1;
	for(int i=1;i<=n;i++)
	{
		//times
		for(int j=0;j<maxn;j++)
		{
			t[j]*=i;
			
		}
		for(int j=0;j<maxn;j++)
		{
			t[j+1]+=t[j]/10;
			t[j]%=10;	
			s[j]+=t[j];
			s[j+1]+=s[j]/10;
			s[j]%=10; 	
		}
	}
	bool flag=0;	
	for(int i=maxn-1;i>=0;i--)
	{
		if(s[i]) flag=1;
		if(flag) cout<<s[i];
	}
	return 0;
}
