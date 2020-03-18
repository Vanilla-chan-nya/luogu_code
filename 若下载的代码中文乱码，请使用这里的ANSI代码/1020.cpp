#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
int a[100005];
using namespace std;
int main()
{
	int n=0,i=0,number=1,maxnum;
	while(cin>>n){
        a[i] = n;
        i++;
        if (getchar() == '\n')  break;
    }
	for(int j=0;j<i;j++)
	{
		number=1;
		for(int h=j;h<i;h++)
			if(a[h+1]<=a[h]) number++;
		//maxnum=max(number,maxnum);
		cout<<number<<endl;
	}
	cout<<number;
}
