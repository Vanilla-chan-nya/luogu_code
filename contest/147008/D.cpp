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
		putchar(' ');
	}
};
using oi::read;

#define N 1000010


int t;
int n;
int a[N];
int m;
map<int,int>M,dM,ddM;
int m1,m2;
int main()
{
	t=read();
	while(t--)
	{
		dM.clear();
		ddM.clear();
		M.clear();
		n=read();
		m=read();
		
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			M[a[i]]++;
		}
		
		while(m--)
		{
			if(m==-2) break;
			m1=-1;
			m2=-1;
			M.clear();
			for(int i=1;i<=n;i++)
			{
				M[a[i]]++;
			}
			
			if(M==dM) break;
			if(M==ddM) break;
			
			
			
			if(M.size()==1)
			{
				m%=2;
			}
			if(M.size()==2&&(*M.begin()).first==0&&M[0]==1)
			{
				m%=2;
			}
			
			/*
			for(int i=0;;i++)
			{
				if(M.find(i)==M.end()) break;
				if(m1==i-1&&M[i]>=1)
				{
					m1=i;
				}
				if(m2==-1&&M[i]>=2) m2=i;
			}
			*/
			
			for(auto it=M.begin();it!=M.end();it++)
			{
				if(m1!=it->first-1) break;
				m1++;
				if(m2==-1&&it->second>=2) m2=it->first;
			}
			
			
			
			debug
			
			auto it = M.end();
			it--;
			if(m1==it->first)
			{
				if(m2==-1) break;
				if(m2==m1) m%=2;
			}
				
			
			
			for(int i=1;i<=n;i++)
			{
				if(a[i]<=m1)
				{
					if(M[a[i]]>1) a[i]=m1+1;
					
				}
				else if(a[i]>m1) a[i]=m1+1;
			}
			
			ddM=dM;
			dM=M;
			
		}
		
		
		
		for(int i=1;i<=n;i++) oi::write(a[i]);
		putchar('\n');
		
	}
	
	
	
	
	
	
	return 0;
}
