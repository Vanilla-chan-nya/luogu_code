/**************************************************************
 * Problem: 3120
 * Author: Vanilla_chan
 * Date: 20210319
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

#define mod 1000000007
#define N 800
int n,m;
int a[N][N],ans[N][N],sum[N];
struct node
{
	int ls,rs;
	LL sum;
#define ls(x) b[x].ls
#define rs(x) b[x].rs
#define sum(x) b[x].sum
}b[N*N*10];
int cnt;
void upd(int p)
{
	sum(p)=sum(ls(p))+sum(rs(p));
	sum(p)%=mod;
}
void change(int& p,int l,int r,int x,int v)
{
	if(!p) p=++cnt;
	if(l==r)
	{
		b[p].sum+=v;
		b[p].sum%=mod;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) change(ls(p),l,mid,x,v);
	else change(rs(p),mid+1,r,x,v);
	upd(p);
}
LL ask(int x,int l,int r,int L,int R)
{
	if(!x) return 0;
	if(L<=l&&r<=R)
	{
		return sum(x);
	}
	int mid=l+r>>1;
	LL ans=0;
	if(L<=mid) ans+=ask(ls(x),l,mid,L,R);
	if(R>mid) ans+=ask(rs(x),mid+1,r,L,R);
	return ans%mod;
}
int main()
{
	oi::cin>>n>>m>>cnt;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			oi::cin>>a[i][j];
		}
	}
	ans[1][1]=1;
	for(int i=1;i<=m;i++) sum[i]=1;
	change(a[1][1],1,m,1,1);
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			ans[i][j]=(sum[j-1]-ask(a[i][j],1,m,1,j-1))%mod;
			ans[i][j]+=mod;
			ans[i][j]%=mod;
		}
		LL t=0;
		for(int j=2;j<=m;j++)
		{
			t=(t+ans[i][j])%mod;
			change(a[i][j],1,m,j,ans[i][j]);
			sum[j]=(t+sum[j])%mod;
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	write(ans[n][m]);
	return 0;
}


