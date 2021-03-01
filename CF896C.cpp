#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define int long long
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
#define N 100010
LL seed,vmax;
int rnd()
{
	int ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
int n,m;
struct node
{
	int l,r;
	mutable LL v;
	node(int ll,int rr=-1,LL vv=0)
	{
		l=ll;
		r=rr;
		v=vv;
	}
	IL bool operator<(const node& z)const
	{
		return l<z.l;
	}
};
#define s Chtholly
set<node>Chtholly;
#define IT set<node>::iterator
IT split(int x)
{
	node tmp={x};
	IT it=s.lower_bound(tmp);
	if(it!=s.end()&&it->l==x) return it;
	it--;
	LL l=it->l,r=it->r,v=it->v;
	s.erase(it);
	s.insert(node(l,x-1,v));
	return s.insert(node(x,r,v)).first;
}
void add(int l,int r,LL x)
{
	IT itr=split(r+1);
	IT itl=split(l);
	for(;itl!=itr;itl++)
	{
		itl->v+=x;
	}
}
void assign(int l,int r,LL x)
{
	IT itr=split(r+1);
	IT itl=split(l);
	s.erase(itl,itr);
	s.insert(node(l,r,x));
}
vector<pair<LL,LL> >vec;
int k_th(int l,int r,int k)
{
	vec.clear();
	IT itr=split(r+1);
	IT itl=split(l);
	for(;itl!=itr;itl++)
	{
		vec.push_back(make_pair(itl->v,itl->r-itl->l+1));
	}
	sort(vec.begin(),vec.end());
	for(LL i=0;i<vec.size();i++)
	{
		k-=vec[i].second;
		if(k<=0) return vec[i].first;
	}
	return -2147483647;
}
LL qpow(LL a,LL b,LL p)
{
	LL ans=1;
	a%=p;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans%p;
}
LL powsum(int l,int r,LL x,LL y)
{
	LL ans=0;
	IT itr=split(r+1);
	IT itl=split(l);
	for(;itl!=itr;itl++)
	{
		ans+=qpow(itl->v,x,y)*(itl->r-itl->l+1);
		ans%=y;
	}
	return ans;
}
LL a[N];
signed main()
{
	n=read();
	m=read();
	seed=read();
	vmax=read();
	for(LL i=1;i<=n;i++)
	{
		a[i]=rnd()%vmax+1;
		s.insert(node(i,i,a[i]));
	}
	LL op,l,r,x,y;
	for(LL i=1;i<=m;i++)
	{
		op=(rnd()%4)+1;
		l=rnd()%n+1;
		r=rnd()%n+1;
		if(l>r) swap(l,r);
//		cout<<"op="<<op<<" l="<<l<<" r="<<r<<endl;
		if(op==3) x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if(op==4) y=rnd()%vmax+1;
		
		if(op==1)
		{
			add(l,r,x);
		}
		if(op==2)
		{
//			cout<<" x="<<x<<endl;
			assign(l,r,x);
		}
		if(op==3)
		{
			write(k_th(l,r,x));
		}
		if(op==4)
		{
			write(powsum(l,r,x,y));
		}
//		for(IT it=s.begin();it!=s.end();it++)
//		{
//			cout<<"l="<<it->l<<" r="<<it->r<<" v="<<it->v<<endl;
//		}
	}
	return 0;
}


