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
	int l,r;
	int tot[30];
	bool lazy;
	int k;
	#define l(x) b[x].l
	#define r(x) b[x].r
	#define tot(x,y) b[x].tot[y]
	#define lazy(x) b[x].lazy
	#define k(x) b[x].k
}b[50010*4];
char a[50010];
void upd(int p)
{
	for(int i=0;i<26;i++) tot(p,i)=tot(p<<1,i)+tot(p<<1|1,i);
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
int ask_one(int p,int l,int r,int k)
{
//	cout<<"p="<<p<<" lp="<<l(p)<<" rp="<<r(p)<<endl;
	if(l<=l(p)&&r(p)<=r)
	{
		return tot(p,k);
	}
	spread(p);
	int mid=l(p)+r(p)>>1,ans=0;
	if(l<=mid) ans+=ask_one(p<<1,l,r,k);
	if(r>mid) ans+=ask_one(p<<1|1,l,r,k);
	return ans;
}
int s[30];
void ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		for(int i=0;i<26;i++) s[i]+=tot(p,i);
		return;
	}
	spread(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid) ask(p<<1,l,r);
	if(r>mid) ask(p<<1|1,l,r);
}
int n,m;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	build(1,1,n);
	int t,x,y;
	char k;
	while(m--)
	{
		t=read();
		if(t==1)
		{
			cin>>x>>y>>k;
			if(k<='z'&&k>='a') k+='A'-'a';
			cout<<ask_one(1,x,y,k-'A')<<endl;
		}
		else if(t==2)
		{
			cin>>x>>y>>k;
			if(k<='z'&&k>='a') k+='A'-'a';
			change(1,x,y,k-'A');
		}
		else
		{
			cin>>x>>y;
			memset(s,0,sizeof(s));
			ask(1,x,y);
			for(int i=0;i<26;i++)
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


