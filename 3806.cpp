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
#define N 10010
#define M 20010
int n,m;
int head[N],ver[M],nxt[M],w[M];
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
int g;
int mx[N],sze[N];
int S;
void calcS(int x,int f)
{
	S++;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f||book[ver[i]]) continue;
		calcS(ver[i],x);
	}
}
void find(int x,int f)
{
	sze[x]=1;
	mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f||book[ver[i]]) continue;
		find(ver[i],x);
		sze[x]+=sze[ver[i]];
		mx[x]=max(mx[x],sze[ver[i]]);
 	}
 	mx[x]=max(mx[x],S-sze[x]);
 	if(mx[x]<mx[g]||!mx[g]) g=x;
}
void calcG(int x)
{
	S=0;
	g=0;
	calcS(x,0);
	mx[0]=n;
	find(x,0);
}
int ans[10001000];
int d[N],dcnt;
void dfs(int x,int f,int len)
{
	d[++dcnt]=x;
	for(int i=head[x];i;i=nxt[i])
	{
		if(book[ver[i]]||ver[i]==f) continue;
		dfs(ver[i],x,len+w[i]);
	}
}
void calc(int x,int L,int z)
{
	dcnt=0;
	dfs(x,0,L);
	for(int i=1;i<=dcnt;i++)
	{
		for(int j=i+1;j<=dcnt;j++)
		{
			ans[d[i]+d[j]]+=z;
		}
	}
}
void solve(int x)
{
	calcG(x);
	x=g;
	debug cout<<"x="<<x<<endl;
	book[x]=1;
	calc(x,0,1);
	for(int i=head[x];i;i=nxt[i])
	{
		if(book[ver[i]]) continue;
		calc(ver[i],w[i],-1);
	}
	for(int i=head[x];i;i=nxt[i])
	{
		if(book[ver[i]]) continue;
		solve(ver[i]);
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
	solve(1);
	for(int i=1;i<=n;i++)
	{
		cout<<"i="<<ans[i]<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<(ans[read()]?"AYE":"NAY");
		cout<<endl;
	}
	return 0;
}


