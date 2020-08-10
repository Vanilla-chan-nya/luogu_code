/*
1.sort
2.从大到小枚举 判断其是否是另一些数的倍数 
3.同上 判断其是否是另一些数的和 
4.3可以用小凯的疑惑中的算法 
5.以上是错误想法(WA15) 
*/
#include<iostream>
#include<algorithm>

bool cmp(int a,int b){return a>b;}
using namespace std;
long long n,t,minc;
long long a[102];
int main()
{
	cin>>t;
	while(t--){
		minc=0x3f3f3f3f;
		cin>>n; for(int i=0;i<n;i++) cin>>a[i]; 
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
	
		}
		cout<<n<<endl;
	}
	return 0;
}
