#include<bits/stdc++.h>
using namespace std;
int n,T;
priority_queue<int>q;
int main()
{
	cin>>T;
	int t;
	while(T--)
	{
		cin>>t;
		if(t==1){
			int tn;
			cin>>tn;
			q.push(-tn);
		}
		if(t==2){
			cout<<-q.top()<<endl;
		}
		if(t==3){
			q.pop();
		}
	}
	return 0;
}
