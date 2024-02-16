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

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
	inline int read()
	{
		int x=0,fu=0;char ch=getchar();
		while(!isdigit(ch)&&ch!='-') ch=getchar();
		if(ch=='-') fu=1,ch=getchar();
		while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
		if(fu) x=-x;
		return x;
	}
	int G[55];
	template<class T>inline void write(T x)
	{
		int g=0;
		if(x<0) x=-x,putchar('-');
		do { G[++g]=x%10;x/=10; } while(x);
		for(int i=g;i>=1;--i) putchar('0'+G[i]);
		putchar('\n');
	}
};
using oi::read;

#define N 1000010


bool s[2][2][100010];
int n,q;
pair<bool,bool>statu;
int main()
{
	cin>>n>>q;
	string str;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		s[0][0][i]=str[i]-'0';
	}
	for(int i=0;i<n;i++)
	{
		s[1][0][i]=s[0][0][n-i-1];
	}
	for(int i=0;i<n;i++)
	{
		s[0][1][i]=!s[0][0][i];
	}
	for(int i=0;i<n;i++)
	{
		s[1][1][i]=!s[1][0][i];
	}
	
	
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1') statu.first^=1;
		else statu.second^=1;
	}
	for(int i=0;i<n;i++)
	{
		cout<<s[statu.first][statu.second][i];
	}
	
	
	return 0;
}
