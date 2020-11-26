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
inline LL read()
{
	LL x=0;
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
LL t;
LL n,m,a[2000010];
LL head[4000010],nxt[4000010],ver[4000010];
LL cnt;
IL void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
}
struct node
{
	int l,r,mx,lmax;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define mx(x) b[x].mx
	#define lmax(x) b[x].lmax
}b[2000010];
IL void pre()
{
	memset(head,0,sizeof(head));
	memset(a,0,sizeof(a));
	memset(nxt,0,sizeof(nxt));
	memset(ver,0,sizeof(ver));
}
IL void upd(int p)
{
	if(mx(p<<1)>=mx(p<<1|1))
	{
		mx(p)=mx(p<<1);
		lmax(p)=lmax(p<<1);
	}
	else
	{
		mx(p)=mx(p<<1|1);
		lmax(p)=lmax(p<<1|1);
	}
}
void build(int l,int r,int p)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		mx(p)=a[l];
		lmax(p)=l;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	upd(p);
}
void change(int p,int x)
{
	if(l(p)==r(p))
	{
		mx(p)++;
		return;
	}
	int mid=l(p)+r(p)>>1;
	if(x<=mid) change(p<<1,x);
	else change(p<<1|1,x);
	upd(p);
}
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		pre();
		for(re int i=1;i<=n;i++) read(a[i]);
		for(re int i=1,x,y;i<n;i++)
		{
			x=read();
			y=read();
			insert(x,y);
			insert(y,x);
		}
		build(1,n,1);
		for(re int i=1;i<=m;i++)
		{
			for(re int j=head[b[1].lmax];j;j=nxt[j])
			{
				change(1,ver[j]);
			}
		}
		cout<<b[1].lmax<<endl;
	}
	return 0;
}

