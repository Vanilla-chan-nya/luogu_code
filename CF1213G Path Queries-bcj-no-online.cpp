/**************************************************************
 * Problem: CF1213G Path Queries-bcj-no-online
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
#define N 200010
struct Ask
{
	int id,q;
	bool operator<(const Ask& z)const
	{
		return q<z.q;
	}
}ask[N];
int f[N],sze[N];
LL S;
int getf(int x)
{
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}
LL calc(LL x)
{
	return x*(x-1)/2;
}
void merge(int x,int y)
{
	x=getf(x);
	y=getf(y);
	if(x==y) return;
	S-=calc(sze[x])+calc(sze[y]);
	if(sze[x]<sze[y])
	{
		f[x]=y;
		sze[y]+=sze[x];
		sze[x]=0;
	}
	else
	{
		f[y]=x;
		sze[x]+=sze[y];
		sze[y]=0;
	}
	S+=calc(sze[f[x]]);
	
}
int n,m;
struct edge
{
	int x,y,z;
	bool operator<(const edge& b)const
	{
		return z<b.z;
	}
}e[N];
LL ans[N];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<n;i++)
	{
		e[i].x=read();
		e[i].y=read();
		e[i].z=read();
	}
	sort(e+1,e+n);
	for(int i=1;i<=m;i++)
	{
		ask[i].q=read();
		ask[i].id=i;
	}
	sort(ask+1,ask+m+1);
	for(int i=1;i<=n;i++) f[i]=i,sze[i]=1;
	int top=1;
	for(int i=1;i<=m;i++)
	{
		while(top<n&&e[top].z<=ask[i].q) merge(e[top].x,e[top].y),top++;
		ans[ask[i].id]=S;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}


