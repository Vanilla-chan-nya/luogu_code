#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#define IL inline
using namespace std;

int n,f,x,y,t;
IL void prime_factor(int num)
{
	int i=1;
	bool flag=0;
	while(i++,num>1)
	{
		while(num%i==0)
		{
			num/=i;
			if(flag) cout<<"*";
			else cout<<"=";
			flag=1;
			cout<<i;
		}
	}
}
int main()
{
	cin>>n;
	x=1,y=0,t=0;
	for(int i=2;i<=n;i++)
	{
		t=x;
		x+=y;
		y=t;
	}
	cout<<x;
	prime_factor(x);
	return 0;
}


