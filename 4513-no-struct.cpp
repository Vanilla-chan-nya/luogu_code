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
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define l(x) l[x]
#define r(x) r[x]
#define lm(x) lm[x]
#define rm(x) rm[x]
#define sum(x) sum[x]
#define m(x) m[x]
#define mid ((ll+rr)>>1)
#define Mid ((l(p)+r(p))>>1)
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
	re int x=0,fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int N,M; 
int a[500010];
int l[2000010],r[2000010],sum[2000010],lm[2000010],rm[2000010],m[2000010];
IL void upd(int now)
{
	sum[now]=sum[now<<1]+sum[now<<1|1];
	lm[now]=max(lm[now<<1],sum[now<<1]+lm[now<<1|1]);
	rm[now]=max(rm[now<<1|1],sum[now<<1|1]+rm[now<<1]);
	m[now]=max(max(m[now<<1],m[now<<1|1]),rm[now<<1]+lm[now<<1|1]);
}
void build(int p,int ll,int rr)
{
	l(p)=ll;r(p)=rr;
	if(ll==rr)
	{
		lm(p)=rm(p)=sum(p)=m(p)=a[ll];
		return;
	}
	build(p<<1,ll,mid);
	build(p<<1|1,mid+1,rr);
	upd(p);
}
void change(int p,int x,int k)
{
	if(l(p)==r(p))
	{
		lm(p)=rm(p)=sum(p)=m(p)=a[l(p)]=k;
		return;
	}
	if(x>Mid) change(p<<1|1,x,k);
	else change(p<<1,x,k);
	upd(p);
}
struct node
{
	int lm,rm,m,sum;
}temp;
node ask(int p,int ll,int rr)
{
	if(l(p)==r(p))
	{
		temp.lm=lm(p);
		temp.rm=rm(p);
		temp.sum=sum(p);
		temp.m=m(p);
		return temp;
	};
	if(rr<=Mid) return ask(p<<1,ll,rr);
	else if(ll>Mid) return ask(p<<1|1,ll,rr);
//	upd(now,,);
//	lm[now]=max(lm[now<<1],sum[now<<1]+lm[now<<1|1]);
//	rm[now]=max(rm[now<<1|1],sum[now<<1|1]+rm[now<<1]);
//	m[now]=max(max(m[now<<1],m[now<<1|1]),rm[now<<1]+lm[now<<1|1]);
	node lll=ask(p<<1,ll,Mid),rrr=ask(p<<1|1,Mid+1,rr);
	temp.sum=lll.sum+rrr.sum;
	temp.lm=max(lll.rm,rrr.sum+lll.rm);
	temp.rm=max(rrr.rm,rrr.sum+lll.rm);
	temp.m=max(max(lll.m,rrr.m),lll.rm+rrr.lm);
	return temp;
}
int main()
{
	freopen("P4513_4.in","r",stdin);
	freopen("4513_4.out","w",stdout);
	N=read();M=read();
	for(re int i=1;i<=N;i++)
	{
		a[i]=read();
	}
	re int t,x,y;
	build(1,1,N);
	while(M--)
	{
		t=read();x=read();y=read();
		if(t==1)
		{
			write(ask(1,min(x,y),max(x,y)).m);
		}
		else
		{
			change(1,x,y);
		}
	}
	return 0;
}

