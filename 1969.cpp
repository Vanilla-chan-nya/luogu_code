#include<iostream>
using namespace std;
int n,h,l,ans;
int main()
{
	cin>>n>>l;ans=l;
	for(int i=1;i<n;i++)
	{
		cin>>h;
		if(l<h) ans+=h-l;
		l=h;
	}
	cout<<ans;
}
