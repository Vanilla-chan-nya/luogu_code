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
struct node
{
	LL l,r,sum,mx;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define mx(x) b[x].mx
	#define sum(x) b[x].sum
}b[400010];
int n,m;
LL a[100010];
void upd(int p)
{
	sum(p)=sum(p*2)+sum(p*2+1);
	mx(p)=max(mx(p*2),mx(p*2+1));
}
void build(LL l,LL r,LL p)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		sum(p)=mx(p)=a[l];
		return;
	}
	LL mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	upd(p);
}
void change(int p,int l,int r)
{
	if(mx(p)==1) return;
	if(l(p)==r(p))
	{
		a[l(p)]=mx(p)=sum(p)=sqrt(sum(p));
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(p*2,l,r);
	if(r>mid) change(p*2+1,l,r);
	upd(p);
}
LL ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r(p)<=r) return sum(p);
	LL mid=(l(p)+r(p))>>1;
	LL ans=0;
	if(l<=mid) ans+=ask(l,r,p*2);
	if(r>mid) ans+=ask(l,r,p*2+1);
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	build(1,n,1);
	int op,l,r;
	while(m--)
	{
		cin>>op>>l>>r;
		if(l>r) swap(l,r);
		if(op)
		{
			cout<<ask(l,r,1)<<endl;
		}
		else
		{
			change(1,l,r);
		}
	}
	
	return 0;
}

