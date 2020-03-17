#include<iostream>
int n[200000];
using namespace std;
int main()
{
	int size,maxsam=-10001,sam;
	cin>>size;
	for(int k=0;k<size;k++)
		cin>>n[k];
	//
	for(int i=0;i<size;i++){ 
		for(int j=i;j<size;j++)
		{
			if(i==j) sam=n[j];
			else sam+=n[j];
			maxsam=max(sam,maxsam);
		} 
		
	}
	cout<<maxsam;
	return 0;
} 
