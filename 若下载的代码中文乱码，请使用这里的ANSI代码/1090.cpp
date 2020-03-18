#include<iostream>
#include<queue>
using namespace std;

int a[10001];
priority_queue<int> q;
int n,ans,t;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i],q.push(-a[i]);
	for(int i=1;i<n;i++) t=q.top(),q.pop(),t+=q.top(),q.pop(),q.push(t),ans+=t;
	cout<<-ans;
	return 0;
}
