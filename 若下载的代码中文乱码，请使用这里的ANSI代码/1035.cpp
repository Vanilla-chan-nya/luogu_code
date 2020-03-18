#include<iostream>
using namespace std;

int k;

double val=0;

int main(){
	cin>>k;
	int i;
	for(i=1;val<=k;i++){
		val+=1.0/i;
	}
	cout<<i-1;
	return 0;
}
