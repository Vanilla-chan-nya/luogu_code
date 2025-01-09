/**************************************************************
 * Problem: 3369-splay2
 * Author: Vanilla_chan
 * Date: 20210308-20241022
 **************************************************************/
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
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n;
#define N 100010
int f[N],ls[N],rs[N],val[N],cnt[N],sze[N];
int root,tot;
IL void upd(int x)
{
	sze[x]=sze[ls[x]]+sze[rs[x]]+cnt[x];
}
IL int node(int v)
{
	tot++;
	sze[tot]=1;
	cnt[tot]=1;
	val[tot]=v;
	return tot;
}
#define check(x) (rs[f[(x)]]==(x))
void rotate(int x)
{
	int y=f[x],z=f[y],b=ls[y]==x?rs[x]:ls[x];
	f[x]=z,f[y]=x,f[b]=y;
	if(z)
	{
		if(y==ls[z]) ls[z]=x;
		else rs[z]=x;
	}
	if(ls[y]==x) ls[y]=b,rs[x]=y;
	else rs[y]=b,ls[x]=y;
	upd(y),upd(x);
}
void splay(int x,int tar=0)
{
	while(f[x]!=tar)
	{
		if(f[f[x]]!=tar)
		{
			if(check(x)==check(f[x])) rotate(f[x]);
			else rotate(x);
		}
		rotate(x);
	}
	if(tar==0) root=x;
}
int find(int v)
{
	int p=root, last = 0;
	while(p)//
	{
		last = p;
		if(val[p]==v) break;
		if(val[p]<v) p=rs[p];
		else p=ls[p];
	}
	splay(last);
	return last;
}
void insert(int v)
{
	if(!root)
	{
		root=node(v);
		return;
	}
	int p=root,fa=0;
	while(p&&val[p]!=v)
	{
		fa=p;
		if(val[p]>v) p=ls[p];
		else p=rs[p];
	}
	if(p)
	{
		cnt[p]++;
		upd(p);
	}
	else
	{
		p=node(v);
		f[p]=fa;
		if(v<val[fa]) ls[fa]=p;
		else rs[fa]=p;
	}
	splay(p);
}
void del(int v)
{
	int p=find(v);
	if(val[p]!=v) return;
	if(cnt[p]>=2)
	{
		cnt[p]--;
		upd(p);
		return;
	}
	if(!ls[p]&&!rs[p])
	{
		root=0;
		cnt[p]=sze[p]=0;
		return;
	}
	if(!ls[p])
	{
		root=rs[p];
		f[root] = 0;//
		return;
	}
	if(!rs[p])
	{
		root=ls[p];
		f[root] = 0;//
		return;
	}
	//
	int a=ls[p],b=rs[p];
	while(rs[a]) a=rs[a];
	splay(a);
	rs[a]=b;
	f[b]=a;
	root=a;
	f[root] = 0;
	upd(root);
}
int rnk(int v)
{
	return sze[ls[find(v)]]+1;
}
int kth(int k)
{
	int p=root;
	while(1)
	{
		if(sze[ls[p]]>=k) p=ls[p];
		else if(sze[ls[p]]+cnt[p]>=k) break;
		else k-=sze[ls[p]]+cnt[p],p=rs[p];
	}
	splay(p);
	return p;
}
int pre(int v)
{
	int p=find(v);
	p=ls[p];
	while(rs[p]) p=rs[p];
	return p;
}
int nxt(int v)
{
	int p=find(v);
	p=rs[p];
	while(ls[p]) p=ls[p];
	return p;
}
int op,x;
int main()
{
	n=read();
	while(n--)
	{
		op=read();
		x=read();
		if(op==1)
		{
			insert(x);
		}
		else if(op==2)
		{
			del(x);
		}
		else if(op==3)
		{
			write(rnk(x));
		}
		else if(op==4)
		{
			write(val[kth(x)]);
		}
		else if(op==5)
		{
			write(val[pre(x)]);
		}
		else if(op==6)
		{
			write(val[nxt(x)]);
		}
	}
	
	return 0;
}

