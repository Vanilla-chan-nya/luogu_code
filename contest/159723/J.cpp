/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 110
int n,q;
vector<string>c[N];

set<char>s;
vector<string>trans(string str)
{
	vector<int>start;
	vector<string>ans;
	start.push_back(0);
	for(int i=0;i<(int)str.size();i++)
	{
		if(s.find(str[i])!=s.end()&&i+1<(int)str.size()) start.push_back(i+1);
		else
		{
			if(str[i]=='n'&&i+1<(int)str.size()&&s.find(str[i+1])==s.end()) start.push_back(i+1);
		}
		
	}
	start.push_back(str.size());
	for(int i=0;i<(int)start.size()-1;i++)
	{
		ans.push_back(str.substr(start[i],start[i+1]-start[i]));
		//cout<<ans.back()<<" ";
	}
	return ans;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	cin>>n>>q;
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
	string str;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		c[i]=trans(str);
	}
	vector<string>now;
	while(q--)
	{
		cin>>str;
		now=trans(str);
		int num=0;
		for(int i=1;i<=n;i++)
		{
			bool fail=1;
			for(int p=0;p+c[i].size()-1<now.size();p++)
			{
				bool win=1;
				for(int j=0;j<c[i].size();j++)
				{
					if(now[p+j]!=c[i][j]) win=0;
				}
				if(win) fail=0;
			}
			if(fail==0) num++;
		}
		if(num==1)
		{
			cout<<"Yes, Commander"<<endl;
		}
		else{
			cout<<"No, Commander"<<endl;
		}
	}
	return 0;
}
