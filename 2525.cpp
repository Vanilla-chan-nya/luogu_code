#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
#include<cstring>
#define IL inline
using namespace std;
IL void fin(){freopen("test2525.in","r",stdin);}
IL void fout(){freopen("2525.out","w",stdout);}
IL void fio()
{
	fin();
	fout();
}
int n;
int arr[10];
int main()
{
	fio();
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	prev_permutation(arr,arr+n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}

