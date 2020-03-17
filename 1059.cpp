#include<iostream>
using namespace std;
int a[1001];
int n,ans;
int main()
{
	cin>>n;
	int t=0;
	for(int i=0;i<n;i++) cin>>t,a[t]++;
	for(int i=1;i<=1000;i++) if(a[i]) ans++;cout<<ans<<endl; 
	for(int i=1;i<=1000;i++) if(a[i]) cout<<i<<" ";
	return 0;
}
