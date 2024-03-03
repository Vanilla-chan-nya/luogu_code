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



#define N 5


int cnt_at(string s)
{
	int ans=0;for(int i=0;i<s.size();i++) if(s[i]=='@') ans++;
	return ans;
}
string str;
pair<string,string>last,now;
int cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	
	while(getline(cin,str))
	{
		if(str==""||str=="\r") break;
		++cnt;
		int maohao=str.find(':');
		now.first=str.substr(0,maohao-1);
		//cout<<now.first<<'\n';
		if(cnt!=1&&now.first==last.second)
		{
			cout<<"Successful @"<<now.first<<" attempt"<<'\n';
			return 0;
		}
		
		if(str.find('@')!=string::npos)
		{
			int at=str.find('@');
			int tail=str.find(' ',at+11);//@yyy loves
			if(str.find(' ',at+11)==string::npos) now.second=str.substr(at+1);
			else now.second=str.substr(at+1,tail-at-1);
			if(now.second.back()=='\r') now.second.pop_back();
			//cout<<now.second<<'\n';
		}
		
		
		
		if(cnt!=1&&(str.find('@')==string::npos||cnt_at(str)>=2||now.second!=last.second))
		{
			debug
			cout<<"Unsuccessful @"<<last.second<<" attempt"<<'\n';
			cout<<cnt<<'\n';
			cout<<now.first<<'\n';
			return 0;
		}
		
		
		
		last=now;
	}
	
	
	cout<<"Unsuccessful @"<<last.second<<" attempt"<<'\n';
	cout<<cnt<<'\n';
	
	
	
	cout<<"Good Queue Shape"<<'\n';
	
	
	return 0;
}
