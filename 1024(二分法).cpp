//problem？ 
#include<iostream>
#include<cstdio>
using namespace std; 
const double jd=0.01; 
double a,b,c,d;
bool hj;
double dr(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
bool valid(double l,double r){
	if(l+jd>r) return 0;
	if(dr(l)==0){printf("%.2lf ",l); return 1;}
//	if(dr(r)==0){printf("%.2lf ",r); return 1;}
//	这一行不用写，写了反而会使每个整数解输出两边 
	double mid=(l+r)/2.0,value=dr(mid);
	if(value+jd>=0&&value-jd<=0){printf("%.2lf ",mid); return 1;}
//	return valid(l,mid);
//	return valid(mid,r);
//	这里不能这样写，否则会直接返回，剩下的另一半就不会算到 
	return valid(l,mid)||valid(mid,r);
//	return 0;
//	用了异或的情况下，就不需要再返回0了 
}
int main()
{
	cin>>a>>b>>c>>d;
	for(double i=-100;i<100;i++){
		hj=0;
		valid(i,i+1);
	}
	return 0;	
}
