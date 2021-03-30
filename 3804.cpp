/**************************************************************
 * Problem: 3804
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

namespace SAM
{
	const int maxn=1000010;
	struct state
	{
		int len,link;
		LL f;
		map<char,int>nxt;
		void clear()
		{
			len=link=f=0;
			nxt.clear();
		}
		state operator=(const state& z)
		{
			len=z.len;
			link=z.link;
			nxt=z.nxt;
			f=0;
			return *this;
		}
		state()
		{
			clear();
		}
	}st[maxn<<1];
	int cnt=1,last=1;
	void init()
	{
		do
		{
			st[cnt].clear();
			cnt--;
		} while(cnt);
		cnt=last=1;
	}
	void insert(const char &ch)
	{
		int p=last;
		int cur=last=++cnt;
		st[cur].f=1;
		st[cur].len=st[p].len+1;
		while(p&&!st[p].nxt[ch])
		{
			st[p].nxt[ch]=cur;
			p=st[p].link;
		}
		if(!p)
		{
			st[cur].link=1;
		}
		else
		{
			int q=st[p].nxt[ch];
			if(st[p].len+1==st[q].len)
			{
				st[cur].link=q;
			}
			else
			{
				int nq=++cnt; st[nq]=st[q];//复制有一个q，但是len改为st[p].len+1
				st[nq].len=st[p].len+1;
				st[q].link=st[cur].link=nq;
				while(p&&st[p].nxt[ch]==q)
				{
					st[p].nxt[ch]=nq;
					p=st[p].link;
				}
			}
		}
	}
	void insert(const string &str)
	{
		init();
		for(unsigned int i=0;i<str.size();i++)
		{
			insert(str[i]);
		}
	}
	bool judge(const string& str)
	{
		int p=1;
		for(unsigned int i=0;i<str.size();i++)
		{
			if(st[p].nxt.count(str[i])) p=st[p].nxt[str[i]];
			else return 0;
		}
		return 1;
	}
};
LL ans;
int head[SAM::maxn<<1],ver[SAM::maxn<<1],nxt[SAM::maxn<<1];
int cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
}
void dfs(int x)
{
	using namespace SAM;
	for(int i=head[x];i;i=nxt[i])
	{
		dfs(ver[i]);
		st[x].f+=st[ver[i]].f;
	}
	if(st[x].f!=1) ans=max(ans,st[x].f*st[x].len);
}
string str;
int main()
{
	//freopen("P3804_1.in","r",stdin);
	//freopen(".out","w",stdout);
	std::cin>>str;
	SAM::insert(str);
	for(int i=2;i<=SAM::cnt;i++) insert(SAM::st[i].link,i);
	dfs(1);
	write(ans);
	return 0;
}


