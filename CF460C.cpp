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
#define re register
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

template<class T>inline void read(T&x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    int g=0;
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m,w;
int a[100010],delta[100010];
//struct node
//{
//	int l,r,sum;
//	#define l(x) b[x].l
//	#define r(x) b[x].r
//	#define sum(x) b[x].sum
//}b[400010];
//void upd(int p)
//{
//	sum(p)=sum(p*2)+sum(p*2+1);
//}
//void build(int l,int r,int p)
//{
//	l(p)=l;
//	r(p)=r;
//	if(l==r)
//	{
//		sum()
//	}
//}

bool check(int x)
{
	int now=0,tme=0;
	for(int i=1;i<=n;i++)
	{
		now+=delta[i];
		if(now<x)
		{
			delta[i]+=x-now;
			delta[min(i+w+1,n)]-=x-now;
			tme+=x-now;
		}
		if(tme>m) return 0;
	}
	return 1;
}

int main()
{
	n=read();
	m=read();
	w=read();
	int l=1000000000,r=0,mid;
	for(int i=1;i<=n;i++) a[i]=read(),r=max(a[i]+m,r),l=min(l,a[i]);
	while(l<r)
	{
		mid=(l+r)>>1;
		for(int i=1;i<=n;i++) delta[i]=a[i]-a[i-1];
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<mid+1;
	return 0;
}

