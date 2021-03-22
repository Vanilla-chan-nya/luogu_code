/**************************************************************
 * Problem: 5072
 * Author: Vanilla_chan
 * Date: 20210320
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

#define N 100010
#define sq 400
int n,m,block;
struct Ask
{
	int l,r,p,id;
	IL bool operator<(const Ask& z)const
	{
		if(l/block==z.l/block) return r<z.r;
		return l<z.l;
	}
}q[N];
struct List
{
	struct node
	{
		int pre,nxt;
		node(int a=0,int b=0)
		{
			pre=a;
			nxt=b;
		}
	}list[N];
	int cnt;
	List(int a=0)
	{
		cnt=a;
	}
	void insert(int x)
	{
		list[cnt].nxt=x;
		list[x].pre=cnt;
		cnt=x;
	}
	void erase(int x)
	{
		if(x!=cnt)
		{
			list[list[x].pre].nxt=list[x].nxt;
			list[list[x].nxt].pre=list[x].pre;
		}
		else
		{
			list[list[x].pre].nxt=0;
			cnt=list[x].pre;
		}
		list[x]=node();
	}
}list;
int a[N],cnt[N];
LL p,len;
LL ans[N],s[N];
void add(int x)
{
	int v=a[x];
	s[cnt[v]]-=v;
	if(s[cnt[v]]==0) list.erase(cnt[v]);
	cnt[v]++;
	if(s[cnt[v]]==0) list.insert(cnt[v]);
	s[cnt[v]]+=v;
}
void del(int x)
{
	int v=a[x];
	s[cnt[v]]-=v;
	if(s[cnt[v]]==0) list.erase(cnt[v]);
	cnt[v]--;
	if(s[cnt[v]]==0) list.insert(cnt[v]);
	s[cnt[v]]+=v;
}
LL pow2[2][N];
LL pw2(int x)
{
	return pow2[1][x/sq]*pow2[0][x%sq]%p;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//oi::cin>>n>>m;
	n=read();
	m=read();
	block=sqrt(n)+10;
	for(int i=1;i<=n;i++) a[i]=read();
	//for(int i=1;i<=m;i++) q[i].id=i,oi::cin>>q[i].l>>q[i].r>>q[i].p;
	for(int i=1;i<=m;i++) q[i].id=i,q[i].l=read(),q[i].r=read(),q[i].p=read();
	sort(q+1,q+m+1);
	int l=1,r=0;
	pow2[0][0]=pow2[1][0]=1;
	for(int i=1;i<=m;i++)
	{
		//printf("QUERY #%d: id=%d l=%d r=%d p=%d\n",i,q[i].id,q[i].l,q[i].r,q[i].p);
		while(l>q[i].l) add(--l);
		while(r<q[i].r) add(++r);
		while(l<q[i].l) del(l++);
		while(r>q[i].r) del(r--);
		p=q[i].p;
		len=r-l+1;
		for(int j=1;j<=sq;j++)
		{
			pow2[0][j]=pow2[0][j-1]*2%p;
		}
		for(int j=1;j<=sq;j++)
		{
			pow2[1][j]=pow2[1][j-1]*1ll*pow2[0][sq]%p;
		}
		LL& out=ans[q[i].id];
		LL p1,p2,p3;
		for(int j=list.list[0].nxt;j;j=list.list[j].nxt)
		{
			p1=pw2(len);
			p2=pw2(len-j);
			p3=((p1-p2)*s[j]+p)%p;
			out=(out+p3+p)%p;
		}
	}
	for(int i=1;i<=m;i++) write(ans[i]);
	return 0;
}


