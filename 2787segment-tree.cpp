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
struct node
{
	int tot[30];
	int l,r;
	bool lazy;
	int k;
	IL node()
	{
		
	}
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define tot(x,y) b[x].tot[y]
	#define lazy(x) b[x].lazy
	#define k(x) b[x].k
}b[50010*4];
char a[50010];
int i,ti;
void upd(int p)
{
	for(ti=0;ti<26;ti++) tot(p,ti)=tot(p<<1,ti)+tot(p<<1|1,ti);
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		if(a[l]<='z'&&a[l]>='a') a[l]+='A'-'a';
		tot(p,a[l]-'A')++;
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}
void spread(int p)
{
	if(lazy(p))
	{
		//memset(b[p].tot,0,sizeof(b[p].tot));
		if(l(p)!=r(p))
		{
			lazy(p<<1)=1,k(p<<1)=k(p);
			memset(b[p<<1].tot,0,sizeof(b[p<<1].tot));
			tot(p<<1,k(p))=r(p<<1)-l(p<<1)+1;
			lazy(p<<1|1)=1,k(p<<1|1)=k(p);
			memset(b[p<<1|1].tot,0,sizeof(b[p<<1|1].tot));
			tot(p<<1|1,k(p))=r(p<<1|1)-l(p<<1|1)+1;
		}
		//upd(p);
		lazy(p)=0;
	}
}
int ans;

void change(int p,int l,int r,int k)
{
	if(l<=l(p)&&r(p)<=r)
	{
		lazy(p)=1;
		k(p)=k;
		memset(b[p].tot,0,sizeof(b[p].tot));
		tot(p,k)=r(p)-l(p)+1;
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) change(p<<1,l,r,k);
	if(r>mid) change(p<<1|1,l,r,k);
	upd(p);
}
int t,x,y;
int k;
void ask_one(int p)
{
//	cout<<"p="<<p<<" lp="<<l(p)<<" rp="<<r(p)<<endl;
	if(x<=l(p)&&r(p)<=y)
	{
		ans+=tot(p,k);
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(x<=mid) ask_one(p<<1);
	if(y>mid) ask_one(p<<1|1);
}
int s[30];
void ask(int p)
{
	if(x<=l(p)&&r(p)<=y)
	{
		for(i=0;i<26;i++) s[i]+=tot(p,i);
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(x<=mid) ask(p<<1);
	if(y>mid) ask(p<<1|1);
}
int n,m;
int main()
{
	//freopen("P2787_12.in","r",stdin);
	//freopen("P2787.out","w",stdout);
	n=read();
	m=read();
	scanf("%s",a+1);
	build(1,1,n);
	while(m--)
	{
		t=read();
		if(t==1)
		{
			x=read();
			y=read();
			k=getchar();
			while(k==' '||k=='\n') k=getchar();
			if(k<='z'&&k>='a') k+='A'-'a';
			k-='A';
			ans=0;ask_one(1);
			write(ans);
		}
		else if(t==2)
		{
			x=read();
			y=read();
			k=getchar();
			while(k==' '||k=='\n') k=getchar();
			if(k<='z'&&k>='a') k+='A'-'a';
			k-='A';
			change(1,x,y,k);
		}
		else
		{
			x=read();
			y=read();
			memset(s,0,sizeof(s));
			ask(1);
			for(i=0;i<26;i++)
			{
				if(s[i])
				{
					change(1,x,x+s[i]-1,i);
					x+=s[i];
				}
			}
		}
	}
	return 0;
}

