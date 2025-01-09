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
		string text="ABABABC",pattern="ABA";
		cin>>text>>pattern;
		vector<int>nxt(pattern.size());
		unsigned int i=1,j=0;
		while(i<pattern.size())
		{
			if(pattern[i]==pattern[j])
			{
				nxt[i]=j+1;
				i++;
				j++;
			}
			else
			{
				if(j==0)
				{
					i++;
				}
				else
				{
					j=nxt[j-1];
				}
			}
		}
		i=0,j=0;
		vector<int>ans;
		while(i<text.size())
		{
			if(text[i]==pattern[j])
			{
				i++;
				j++;
				if(j==pattern.size())
				{
					ans.push_back(i-j+1);
					j=nxt[j-1];
				}
			}
			else
			{
				if(j==0)
				{
					i++;
				}
				else
				{
					j=nxt[j-1];
				}
			}
		}
		for(unsigned int x=0;x<ans.size();x++) cout<<ans[x]<<endl;
		for(unsigned int x=0;x<nxt.size();x++) cout<<nxt[x]<<" ";
		
		
	}
	return 0;
}
