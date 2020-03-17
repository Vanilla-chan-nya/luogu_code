#include<bits/stdc++.h>
using namespace std;
string sent;
int sam=0,ans=0;
int main()
{

	getline(cin,sent);
	for(int i=0;i<sent.size();i++)
	{
		if(sent[i]=='(') sam++;
		if(sent[i]==')') sam--;
		if(sam<0) {
			ans+=1;
			sam+=2;
		}
	}
	ans+=abs(sam/2);
	cout<<ans;
	return 0;
}
