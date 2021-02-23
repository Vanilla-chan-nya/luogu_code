#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
using namespace std;

template<class T>inline void read(T&x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int cnt;
struct node
{
	int l,r;
	int lson,rson;
	int sum;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define ls(x) b[x].lson
	#define rs(x) b[x].rson
	#define sum(x) b[x].sum
}b[10000010];
void upd(int p)
{
	sum(p)=sum(ls(p))+sum(rs(p));
}
void add(int p,int x)
{
//	debug
	if(l(p)==r(p))
	{
		sum(p)++;
		return;
	}
	int mid=l(p)+r(p)>>1;
	if(x<=mid)
	{
		if(!ls(p)) ls(p)=++cnt,l(ls(p))=l(p),r(ls(p))=mid;
		add(ls(p),x);
	}
	else
	{
		if(!rs(p)) rs(p)=++cnt,l(rs(p))=mid+1,r(rs(p))=r(p);
		add(rs(p),x);
	}
	upd(p);
}
LL ask(int p,int l,int r)
{
//	debug
	if(l<=l(p)&&r(p)<=r)
	{
		return sum(p);
	}
	LL ans=0;
	int mid=l(p)+r(p)>>1;
	if(l<=mid)
	{
		if(ls(p)) ans+=ask(ls(p),l,r);
	}
	if(r>mid)
	{
		if(rs(p)) ans+=ask(rs(p),l,r);
	}
	return ans;
}
int a[500010];
int n,mx;
LL ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i]-
	}
	l(cnt=1)=1;
	r(1)=mx;
	for(int i=1;i<=n;i++)
	{
		debug		
		ans+=ask(1,a[i]+1,mx);
		add(1,a[i]);
	}
	write(ans);
	return 0;
}


