/**************************************************************
 * Problem: 1486
 * Author: Vanilla_chan
 * Date: 20210309
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
#define N 300010
int val[N],ls[N],rs[N],key[N],sze[N];
int root,cnt;
int node(int v)
{
	cnt++;
	val[cnt]=v;
	sze[cnt]=1;
	key[cnt]=rand();
	return cnt;
}
IL void upd(int p)
{
	sze[p]=sze[ls[p]]+sze[rs[p]]+1;
}
void split(int i,int k,int& x,int& y)
{
	if(!i)
	{
		x=y=0;
		return;
	}
	if(val[i]<=k)
	{
		x=i;
		split(rs[i],k,rs[i],y);
	}
	else
	{
		y=i;
		split(ls[i],k,x,ls[i]);
	}
	upd(i);
}
int kth(int k)
{
	int p=root;
	while(1)
	{
		if(k<=sze[ls[p]]) p=ls[p];
		else if(k==sze[ls[p]]+1) return p;
		else k-=sze[ls[p]]+1,p=rs[p];
	}
}
int merge(int x,int y)
{
	if(!x||!y) return x^y;
	if(key[x]<key[y])
	{
		rs[x]=merge(rs[x],y);
		upd(x);
		return x;
	}
	else
	{
		ls[y]=merge(x,ls[y]);
		upd(y);
		return y;
	}
}
void insert(int v)
{
	int x,y;
	split(root,v,x,y);
	root=merge(x,merge(node(v),y));
}

int n,m;
int lazy;
int k;
string op;
int ans;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	m=read();
	while(n--)
	{
		cin>>op>>k;
		if(op[0]=='I')
		{
			if(k>=m) insert(k-lazy);
		}
		else if(op[0]=='A')
		{
			lazy+=k;
		}
		else if(op[0]=='S')
		{
			lazy-=k;
			int x,y;
			split(root,m-lazy-1,x,y);
			root=y;
			ans+=sze[x];
		}
		else
		{
			if(sze[root]<k)
			{
				write(-1);
				continue;
			}
			write(val[kth(sze[root]-k+1)]+lazy);
		}
	}
	write(ans);
	return 0;
}


