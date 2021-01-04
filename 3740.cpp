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
int n,m;
struct node{
	int l,r,cnt;
	int prv,nxt;
	node()
	{
		l=r=cnt=prv=nxt=0;
	}
	node(int ll,int rr,int cc,int pp,int nn)
	{
		l=ll,r=rr,cnt=cc,nxt=nn,prv=pp;
	}
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define cnt(x) b[x].cnt
	#define nxt(x) b[x].nxt
	#define prv(x) b[x].prv
}b[1000000];
int head=1,tail=2,cnt=1;//===++cnt;
int split(int x)
{
	int i;
	for(i=head;i!=tail;i=nxt(i))
	{
		if(l(i)>=x) break;
	}
	if()
}
int main()
{
	n=read();
	m=read();
	b[++cnt]=node(1,n,0,0,2);
	
	for(int i=1,l,r;i<=m;i++)
	{
		l=read(),r=read();
		
	}
	return 0;
}


