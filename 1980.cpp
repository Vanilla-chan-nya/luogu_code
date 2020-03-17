#include<iostream>
using namespace std;
int k,n;
int main()
{
	register int ans=0;
	cin>>n>>k;
	for(register int i=1,j=1;i<=n;i++,j=i) {
		while(j>0){
		if(j%10==k) ans++;
		j/=10;
		}
	}
	cout<<ans;
	return 0;
}
