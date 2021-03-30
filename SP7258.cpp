/**************************************************************
 * Problem: SP7258
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
#include<set>
#include<map>
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
	const int maxn=90010;
	struct state
	{
		int len,link;
		LL f;
		map<char,int>nxt;
		state operator=(const state& z)
		{
			len=z.len;
			link=z.link;
			nxt=z.nxt;
			f=0;
			return *this;
		}
	}st[maxn<<1];
	int cnt=1,last=1;
	void insert(const char& ch)
	{
		int p=last;
		int cur=last=++cnt;
		st[cur].len=st[p].len+1;
		st[cur].f=1;
		while(p&&!st[p].nxt.count(ch))
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
			if(st[p].len+1==st[q].len)//
			{
				st[cur].link=q;
			}
			else
			{
				int nq=++cnt;
				st[nq]=st[q];
				st[nq].len=st[p].len+1;//
				st[q].link=st[cur].link=nq;
				while(p&&st[p].nxt[ch]==q)
				{
					st[p].nxt[ch]=nq;
					p=st[p].link;
				}
			}
		}
	}
};
#define N 90010
LL ans;
int in[N<<1];
int l,r;
int q[N<<1];
int sze[N<<1];
void top()
{
	using namespace SAM;
	for(int i=1;i<=cnt;i++)
	{
		for(map<char,int>::iterator it=st[i].nxt.begin();it!=st[i].nxt.end();it++)
		{
			in[it->second]++;
		}
	}
	l=1,r=0;
	for(int i=1;i<=cnt;i++) if(in[i]==0) q[++r]=i;
	for(;l<=r;l++)
	{
		for(map<char,int>::iterator it=st[q[l]].nxt.begin();it!=st[q[l]].nxt.end();it++)
		{
			in[it->second]--;
			if(in[it->second]==0)
			{
				q[++r]=it->second;
			}
		}
	}
	for(int i=r;i>=1;i--)
	{
		sze[q[i]]=1;
		for(map<char,int>::iterator it=st[q[i]].nxt.begin();it!=st[q[i]].nxt.end();it++)
		{
			sze[q[i]]+=sze[it->second];
		}
	}
}
void ask(int x,int k)
{
	using namespace SAM;
	while(k)
	{
		for(map<char,int>::iterator it=st[x].nxt.begin();it!=st[x].nxt.end();it++)
		{
			if(sze[it->second]>=k)
			{
				putchar(it->first);
				x=it->second;
				k--;
				break;
			}
			else k-=sze[it->second];
		}
	}
	cout<<endl;
}
string str;
int n,t,k;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	oi::cin>>str;
	for(int i=0;i<str.size();i++)
	{
		SAM::insert(str[i]);
	}
	top();
	t=read();
	while(t--)
	{
		oi::cin>>k;
		ask(1,k);
	}
	return 0;
}

