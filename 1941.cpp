/**************************************************************
 * Problem: 1941
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
void chmin(int& x,const int& y)
{
	x=min(x,y);
}
int n,m,k;
int dp[10010][2010];
int up[10010];
int down[10010];
int low[10010];
int high[10010];
bool had[10010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		oi::cin>>up[i]>>down[i];
		low[i]=1;
		high[i]=m;
	}
	for(int i=1,a,b,c;i<=k;i++)
	{
		oi::cin>>a>>b>>c;
		had[a]=1;
		low[a]=b+1;
		high[a]=c-1;
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++) dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=up[i]+1;j<=m+up[i];j++)
		{
			dp[i][j]=min(dp[i-1][j-up[i]]+1,dp[i][j-up[i]]+1);
		}
		for(int j=m+1;j<=m+up[i];j++)
		{
			chmin(dp[i][m],dp[i][j]);
		}
		for(int j=1;j<=m-down[i];j++)
		{
			chmin(dp[i][j],dp[i-1][j+down[i]]);
		}
		for(int j=1;j<low[i];j++)
		{
			dp[i][j]=dp[0][0];
		}
		for(int j=high[i]+1;j<=m;j++)
		{
			dp[i][j]=dp[0][0];
		}
	}
	int ans=dp[0][0];
	for(int j=1;j<=m;j++)
	{
		chmin(ans,dp[n][j]);
	}
	if(ans!=dp[0][0])
	{
		cout<<1<<endl<<ans<<endl;
	}
	else
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			bool flag=0;
			for(int j=1;j<=m;j++)
			{
				if(dp[i][j]<dp[0][0])
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				for(int j=1;j<i;j++) if(had[j]) ans++;
				cout<<0<<endl<<ans<<endl;
				return 0;
			}
		}
	}
	return 0;
}


