//problem�� 
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
//	��һ�в���д��д�˷�����ʹÿ��������������� 
	double mid=(l+r)/2.0,value=dr(mid);
	if(value+jd>=0&&value-jd<=0){printf("%.2lf ",mid); return 1;}
//	return valid(l,mid);
//	return valid(mid,r);
//	���ﲻ������д�������ֱ�ӷ��أ�ʣ�µ���һ��Ͳ����㵽 
	return valid(l,mid)||valid(mid,r);
//	return 0;
//	������������£��Ͳ���Ҫ�ٷ���0�� 
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
