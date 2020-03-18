#include<iostream>
#include<cmath>
using namespace std;
bool n[20];
string huyue(int number)
{
	
	for(int i=18;i>=0;i--)
	if(pow(2,i)<=number){
		n[i]=1;
		number-=pow(2,i);
		cout<<"("<<huyue(i);
	}
	cout<<")";
}
int main(){
	int num;
	cin>>num;
	/*for(int i=18;i>=0;i--)
		cout<<n[i];*/
	huyue(num);
	return 0;
} 
