/**************************************************************
 * Problem: 3975
 * Author: Vanilla_chan
 * Date: 20210326
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
	const int maxn=500010;
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
		st[cur].f=1;
		st[cur].len=st[p].len+1;
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
			if(st[q].len==st[p].len+1)
			{
				st[cur].link=q;//
			}
			else
			{
				int nq=++cnt;
				st[nq]=st[q];
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
	void insert(const string& str)
	{
		for(unsigned int i=0;i<str.size();i++)
		{
			insert(str[i]);
		}
	}
};
#define N 500010
int t,k;
string str;
int l,r,q[N<<1],in[N<<1],sum[N<<1];
using IT=map<char,int>::iterator;
void top()
{
	using namespace SAM;
	for(int i=1;i<=cnt;i++)
	{
		for(IT it=st[i].nxt.begin();it!=st[i].nxt.end();it++)
		{
			in[it->second]++;
		}
	}
	l=1,r=0;
	for(int i=1;i<=cnt;i++) if(in[i]==0) q[++r]=i;
	for(;l<=r;l++)
	{
		for(IT it=st[q[l]].nxt.begin();it!=st[q[l]].nxt.end();it++)
		{
			in[it->second]--;
			if(in[it->second]==0) q[++r]=it->second;
		}
	}
	for(int i=r;i>=1;i--)
	{
		if(t)
		{
			st[st[q[i]].link].f+=st[q[i]].f;
		}
		else
		{
			st[q[i]].f=1;
		}
	}
	st[1].f=0;
	for(int i=r;i>=1;i--)
	{
		sum[q[i]]=st[q[i]].f;
		for(IT it=st[q[i]].nxt.begin();it!=st[q[i]].nxt.end();it++)
		{
			sum[q[i]]+=sum[it->second];
		}
	}
}
void ask(int k)
{
	using namespace SAM;
	int x=1;
	if(k>sum[1])
	{
		cout<<"-1"<<endl;
		return;
	}
	k-=st[x].f;
	while(k>0)
	{
		IT it;
		for(it=st[x].nxt.begin();it!=st[x].nxt.end();it++)
		{
			if(k>sum[it->second]) k-=sum[it->second];
			else break;
		}
		putchar(it->first);
		x=it->second;
		k-=st[x].f;
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	oi::cin>>str>>t>>k;
	SAM::insert(str);
	top();
	ask(k);
	return 0;
}


