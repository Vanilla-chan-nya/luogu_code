#include<bits/stdc++.h>
using namespace std;
string x;
int main()
{
	getline(cin,x);
	for(int i=0;i<x.size();i++)
	{
		int t=x[i]-'0';
		t=min(t,(i==0)?((9-t==0)?t:9-t):9-t);
		x[i]=t+'0';
	}
	cout<<x;
	return 0;
}


