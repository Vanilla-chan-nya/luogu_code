#include<iostream>
#include<algorithm>
#include<cmath>
#define IL inline
#define re register
#define LL long long
using namespace std;

int m,n;
int a[100000],b[100000];
int ans;
int find(int c)
{
	for(int l=0,r=m-1,mid=(l+r)/2;;mid=(l+r)/2)
	{
		if(l>=r) return min(min(abs(a[mid]-c),abs(a[l]-c)),abs(a[r]-c));
		if(mid==c) return 0;
		if(mid>c) r=mid;
		if(mid<c) l=mid+1;
			}
	return 0;
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cin>>b[i];
		ans+=find(b[i]);
		cout<<"Ñ§Éú"<<i<<" "<<find(b[i])<<endl;
	}
	cout<<ans;
	return 0;
}


