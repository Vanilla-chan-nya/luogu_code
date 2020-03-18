#include<iostream>
#include<cstdio>
#include<cmath>
#define IL inline
#define re register
using namespace std;
const double eps=1e-12;
double a;
IL double f(double x)
{
	return pow(x,a/x-x);
}
IL double simpson(double l,double r)
{
	return (r-l)*(f(l)+4.0*f((l+r)/2.0)+f(r))/6.0;
}
double integral(double l,double r)
{
	re double mid=(l+r)/2,ans=simpson(l,r);
	if(fabs(ans-simpson(l,mid)-simpson(mid,r))<eps) return (ans+simpson(l,mid)+simpson(mid,r))/2.0;
	return integral(l,mid)+integral(mid,r);
}
int main()
{
	cin>>a;
	if(a<0) cout<<"orz";
	else printf("%.5lf",integral(eps,15));
	return 0;
}

