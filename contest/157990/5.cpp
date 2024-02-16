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

#define N 100010

int t;
int n,m;
bool s[N];
int local[N];
int cnt;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		memset(s,0,sizeof(s));
		memset(local,0,sizeof(local));
		cnt=0;
		string str;cin>>str;
		for(int i=1;i<=m;i++)
		{
			s[i]=str[i-1]-'0';
			if(s[i]) local[++cnt]=i;
		}
		if(cnt==0)
		{
			if(m<=n)
			{
				cout<<"Yes"<<endl;
			}
			else cout<<"No"<<endl;
		}
		else if(cnt==1)
		{
			int dis=max(local[1]-1,m-local[1]);
			if(dis<=n)
			{
				cout<<"Yes"<<endl;	
			}
			else cout<<"No"<<endl;
		}
		else{
			int dis=local[2]-local[1];
			bool flag=1;
			for(int i=2;i<=cnt;i++)
			{
				if(local[i]-local[i-1]!=dis) flag=0;
			}
			if(dis>n) flag=0;
			if(local[1]-1>dis-1||m-local[cnt]>dis-1) flag=0;
			if(flag)
			{
				cout<<"Yes"<<endl;	
			}
			else cout<<"No"<<endl;
		}
		 
		
		
		
	}
	
	
	
	
	
	
	return 0;
}
