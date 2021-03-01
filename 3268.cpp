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
inline LL read()
{
	LL x=0,fu=1;
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
#define N 200010
int n,nowx;
LL X[N],Y[N],R[N];
struct Opt
{
	LL pos;
	int x;
	bool insert;
	Opt(LL a=0,int b=0,bool c=0)
	{
		pos=a,x=b,insert=c;
	}
	IL bool operator<(const Opt& z)const
	{
		return pos<z.pos;
	}
};
vector<Opt>opt;
bool dep[N];
#define eps 1e-6
struct O
{
	int x;
	bool up;
	O(int xx=0,bool u=1)
	{
		x=xx,up=u;
	}
	double calc()const
	{
		if(up) return Y[x]+sqrt(R[x]*R[x]-(X[x]-nowx)*(X[x]-nowx))+eps;
		return Y[x]-sqrt(R[x]*R[x]-(X[x]-nowx)*(X[x]-nowx));
	}
	IL bool operator<(const O& z)const
	{
		return calc()<z.calc();
	}
};
set<O>s;
set<O>::iterator it;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		X[i]=read();
		Y[i]=read();
		R[i]=read();
		opt.push_back(Opt(X[i]-R[i],i,1));
		opt.push_back(Opt(X[i]+R[i],i,0));
	}
	sort(opt.begin(),opt.end());
	LL ans=0;
	for(int i=0;i<opt.size();i++)
	{
		nowx=opt[i].pos;
		if(opt[i].insert)
		{
			it=s.insert(O(opt[i].x,1)).first;
			if(it==s.begin())
			{
				dep[opt[i].x]=1;
			}
			else
			{
				it--;
				if(it->up)
				{
					dep[opt[i].x]=dep[it->x];
				}
				else
				{
					dep[opt[i].x]=dep[it->x]^1;
				}
			}
			s.insert(O(opt[i].x,0));
			if(dep[opt[i].x]) ans+=R[opt[i].x]*R[opt[i].x];
			else ans-=R[opt[i].x]*R[opt[i].x];
		}
		else
		{
			s.erase(O(opt[i].x,1));
			s.erase(O(opt[i].x,0));
		}
	}
	write(ans);
	return 0;
}


