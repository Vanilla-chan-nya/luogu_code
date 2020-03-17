#include<iostream>
using namespace std;
int main(){
	int tm=0,ys=0,mun=0;
	
	for(int i=1;i<=12;i++)
	{
		tm+=300;
		cin>>ys;
		if(tm<ys)
		{
			cout<<"-"<<i;
			return 0;
		}
		tm-=ys;
		mun+=tm/100*100;
		tm%=100;		
	}
	cout<<mun*1.2+tm;
	
	
	return 0;
}
