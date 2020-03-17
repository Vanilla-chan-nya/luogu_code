//#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<ctime>
#define IL inline
using namespace std;
IL bool zs(int a)
{
	if(a<2) return 0;
	bool flag=0;
	for(int i=2;i<=sqrt(a);i++)
	if(a%i==0) return 0;
	return 1;
}
int n;
int main()
{
	cin>>n;
	for(int i=4;i<=n;i+=2)
	{
		for(int j=2;j<=i/2+1;j++)
		{
			if(zs(j)&&zs(i-j)){
				cout<<i<<"="<<j<<"+"<<i-j<<endl;
				break;
			}
		}
	}
	
	return 0;
}


