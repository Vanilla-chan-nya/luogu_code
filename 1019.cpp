#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>	
#define IL inline
#define re register
#define LL long long
using namespace std;

string word[25];
char start;
int n;
int book[25];
int maxans;

int match(string a,string b)
{
//	cout<<"匹配"<<a<<" "<<b<<endl; 
	for(int i=1;i<min(a.size(),b.size());i++)
	{
//		cout<<"i:"<<i<<endl;
		bool flag=1;
		for(int j=0;j<i;j++)
		{
//			cout<<"j:"<<j<<endl;
			if(b[j]!=a[a.size()-i+j]){
				flag=0;
				break;
			}
		}
		if(flag) return i;
	}
	return 0;
}

void dfs(int len,int last)
{
	maxans=max(len,maxans);
	for(int i=0;i<n;i++)
		if(book[i]<2)
		{
			if(match(word[last],word[i]))
			{
				book[i]++;
//				cout<<"加入"<<word[i]<<endl;
				dfs(len+word[i].size()-match(word[last],word[i]),i);
//				cout<<"stop"<<word[i]<<"\n";
				book[i]--;
			}	
		}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>word[i];
	cin>>start;
	for(int i=0;i<n;i++)
	{
		if(word[i][0]!=start) continue;
		book[i]++;
//		cout<<"首选"<<i<<endl;
		dfs(word[i].size(),i);
		book[i]--;
	}
	cout<<maxans;
	return 0;
}


