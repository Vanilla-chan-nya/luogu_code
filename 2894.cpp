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
int n,m;
struct node{
	int v,l,r,lv,rv,lazy,len;
//	区间内最长空房 从左开始的最长空房  从右开始的最大空房 
	#define v(x) b[x].v
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define lv(x) b[x].lv
	#define rv(x) b[x].rv
	#define len(x) b[x].len
	#define lazy(x) b[x].lazy
}b[210050];
void upd(int p)
{
	if(len(p*2)==v(p*2)) lv(p)=v(p*2)+lv(p*2+1);
	else lv(p)=lv(p*2);
	if(len(p*2+1)==v(p*2+1)) rv(p)=v(p*2+1)+rv(p*2);
	else rv(p)==rv(p*2+1);
	v(p)=max(max(v(p*2),v(p*2+1)),rv(p*2)+lv(p*2+1));
}
void build(int p,int l,int r)
{
	l(p)=l;r(p)=r;
	v(p)=lv(p)=rv(p)=len(p)=r-l+1;
	lazy(p)=0;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}
void spread(int p)
{
	if(lazy(p)==0) return;
	if(lazy(p)==1)
	{
		lazy(p*2)=lazy(p*2+1)=1;
		v(p*2)=lv(p*2)=rv(p*2)=0;
		v(p*2+1)=lv(p*2+1)=rv(p*2+1)=0;
	}
	if(lazy(p)==2)
	{
		lazy(p*2)=lazy(p*2+1)=2;
		v(p*2)=lv(p*2)=rv(p*2)=len(p*2);
		v(p*2+1)=lv(p*2+1)=rv(p*2+1)=len(p*2+1);
	}
	lazy(p)=0;
}
void change(int p,int l,int r,int tag)
{
	spread(p);
//	cout<<"change p="<<p<<" l="<<l<<" r="<<r<<" tag="<<tag<<endl;
	if(l<=l(p)&&r(p)<=r)
	{
		if(tag==1) v(p)=lv(p)=rv(p)=0;
		else v(p)=lv(p)=rv(p)=len(p);
		lazy(p)=tag;
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(p*2,l,r,tag);
	if(r>mid) change(p*2+1,l,r,tag);
	upd(p);
}
int ask(int p,int len)
{
	spread(p);
	if(l(p)==r(p)) return l(p);
	int mid=(l(p)+r(p))/2;
	if(v(p*2)>=len) return ask(p*2,len);
	if(rv(p*2)+lv(p*2+1)>=len) return mid-rv(p*2)+1;
	else return ask(p*2+1,len);
}
int main()
{
	cin>>n>>m;
	int op,x,y,t; 
	build(1,1,n);
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x;
//			cout<<v(1)<<endl;
			if(x<=v(1))
			{
				t=ask(1,x);
				cout<<t<<endl;
				change(1,t,t+x-1,1);
			}
			else cout<<"0\n";
		}
		if(op==2)
		{
			cin>>x>>y;
			change(1,x,x+y-1,2);
		}
		
	}
	return 0;
}

