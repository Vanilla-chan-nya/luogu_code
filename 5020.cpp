/*
1.sort
2.�Ӵ�Сö�� �ж����Ƿ�����һЩ���ı��� 
3.ͬ�� �ж����Ƿ�����һЩ���ĺ� 
4.3������С�����ɻ��е��㷨 
5.�����Ǵ����뷨(WA15) 
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
