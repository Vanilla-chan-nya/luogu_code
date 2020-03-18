#include<bits/stdc++.h>
using namespace std;
string x,y;
int n;
//x>=y&&z>=y
int main()
{
	cin>>n;
	cin>>x>>y;
	for(int i=0;i<n;i++)
	if(x[i]<y[i])
	{
		cout<<"-1";
		return 0;
	}
	cout<<y;
	return 0;
}
