#include<iostream>
using namespace std;
int n,a[101],sum,avg,ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
	avg=sum/n;
	for(int i=0;i<n;i++) a[i]-=avg; 
	for(int i=0;i<n-1;i++) if(a[i]) a[i+1]+=a[i],a[i]=0,ans++;
	cout<<ans;
	return 0;
}
