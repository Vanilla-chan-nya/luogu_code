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
int n;
bool flag;
IL bool prime(int num)
{
	if(num<=1) return 0;
	for(int i=2;i<=sqrt(num);i++)
	if(num%i==0) return 0;
	return 1;
}
IL void dfs(int depth,int num)
{
	if(depth==n){
		cout<<num<<endl;
		return;
	}
	num*=10;
	for(int i=0;i<=9;i++)
	if(prime(num+i))
	dfs(depth+1,num+i);
}
int main()
{
	cin>>n;
	dfs(0,0);
	return 0;
}


