#include<iostream>//不想OI一场空，千万别用万能头
#include<algorithm>//快排sort()
#include<cstdio>//能不用cin就不用
#include<cstring>
#include<map>
#include<cmath>
#include<vector>
#define IL inline
using namespace std;
int n;
long long cat[3000]={1,1};
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			cat[i]+=cat[i-j-1]*cat[j];
		cat[i]%=100000007;
//		cout<<cat[i]<<endl;
	}
		
	cout<<cat[n];
	return 0;
}

