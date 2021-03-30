/**************************************************************
 * Problem: 3792
 * Author: Vanilla_chan
 * Date: 20210321
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
#define LL unsigned long long
#define ULL unsigned long long
//#define int ULL
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
#define N 500010
int n,m;
int a[N];
struct node
{
	int l,r,mx,mn;
	ULL sum,pow2,cub;
#define l(x) b[x].l
#define r(x) b[x].r
#define mx(x) b[x].mx
#define mn(x) b[x].mn
#define sum(x) b[x].sum
#define pow2(x) b[x].pow2
#define cub(x) b[x].cub
}b[N*4];
void upd(int p)
{
	mx(p)=max(mx(p<<1),mx(p<<1|1));
	mn(p)=min(mn(p<<1),mn(p<<1|1));
	sum(p)=sum(p<<1)+sum(p<<1|1);
	pow2(p)=pow2(p<<1)+pow2(p<<1|1);
	cub(p)=cub(p<<1)+cub(p<<1|1);
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		cub(p)=pow2(p)=sum(p)=mx(p)=mn(p)=a[l];
		pow2(p)*=pow2(p);
		cub(p)*=pow2(p);
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
void change(int p,int x,int k)
{
	if(l(p)==r(p))
	{
		cub(p)=pow2(p)=sum(p)=mx(p)=mn(p)=a[x]=k;
		pow2(p)*=pow2(p);
		cub(p)*=pow2(p);
		return;
	}
	int mid=l(p)+r(p)>>1;
	if(x<=mid) change(p<<1,x,k);
	else change(p<<1|1,x,k);
	upd(p);
}
int ask_mx(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return mx(p);
	}
	int mid=l(p)+r(p)>>1;
	if(r<=mid) return ask_mx(p<<1,l,r);
	if(l>mid) return ask_mx(p<<1|1,l,r);
	return max(ask_mx(p<<1,l,r),ask_mx(p<<1|1,l,r));
}
int ask_mn(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return mn(p);
	}
	int mid=l(p)+r(p)>>1;
	if(r<=mid) return ask_mn(p<<1,l,r);
	if(l>mid) return ask_mn(p<<1|1,l,r);
	return min(ask_mn(p<<1,l,r),ask_mn(p<<1|1,l,r));
}
ULL ask_sum(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return sum(p);
	}
	int mid=l(p)+r(p)>>1;
	if(r<=mid) return ask_sum(p<<1,l,r);
	if(l>mid) return ask_sum(p<<1|1,l,r);
	return ask_sum(p<<1,l,r)+ask_sum(p<<1|1,l,r);
}
ULL ask_pow(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return pow2(p);
	}
	int mid=l(p)+r(p)>>1;
	if(r<=mid) return ask_pow(p<<1,l,r);
	if(l>mid) return ask_pow(p<<1|1,l,r);
	return ask_pow(p<<1,l,r)+ask_pow(p<<1|1,l,r);
}
ULL ask_cub(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return cub(p);
	}
	int mid=l(p)+r(p)>>1;
	if(r<=mid) return ask_cub(p<<1,l,r);
	if(l>mid) return ask_cub(p<<1|1,l,r);
	return ask_cub(p<<1,l,r)+ask_cub(p<<1|1,l,r);
}
ULL mx,mn;
ULL sum;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	int l,r,op;
	while(m--)
	{
		op=read();
		l=read();
		r=read();
		if(op==1)
		{
			change(1,l,r);
		}
		else
		{
			mx=ask_mx(1,l,r);
			mn=ask_mn(1,l,r);
			if(mx-mn!=r-l)
			{
				cout<<"yuanxing"<<endl;
				continue;
			}
			if(ask_sum(1,l,r)*2!=(mn+mx)*(mx-mn+1))
			{
				cout<<"yuanxing"<<endl;
				continue;
			}
			if(ask_pow(1,l,r)*6!=(mx*(mx+1)*(2*mx+1))-(mn*(mn-1)*(2*mn-1)))
			{
				cout<<"yuanxing"<<endl;
				continue;
			}
			if(ask_cub(1,l,r)*4!=(1+mx)*(1+mx)*mx*mx-mn*mn*(mn-1)*(mn-1))
			{
				cout<<"yuanxing"<<endl;
				continue;
			}
			cout<<"damushen"<<endl;
		}
	}
	return 0;
}


