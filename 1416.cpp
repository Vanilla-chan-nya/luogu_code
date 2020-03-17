#include<iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	if(n==1) cout<<0;
	else cout<<n-2;
	//也可以是这样的
	/*
	cout<<max(n-2,0);
	*/ 
	return 0;
}
