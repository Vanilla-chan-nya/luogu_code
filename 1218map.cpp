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
map<int,bool>table,vis;
IL bool prime(int num)
{
	if(num<=1) return 0;
	if(vis[num]) return table[num];
	vis[num]=1;
	for(int i=2;i<=sqrt(num);i++)
	if(num%i==0) return table[num]=0;
	return table[num]=1;
}
int main()
{
	cin>>n;
	for(int i=pow(10,n-1);i<pow(10,n);i++)
	{
		flag=1;
		for(int j=i;j>0;j/=10)
		if(!prime(j)){
			flag=0;
			break;
		}
		if(flag) cout<<i<<endl;
	}
	return 0;
}


