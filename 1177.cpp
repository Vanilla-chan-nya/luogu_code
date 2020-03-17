#include<iostream>
#include<tr1/unordered_map>
using namespace std;
tr1::unordered_map<int,int>m;
int n,t,maxn=0,minn=1e9;
inline max(int a,int b){return a>b?a:b;}
inline min(int a,int b){return a<b?a:b;}
inline int read()
{
	int ans=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>'0'&&ch<'9') ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) t=read(),m[t]++,maxn=max(t,maxn),minn=min(minn,t);
	for(int i=0;i<=maxn;i++)
	{
		if(m.find(i)!=m.end())
		for(int j=1;j<=m[i];j++) cout<<i<<" ";
	}
	return 0;
}
