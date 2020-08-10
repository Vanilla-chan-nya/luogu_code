#include<iostream>
using namespace std;
int main(){
	int n,tm[3];
	cin>>n;
	double a[3][2];
	for(int i=0;i<=2;i++)
	{
		cin>>a[i][0]>>a[i][1];
//		tm[i]=a[i][1]*(n/a[i][0]==int(n/a[i][0])?n/a[i][0]:int(n/a[i][0])+1);
		tm[i]=a[i][1]*int(n/a[i][0]+0.9999999999);
//		两种都可以！！！！！ 
	}
	
	
	cout<<min(tm[0],min(tm[1],tm[2]));
	return 0;
}
