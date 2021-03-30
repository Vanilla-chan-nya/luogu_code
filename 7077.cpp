/**************************************************************
 * Problem: 7077
 * Author: Vanilla_chan
 * Date: 7077
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
#define int LL
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
		for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar(' ');
	}
};
using namespace oi;

#define N 100010
#define mod 998244353
int n,m,t;
int a[N],op[N],pos[N],val[N],mul[N],in[N],f[N],add[N];
bool book[N];
vector<int>g[N];
void dfs(int x)
{
	book[x]=1;
	if(op[x]==2) mul[x]=val[x];
	else mul[x]=1;
	for(unsigned int i=0;i<g[x].size();i++)
	{
		if(book[g[x][i]]==0) dfs(g[x][i]);
		mul[x]=mul[x]*mul[g[x][i]]%mod;
	}
}
int task[N],q[N];
int l=1,r=0;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m=read();
	for(int i=1,t,c;i<=m;i++)
	{
		op[i]=read();
		if(op[i]==1) pos[i]=read(),val[i]=read();
		else if(op[i]==2) val[i]=read();
		else
		{
			c=read();
			while(c--)
			{
				t=read();
				in[t]++;
				g[i].push_back(t);
			}
		}
	}
	for(int i=1;i<=m;i++) if(in[i]==0&&!book[i]) dfs(i);
	t=read();
	for(int i=1;i<=t;i++)
	{
		task[i]=read();
	}
	LL mu=1;
	for(int i=t;i>=1;i--)
	{
		if(op[task[i]]==1) f[task[i]]+=mu;
		else if(op[task[i]]==2) mu=mu*val[task[i]]%mod;
		else f[task[i]]+=mu,mu=mu*mul[task[i]]%mod;
	}
	for(int i=1;i<=m;i++) if(!in[i]) q[++r]=i;
	int ff;
	while(l<=r)
	{
		int x=q[l];
		l++;
		if(op[x]==1)
		{
			add[pos[x]]+=f[x]*val[x]%mod;
			add[pos[x]]%=mod;
		}
		ff=f[x];
		for(int i=g[x].size()-1;i>=0;i--)
		{
			in[g[x][i]]--;
			if(!in[g[x][i]]) q[++r]=g[x][i];
			f[g[x][i]]+=ff;
			f[g[x][i]]%=mod;
			ff=ff*mul[g[x][i]]%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		write((a[i]*mu+add[i])%mod);
	}
	return 0;
}


