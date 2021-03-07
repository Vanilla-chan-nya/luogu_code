/**************************************************************
 * Problem: P3806
 * Author: Vanilla_chan
 * Date: 20210305
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
int n,m,query[200];
bool exist[200];
#define N 10010
int head[N],ver[N<<1],nxt[N<<1],w[N<<1];
int cnt;
void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	w[cnt]=z;

	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
	w[cnt]=z;
}
bool book[N];
int root,sum;
int sze[N],dp[N];
void calcG(int x,int f)
{
	sze[x]=1;
	dp[x]=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f||book[ver[i]]) continue;
		calcG(ver[i],x);
		sze[x]+=sze[ver[i]];
		dp[x]=max(dp[x],sze[ver[i]]);
	}
	dp[x]=max(dp[x],sum-sze[x]);
	if(dp[x]<dp[root]) root=x;
}
int stac[N],top;
int dis[N];
void dfs(int x,int f)
{
	stac[++top]=dis[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f||book[ver[i]]) continue;
		dis[ver[i]]=dis[x]+w[i];
		if(dis[ver[i]]<=10000000)dfs(ver[i],x);
	}
}
int change[N],p;
bool judge[10000010];
void calc(int x)
{
	p=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(book[ver[i]]) continue;
		top=0;
		dis[ver[i]]=w[i];
		dfs(ver[i],x);

		for(int j=top;j>0;j--)
		{
			for(int k=1;k<=m;k++)
			{
				if(query[k]>=stac[j]&&query[k]-stac[j]<=10000000)
				{
					exist[k]|=judge[query[k]-stac[j]];
				}
			}
		}
		for(int j=top;j>0;j--)
		{
			change[++p]=stac[j];
			judge[stac[j]]=1;
		}
	}
	for(int i=1;i<=p;i++) judge[change[i]]=0;
}
void solve(int x)
{
	book[x]=1;
	judge[0]=1;
	calc(x);
	for(int i=head[x];i;i=nxt[i])
	{
		if(book[ver[i]]) continue;
		sum=sze[ver[i]];
		dp[root=0]=10000000;
		calcG(ver[i],0);
		solve(root);
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1,a,b,c;i<n;i++)
	{
		a=read();
		b=read();
		c=read();
		insert(a,b,c);
	}
	for(int i=1;i<=m;i++) query[i]=read();
	dp[root=0]=sum=n;
	calcG(1,0);
	solve(root);
	for(int i=1;i<=m;i++)
	{
		if(exist[i]) cout<<"AYE"<<endl;
		else cout<<"NAY"<<endl;
	}
	
	return 0;
}


