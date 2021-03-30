#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define LL __int128
IL bool isnum(char ch)
{
	return ch>='0'&&ch<='9';
}
IL int read()
{
	char ch=getchar();
	int x=0,fu=1;
	while(!isnum(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	while(isnum(ch)) x=(x<<1)+(x<<3)+(ch-48),ch=getchar();
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);
}
/*
 * array size
 * freopen
 * re try
 */
LL gcd(LL x,LL y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
struct node
{
	LL x,y;// x/y
	node(LL xx=0,LL yy=1)
	{
		x=xx;
		y=yy;
	}
	node easy()
	{
		LL z=gcd(x,y);
		x/=z;
		y/=z;
		return *this;
	}
	void clear()
	{
		x=0;
		y=1;
	}
	node operator+(node z)
	{
		if(y==z.y)
		{
			return node(x+(z.x),y).easy();
		}
		return node(x*(z.y)+(z.x)*y,y*(z.y)).easy();
	}
	node operator+=(node z)
	{
		*this=(*this)+z;
		return *this;
	}
	node operator*(node z)
	{
		node ans=z;
		ans.x*=x;
		ans.y*=y;
		return ans.easy();
	}
	node operator*=(node z)
	{
		*this=(*this)*z;
		return (*this).easy();
	}
	node operator/(node z)
	{
		return ((*this)*node(z.y,z.x)).easy();
	}
}a[100010];
int head[100010],ver[1000010],nxt[1000010],degree[100010];
int cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	degree[x]++;
}
int n,m,x;
queue<int>q;
bool online[100010];
int main()
{
	//freopen("water.in","r",stdin);
	//freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++) a[i]=1,q.push(i),online[i]=1;
	for(int i=1,j;i<=n;i++)
	{
		j=read();
		while(j--)
		{
			insert(i,read());
		}
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		online[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
			a[ver[i]]+=(a[x]/degree[x]);
			if(!online[ver[i]]) q.push(ver[i]),online[ver[i]]=1;
		}
		if(degree[x]) a[x].clear();
	}
	for(int i=1;i<=n;i++)
	{
		if(!degree[i])
		{
			a[i].easy();
		write(a[i].x);
		putchar(' ');
		write(a[i].y);
		putchar('\n');
		}
	}
	return 0;
}
