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



#define N 1000010

int cnt[100];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n;cin>>n;
		string str;cin>>str;
		bool fail=0;
		for(int i=0;i<(int)str.size();i++)
		{
			cnt[str[i]-'0']++;
			if(str[i]!='2'&&str[i]!='0'&&str[i]!='1'&&str[i]!='4') fail=1;
		}
		if(cnt[0]!=cnt[1]) fail=1;
		if(cnt[1]!=cnt[2]) fail=1;
		if(cnt[2]!=cnt[4]) fail=1;
		if(cnt[0]!=cnt[4]) fail=1;
		
		if(fail) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		
	}
	return 0;
}
