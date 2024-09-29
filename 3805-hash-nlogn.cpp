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



#define N 12000000
#define pLL pair<LL,LL>
string str;
const LL p1=998244353,p2=1000000007;
const LL k=33;

LL powk1[N],powk2[N];

LL hsh[N],rhsh[N];

LL qpow(LL a,LL b,LL p)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans%p;
}

LL inv(LL a,LL p)
{
	return qpow(a,p-2,p);
}

pLL calc_hash(int l,int r)
{
	LL 
}

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
		cin>>str;
		
		powk1[0]=powk2[0]=1;
		for(unsigned int i=1;i<=str.size();i++)
		{
			powk1[i]=powk1[i-1]*k%p1;
			powk2[i]=powk2[i-1]*k%p2;
		}
		
		for(unsigned int i=0;i<str.size();i++)
		{
			hsh1[i]=hsh1[i-1]+(str[i]-'a')*powk1[i];
			rhsh1[i]=rhsh1[i-1]+(str[i]-'a')*powk1[str.size()-i-1];
		}
		
		
		
		int L=1,R=str.size()-1,mid;
		while(R>=L)
		{
			mid=(L+R)/2;
			bool succ=0;
			for(int i=0;i<=n;i++)
			{
				int l=i
			}
		}
		
		
		
		
	}
	return 0;
}
