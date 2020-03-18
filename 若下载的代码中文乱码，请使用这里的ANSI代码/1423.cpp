#include<iostream>
using namespace std;

double sum,x;

int main(){
	cin>>x;
	int b=1;
	for(double last=2.0,sum=2.0;sum<=x;last*=0.98,sum+=last,b++) ;
	cout<<b;
	return 0;
}
