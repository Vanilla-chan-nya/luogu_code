#include<iostream>
#include<cstdio>
#include <iomanip>
using namespace std;
int main(){
	double x,y;
	cin>>x;
	if(x<=150) 
		y=x*0.4463;
	else 
		if(x<=400)
			y=150*0.4463+(x-150)*0.4663;
		else
			y=150*0.4463+250*0.4663+(x-400)*0.5663;
	printf("%.1lf",y);
	return 0;	
}
