#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
#include<cstring>
#define IL inline
using namespace std;
IL void fin(){freopen("test2525.in","r",stdin);}
IL void fout(){freopen("2525unSTL.out","w",stdout);}
IL void fio()
{
	fin();
	fout();
}
bool cmp(int a,int b){return a>b;}
int n;
int arr[10];
int main()
{
	fio();
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=n-1;i>0;i--) 
	if(arr[i]>arr[i-1]) swap(arr[i],arr[i-1]);
	else
	{
		sort(arr+i+1,arr+n,cmp);
		break;
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
