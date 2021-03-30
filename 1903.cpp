/**************************************************************
 * Problem: 1903
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
#define N 200000
int n,m;
int block;
struct Ask
{
	int l,r,t,id;
	bool operator<(const Ask& z)const
	{
		if(l/block!=z.l/block) return l<z.l;
		if(r/block!=z.r/block) return r<z.r;
		return t<z.t;
	}
}q[N];
int qcnt,tcnt;
int a[N],ans[N],now;
int cnt[1000010];
void add(int x)
{
	x=a[x];
	if(cnt[x]==0) now++;
	cnt[x]++;
}
void del(int x)
{
	x=a[x];
	cnt[x]--;
	if(cnt[x]==0) now--;
}
struct change
{
	int pos,val;
}C[N];
void work(int x,int i)
{
	if(C[x].pos>=q[i].l&&C[x].pos<=q[i].r)
	{
		cnt[a[C[x].pos]]--;
		if(cnt[a[C[x].pos]]==0) now--;
		if(cnt[C[x].val]==0) now++;
		cnt[C[x].val]++;
	}
	swap(C[x].val,a[C[x].pos]);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	oi::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		oi::cin>>a[i];
	}
	string str;
	for(int i=1;i<=m;i++)
	{
		oi::cin>>str;
		if(str[0]=='Q')
		{
			q[++qcnt].l=read();
			q[qcnt].r=read();
			q[qcnt].id=qcnt;
			q[qcnt].t=tcnt;
		}
		else
		{
			C[++tcnt].pos=read();
			C[tcnt].val=read();
		}
	}
	block=ceil(exp((log(n)+log(tcnt+1))/3));//????
	block=pow(n*(double)(tcnt+1),1.0/3);
	sort(q+1,q+qcnt+1);
	int l=1,r=0,nowt=0;
	for(int i=1;i<=qcnt;i++)
	{
		while(l>q[i].l) add(--l);
		while(r<q[i].r) add(++r);
		while(l<q[i].l) del(l++);
		while(r>q[i].r) del(r--);
		while(nowt<q[i].t) work(++nowt,i);
		while(nowt>q[i].t) work(nowt--,i);
		ans[q[i].id]=now;
		//cout<<"id="<<q[i].id<<" l="<<l<<" r="<<r<<endl;
		//for(int j=1;j<=10;j++) cout<<cnt[j]<<" ";
		//cout<<endl;
	}
	for(int i=1;i<=qcnt;i++) cout<<ans[i]<<endl;
	return 0;
}


