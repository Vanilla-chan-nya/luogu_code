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
IL bool prime(int num)
{
	if(num<=1) return 0;
	for(int i=2;i<=sqrt(num);i++)
	if(num%i==0) return 0;
	return 1;
}
int main()
{
	freopen("bool_prime.out","w",stdout);
	for(int i=0;i<=1000000;i++) cout<<prime(i)<<",";
	return 0;
}


