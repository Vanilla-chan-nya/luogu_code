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
int n;
#define N 1200010
#define root rs[0]
int f[N],ls[N],rs[N],v[N],num[N],sze[N],cnt;
void upd(int p)
{
	sze[p]=sze[ls[p]]+sze[rs[p]]+num[p];
}
IL bool judge(int p)
{
	return rs[f[p]]==p;
}
void rotate(int x)
{
//	/*
	int y=f[x],z=f[y],b=ls[y]==x?rs[x]:ls[x];//find y,z,b
	f[x]=z,f[y]=x;//fx,fy
	f[b]=y;//fb
	ls[z]==y?ls[z]=x:rs[z]=x;//sz=x
	if(x==ls[y]) rs[x]=y,ls[y]=b;//sx=y,sy=b
	else ls[x]=y,rs[y]=b;
	upd(y),upd(x);
//	*/
	/*
	int k=judge(x),y=f[x],z=f[y];
	if(judge(y)) rs[z]=x;
	else ls[z]=x; 
	f[x]=z;
	if(k) rs[y]=ls[x],ls[x]=y;
	else ls[y]=rs[x],rs[x]=y;
	if(k) ls[x]=y;
	else rs[x]=y;
	f[y]=x;
	upd(y),upd(x);
	*/
}
void splay(int x,int tar=0)
{
	while(f[x]!=tar)
	{
		if(f[f[x]]!=tar)
		{
			if(judge(x)==judge(f[x])) rotate(f[x]);
			else rotate(x);
		}
		rotate(x);
	}
	if(!tar) root=x;
}
int find(int x)
{
	int p=root;
	while(1)
	{
		if(v[p]==x) break;
		
		if(v[p]<x)
		{
			if(rs[p]) p=rs[p];
			else break;
		}
		else
		{
			if(ls[p]) p=ls[p];
			else break;
		}
	}
	splay(p);
	return p;
}
void insert(int x)
{
	if(!root)
	{
		root=++cnt;
		v[cnt]=x;
		num[cnt]=sze[cnt]=1;
		return;
	}
	int p=root,fa;
	while(p&&v[p]!=x)
	{
		fa=p;
		if(v[p]<x) p=rs[p];
		else p=ls[p];
	}
	if(p) sze[p]++,num[p]++;
	else
	{
		p=++cnt;
		if(fa)
		{
			if(x<v[fa]) ls[fa]=p;
			else rs[fa]=p;
		}
		f[p]=fa;
		v[p]=x;
		ls[p]=rs[p]=0;
		sze[p]=num[p]=1;
	}
	splay(p);
}
int prv(int x)
{
	int p=find(x);
	if(v[p]<x) return p;
	p=ls[p];
	while(rs[p]) p=rs[p];
	return p;
}
int nxt(int x)
{
	int p=find(x);
	if(v[p]>x) return p;
	p=rs[p];
	while(ls[p]) p=ls[p];
	return p;
}
void del(int x)
{
	int a=prv(x),b=nxt(x);
	splay(a);
	splay(b,a);
	int p=ls[b];
	if(num[p]>=2) 
	{
		num[p]--,sze[p]--;
		splay(p);
		return;
	}
	ls[b]=0;
	splay(b);
}
int rank(int x)
{
	int p=find(x);
	return sze[ls[p]];
}
int kth(int x)
{
	int p=root;
	while(1)
	{
		if(x<=sze[ls[p]]) p=ls[p];
		else if(x>sze[ls[p]]+num[p]) x-=sze[ls[p]]+num[p],p=rs[p];
		else break;
	}
	splay(p);
	return p;
}
int last,ans;
int main()
{
	n=read();
	insert(-INT_MAX);
	insert(INT_MAX);
	int m=read();
	for(int i=1;i<=n;i++) insert(read());
	for(int i=1,op,x;i<=m;i++)
	{
		op=read();
		x=read();
		x=(x xor last);
		if(op==1)
		{
			insert(x);
		}
		if(op==2)
		{
			del(x);
		}
		if(op<=2) continue;
		if(op==3)
		{
			last=(rank(x));
		}
		if(op==4)
		{
			last=v[kth(x+1)];
		}
		if(op==5)
		{
			last=v[prv(x)];
		}
		if(op==6)
		{
			last=v[nxt(x)];
		}
		if(op>=3) ans=(last xor ans);
	}
	write(ans);
	return 0;
}
