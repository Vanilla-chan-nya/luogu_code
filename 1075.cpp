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
int main()
{
	cin>>n;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0){
		cout<<n/i;
		break;
	}
	return 0;
}


