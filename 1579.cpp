#include<iostream>//不想OI一场空，千万别用万能头
#include<algorithm>//快排sort()
#include<cstdio>//能不用cin就不用
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#define IL inline
using namespace std;
int n;
IL bool prime(int num)
{
	if(num<=1) return 0;
	for(int i=2;i<=sqrt(num);i++)
	if(num%i==0) return 0;
	return 1;
}
int main()
{
	cin>>n;
	for(int a=2;a<=sqrt(n);a++)
	for(int b=a;b<=sqrt(n);b++)
	if(prime(a)&&prime(b)&&prime(n-a-b))
	{
		cout<<a<<" "<<b<<" "<<n-a-b;
		return 0;
	}
	return 0;
}
