#include<iostream>
#include<cstdio>
using namespace std;
double jd=0.005; 
int main()
{
	int j=0;
	double a,b,c,d;cin>>a>>b>>c>>d;
	for(double x=-100;x<=100;x+=0.01){
		if(j==3) break;
		if(a*x*x*x+b*x*x+c*x+d+jd>=0&&a*x*x*x+b*x*x+c*x+d-jd<=0){
			printf("%.2lf ",x);
			x+=0.9;
			j++;
		}
	}
	return 0;	
} 
