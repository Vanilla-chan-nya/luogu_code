/**************************************************************
 * Problem: 4070
 * Author: Vanilla_chan
 * Date: 20210325
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
			for(;!isalnum(ch);ch=getchar());
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

LL ans;
namespace SAM
{
	const int maxn=100010;
	struct node
	{
		int len,link;
		map<int,int>nxt;
	}st[maxn<<1];
	int cnt=1,last=1;
	void insert(const int& x)
	{
		int p=last;
		int cur=last=++cnt;
		st[cur].len=st[p].len+1;
		while(p&&!st[p].nxt[x])
		{
			st[p].nxt[x]=cur;
			p=st[p].link;
		}
		if(!p)
		{
			st[cur].link=1;
		}
		else
		{
			int q=st[p].nxt[x];
			if(st[q].len==st[p].len+1)
			{
				st[cur].link=q;
			}
			else
			{
				int nq=++cnt;
				st[nq]=st[q];
				st[nq].len=st[p].len+1;
				st[q].link=st[cur].link=nq;
				while(p&&st[p].nxt[x]==q)
				{
					st[p].nxt[x]=nq;
					p=st[p].link;
				}
			}
		}
		ans+=st[cur].len-st[st[cur].link].len;
	}
};
int n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		SAM::insert(read());
		write(ans);
	}
	return 0;
}


