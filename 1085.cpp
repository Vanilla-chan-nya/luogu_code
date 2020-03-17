#include<iostream>
using namespace std;
int main(){
	int maxn=0,maxd=0,ta,tb,tc;
	
	for(int i=1;i<=7;i++)
	{
		cin>>ta>>tb;
		tc=ta+tb;
		if(tc>maxn)
		{
			maxn=tc;
			maxd=i;
		}
	}
	cout<<maxd;
	return 0;
}
