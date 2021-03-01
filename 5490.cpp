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
LL rys[400010];
map<LL,int>ys;
map<LL,int>::iterator it;
namespace pre
{
	struct Line
	{
		LL x1,y1,x2,y2;
		IL void in()
		{
			cin>>x1>>y1>>x2>>y2;
			::ys[x1]=0;
			::ys[x2]=0;
		}
	}line[100010];
};
struct Line
{
	LL x1,x2,y,v;
	Line(LL a=0,LL b=0,LL c=0,LL d=0)
	{
		x1=a,x2=b,y=c,v=d;
	}
	IL bool operator<(const Line& z)const
	{
		return y<z.y;
	}
}line[200010];
int n;
struct node
{
	int l,r,v;
	LL len;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define v(x) b[x].v
	#define len(x) b[x].len
}b[1600010];
void upd(int p)
{
	if(v(p)) len(p)=rys[r(p)+1]-rys[l(p)];
	else len(p)=len(p<<1)+len(p<<1|1);
}
void build(int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if(l==r) return;
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void change(int p,int l,int r,int w)
{
//	debug cout<<"p="<<p<<" l="<<l(p)<<" r="<<r(p)<<endl;
	if(rys[r(p)+1]<=l||r<=rys[l(p)]) return;
	if(l<=rys[l(p)]&&rys[r(p)+1]<=r)
	{
		v(p)+=w;
		upd(p);
		return;
	}
	change(p<<1,l,r,w);
	change(p<<1|1,l,r,w);
	upd(p);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		pre::line[i].in();
		line[i*2]=Line(pre::line[i].x1,pre::line[i].x2,pre::line[i].y1,1);
		line[i*2-1]=Line(pre::line[i].x1,pre::line[i].x2,pre::line[i].y2,-1);
	}
	n<<=1;
	int rank=1;
	for(it=ys.begin();it!=ys.end();rank++,it++)
	{
		it->second=rank;
		rys[rank]=it->first;
	}
	build(1,1,ys.size()-1);
	sort(line+1,line+n+1);
	LL ans=0;
	for(int i=1;i<n;i++)
	{
//		debug cout<<"i="<<i<<" y="<<line[i].y<<endl;
		change(1,line[i].x1,line[i].x2,line[i].v);
		ans+=len(1)*(line[i+1].y-line[i].y);
	}
	write(ans);
	return 0;
}


