/**************************************************************
 * Problem: 1494
 * Author: Vanilla_chan
 * Date: 20210323
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
#define N 50010

int n,m,block;
int a[N];
struct Ask
{
	LL l,r;
	int id;
	bool operator<(const Ask& z)const
	{
		if(l/block==z.l/block) return r<z.r;
		return l<z.l;
	}
}q[N];
LL tot[N];
pair<LL,LL>ans[N];
LL now;
void add(int x)
{
	x=a[x];
	now-=tot[x]*(tot[x]-1);
	tot[x]++;
	now+=tot[x]*(tot[x]-1);
}
void del(int x)
{
	x=a[x];
	now-=tot[x]*(tot[x]-1);
	tot[x]--;
	now+=tot[x]*(tot[x]-1);
}
LL gcd(LL x,LL y)
{
	//return 1;
	if(y) return gcd(y,x%y);
	return x;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
	}
	block=sqrt(n);
	sort(q+1,q+m+1);
	LL l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		if(q[i].l==q[i].r)
		{
			ans[q[i].id]=make_pair(0,1);
			continue;
		}
		while(l>q[i].l) add(--l);
		while(r<q[i].r) add(++r);
		while(l<q[i].l) del(l++);
		while(r>q[i].r) del(r--);
		ans[q[i].id]=make_pair(now,(r-l+1)*(r-l));
	}
	for(int i=1;i<=m;i++)
	{
		if(ans[i].first==0)
		{
			cout<<"0/1"<<endl;
		}
		else cout<<ans[i].first/gcd(ans[i].first,ans[i].second)<<"/"<<ans[i].second/gcd(ans[i].first,ans[i].second)<<endl;
	}
	return 0;
}


