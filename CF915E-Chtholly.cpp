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
int ans;
struct node
{
	int l,r;
	mutable int v;
	node()
	{
		l=r=v=0;
	}
	node(int ll,int rr=-1,int vv=1)
	{
		l=ll;
		r=rr;
		v=vv;
	}
	bool operator<(const node & z)const
	{
		return l<z.l;
	}
};
int n,m;
set<node>Chtholly;
#define s Chtholly
#define IT set<node>::iterator
IT split(int x)
{
	IT it=s.lower_bound(node(x));
	if(it!=s.end()&&it->l==x) return it;
	it--;
	node temp=*it;
	s.erase(it);
	s.insert(node(temp.l,x-1,temp.v));
	return s.insert(node(x,temp.r,temp.v)).first;
}
void assign(int l,int r,int k)
{
	IT y=split(r+1),x=split(l);
	int delta=0;
	for(IT pos=x;pos!=y;pos++)
	{
		if(pos->v!=k) delta+=pos->r-pos->l+1;
	}
	s.erase(x,y);
	s.insert(node(l,r,k));
	ans+=(k)?delta:-delta;
}
int main()
{
	ans=n=read();
	m=read();
	s.insert(node(1,n,1));
	int l,r,k;
	while(m--)
	{
		l=read();
		r=read();
		k=read();
		assign(l,r,k-1);
		write(ans);
	}
	return 0;
}
