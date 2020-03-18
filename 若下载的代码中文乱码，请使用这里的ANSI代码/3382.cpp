#include<bits/stdc++.h>
using namespace std;
int n;
double eps=1e-5;
double a[20];
double f(double x){
	double ans=0,now=1;
	for(int i=0;i<=n;i++)
		ans+=now*a[i],now*=x;
	return ans;
}
double fuc(double l,double r)
{
	if(l+eps>r) return (l+r)/2; 
	double ml=l+(r-l)/3,mr=r-(r-l)/3;
	if(f(ml)>=f(mr)) return fuc(l,mr);
	return fuc(ml,r);
}
double l,r;
int main()
{
	cin>>n>>l>>r;
	for(int i=n;i>=0;i--) cin>>a[i];
	printf("%.5lf",fuc(l,r));
	return 0;
}
