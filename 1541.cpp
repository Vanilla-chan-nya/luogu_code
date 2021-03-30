/**************************************************************
 * Problem: 1541
 * Author: Vanilla_chan
 * Date: 20210322
 * E-Mail: Vanilla_chan@outlook.com
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
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isdigit(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
	inline int read()
	{
		int x=0,fu=1;
		char ch=getchar();
		while(!isdigit(ch)&&ch!='-') ch=getchar();
		if(ch=='-') fu=-1,ch=getchar();
		x=ch-'0';ch=getchar();
		while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
		return x*fu;
	}
	int G[55];
	template<class T>inline void write(T x)
	{
		int g=0;
		if(x<0) x=-x,putchar('-');
		do { G[++g]=x%10;x/=10; } while(x);
		for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
	}
};
using namespace oi;
int n,m;
int b[5];
int a[400];
int dp[42][42][42][42];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[read()]++;
	dp[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++)
	{
		for(int j=0;j<=b[2];j++)
		{
			for(int x=0;x<=b[3];x++)
			{
				for(int y=0;y<=b[4];y++)
				{
					int now=i+j*2+x*3+y*4+1;
					if(i) dp[i][j][x][y]=max(dp[i][j][x][y],dp[i-1][j][x][y]+a[now]);
					if(j) dp[i][j][x][y]=max(dp[i][j][x][y],dp[i][j-1][x][y]+a[now]);
					if(x) dp[i][j][x][y]=max(dp[i][j][x][y],dp[i][j][x-1][y]+a[now]);
					if(y) dp[i][j][x][y]=max(dp[i][j][x][y],dp[i][j][x][y-1]+a[now]);
				}
			}
		}
	}
	write(dp[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}


