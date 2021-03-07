/**************************************************************
 * Problem: P4178 Point divide and rule (Inclusion exclusion principle)
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
int n,m,k;
#define N 40010
int head[N],ver[N<<1],nxt[N<<1],w[N<<1],cnt;
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
int book[N],sze[N],dp[N];
int sum,root;
void getG(int x,int f)
{
	sze[x]=1;
	dp[x]=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f||book[ver[i]]) continue;
		getG(ver[i],x);
		sze[x]+=sze[ver[i]];
		dp[x]=max(dp[x],sze[ver[i]]);
	}
	dp[x]=max(dp[x],sum-sze[x]);
	if(dp[x]<dp[root]) root=x;
}
int dis[N];
int stac[N],top;
void dfs(int x,int f)
{
	stac[++top]=dis[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f||book[ver[i]]) continue;
		dis[ver[i]]=dis[x]+w[i];
		dfs(ver[i],x);
	}
}
int calc(int x,int w)
{
	top=0,dis[x]=w,dfs(x,0);
	sort(stac+1,stac+top+1);
	int l=1,r=top,ans=0;
	while(l<=r)
	{
		if(stac[l]+stac[r]<=k)
		{
			ans+=r-l;
			l++;
		}
		else r--;
	}
	return ans;
}
LL ans;
void solve(int x)
{
	book[x]=1;
	ans+=calc(x,0);
	for(int i=head[x];i;i=nxt[i])
	{
		if(book[ver[i]]) continue;
		ans-=calc(ver[i],w[i]);
		sum=sze[ver[i]];
		dp[root=0]=n;
		getG(ver[i],x);
		solve(root);
	}
}
int main()
{
	n=read();
	for(int i=1,a,b,c;i<n;i++)
	{
		a=read();
		b=read();
		c=read();
		insert(a,b,c);
	}
	k=read();
	dp[root=0]=sum=n;
	getG(1,0);
	solve(root);
	write(ans);
	return 0;
}


