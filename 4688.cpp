/**************************************************************
 * Problem: 4688
 * Author: Vanilla_chan
 * Date: 20210319
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
#include<bitset>
#define N 100010
#define M 50010
int n,m;
bitset<N>ans[M],now;
int sum[M];
int a[N],b[N];
int block;
struct Ask
{
	int l,r,id;
	IL bool operator<(const Ask& z)const
	{
		if(l/block!=z.l/block) return l<z.l;
		return (l/block&1)?r<z.r:r>z.r;
	}
}q[N*3];
int tot,res,ct;
int cnt[N];
IL void add(int x)
{
	now.set(x+cnt[x]);
	cnt[x]++;
}

IL void del(int x)
{
	cnt[x]--;
	now.reset(x+cnt[x]);
}
int l,r,i,P,part,j;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	oi::cin>>n>>m;
	res=m;
	part=m/3+10;
	block=sqrt(n);
	for(int i=1;i<=n;i++) b[i]=a[i]=read();
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	}
	for(P=0;P<3;P++)
	{
		memset(cnt,0,sizeof(cnt));
		now.reset();
		tot=0;
		ct=0;
		for(i=1;i<=part&&res;i++)
		{
			tot++;
			sum[i]=0;
			ans[i].set();
			res--;
			for(j=1;j<=3;j++)
			{
				ct++;
				q[ct].id=tot;
				oi::cin>>q[ct].l>>q[ct].r;
				sum[tot]+=q[ct].r-q[ct].l+1;
			}
		}
		sort(q+1,q+ct+1);
		l=1,r=0;
		for(i=1;i<=ct;i++)
		{
			while(l>q[i].l) add(a[--l]);
			while(r<q[i].r) add(a[++r]);
			while(l<q[i].l) del(a[l++]);
			while(r>q[i].r) del(a[r--]);
			ans[q[i].id]&=now;
		}
		for(i=1;i<=tot;i++) write(sum[i]-(int)ans[i].count()*3);
	}
	return 0;
}

