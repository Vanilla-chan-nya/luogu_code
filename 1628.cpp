#include<bits/stdc++.h>
using namespace std;
string t;
string word[100001];
string can[100001];
int n;
bool cmp(string a,string b){return a<b;}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>word[i];	
	}
	cin>>t;
	int headlen=t.size(),num=0;
	for(int i=0;i<n;i++)
	{
		int flag=1;
		for(int j=0;j<headlen;j++)
		{
			if(word[i][j]!=t[j]) flag=0;
		}
		if(flag) 
		{
			can[num++]=word[i];
		}
		
	}
	sort(can,can+num,cmp);
	for(int i=0;i<num;i++)
		cout<<can[i]<<endl; 
	return 0;
}
