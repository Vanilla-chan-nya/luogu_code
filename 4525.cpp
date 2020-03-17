#include<iostream>
#include<cstdio>
#include<cmath>
#define IL inline
#define re register
using namespace std;
const double eps=1e-12;
double a,b,c,d,L,R;
IL double f(double x)
{
	return (c*x+d)/(a*x+b);
}
IL double simpson(double l,double r)
{
	return (r-l)*(f(l)+4*f((l+r)/2.0)+f(r))/6;
}
double integral(double l,double r)
{
	double mid=(l+r)/2,ans=simpson(l,r);
	if(fabs(ans-simpson(l,mid)-simpson(mid,r))<eps) return (ans+simpson(l,mid)+simpson(mid,r))/2;
	return integral(l,mid)+integral(mid,r);
}
int main()
{
	cin>>a>>b>>c>>d>>L>>R;
	printf("%.6lf",integral(L,R));
	return 0;
}

