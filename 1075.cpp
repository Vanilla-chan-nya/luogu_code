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


