/**************************************************************
 * Problem: 1983
 * Author: Vanilla_chan
 * Date: 20210329
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

#define N 1010
#define M 100000010
int n,m;
vector<int>a[N];
bool edge[N][N];
bool book[N];
int in[N];
void insert(int x,int y)
{
	if(!edge[x][y]) edge[x][y]=1,in[y]++;
}
int q[N],dis[N];
int l,r,x;
int main()
{
//	freopen("P1983_8.in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1,t;i<=m;i++)
	{
		memset(book,0,sizeof(book));
		t=read();
		while(t--) a[i].push_back(read()),book[a[i].back()]=1;
		for(int j=a[i].front();j<=a[i].back();j++)
		{
			if(!book[j])
			for(int k=0;k<a[i].size();k++) insert(a[i][k],j);
		}
	}
	l=1,r=0;
	for(int i=1;i<=n;i++) if(in[i]==0) q[++r]=i,dis[i]=1;
	while(l<=r)
	{
		x=q[l];
		l++;
		for(int i=1;i<=n;i++)
		{
			if(!edge[x][i]) continue;
			in[i]--;
			if(in[i]==0) q[++r]=i,dis[i]=dis[x]+1;
		}
	}
	write(dis[q[r]]);
	return 0;
}


