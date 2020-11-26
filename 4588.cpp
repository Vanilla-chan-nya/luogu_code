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
struct node{
	LL l,r,v=1;
	node(){
		l=0,r=0,v=1;
//		write(__LINE__);
	}
	void clear()
	{
		node();
	}
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define v(x) b[x].v
}b[400010];
LL t,n,mod;
void upd(LL p)
{
	v(p)=v(p*2)*v(p*2|1)%mod;
}
void build(LL l,LL r,LL p)
{
//	cout<<"building "<<p<<" "<<l<<" "<<r<<endl;
	l(p)=l,r(p)=r;
	if(l==r) return;
	LL mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2|1);
}
void change(LL p,LL x,LL k)
{
	if(l(p)==r(p))
	{
		v(p)=k%mod;
		return;
	}
	LL mid=(l(p)+r(p))>>1;
	if(x>mid) change(p*2|1,x,k);
	else change(p*2,x,k);
	upd(p);
}
LL ask(LL p,LL l,LL r)
{
	if(l<=l(p)&&r>=r(p)) return v(p);
	LL mid=(l(p)+r(p))>>1;
	if(r<=mid) return ask(p*2,l,r);
	if(l>mid) return ask(p*2+1,l,r);
	return ask(p*2,l,mid)*ask(p*2+1,mid+1,r)%mod;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>mod;
		for(LL i=0;i<400010;i++) b[i].clear();
		build(1,n,1);
		for(LL i=1,a,b;i<=n;i++)
		{
			cin>>a>>b;
			if(a==1)
			{
				change(1,i,b);
				cout<<ask(1,1,i)<<endl;
			}
			else
			{
				change(1,b,1);
				cout<<ask(1,1,i)<<endl;
			}
		}
	}
	return 0;
}

