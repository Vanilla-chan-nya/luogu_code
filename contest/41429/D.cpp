/**************************************************************
 * Problem:
 * Author: Vanilla_chan
 * Date:
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
#define N 30
int ans;
#define p 998244353
int n;
int a[N],b[N],c[N];
bool book[N],had[N];
bool check()
{
	memset(c,0,sizeof(c));
	for(int l=0;l<n;l++)
	{
		for(int r=l;r<n;r++)
		{
			memset(had,0,sizeof(had));
			for(int i=l;i<=r;i++) had[a[i]]=1;
			int mex=0;
			for(int i=0;i<n;i++)
			{
				if(had[i]==0)
				{
					mex=i;
					break;
				}
			}
			c[mex]++;
		}
	}
//	for(int i=0;i<n;i++) cout<<c[i]<<" ";
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(c[i]!=b[i]) return 0;
	}
	return 1;
}
void dfs(int x)
{
	if(x==n)
	{
//		cout<<"now=";
//		for(int i=0;i<n;i++) cout<<a[i]<<" ";
//		cout<<endl;
		if(check())
		{
			ans++;
			if(ans>=p) ans-=p;
		}
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(book[i]) continue;
		book[i]=1;
		a[x]=i;
		dfs(x+1);
		book[i]=0;
		a[x]=0;
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=0;i<n;i++)
	{
		b[i]=read();
	}
	b[0]++;
	dfs(0);
	write(ans);
	return 0;
}



