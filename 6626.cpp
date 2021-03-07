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
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0'; ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0'; ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10; x/=10; } while(x);
	for(int i=g; i>=1; --i)putchar('0'+G[i]); putchar('\n');
}
int T;
#define N 100010
#define M 400
//graph
int head[N],ver[N<<1],nxt[N<<1],cnt;
IL void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;

	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
}
//ask
struct node
{
	int k,op,nxt;
}a[N];
int top;
int hh[N];
IL void insert(int x,int k,int op)
{
	a[++top].k=k;
	a[top].op=op;
	a[top].nxt=hh[x];
	hh[x]=top;
}
//pre
int dis[N],sze[N],dfn[N],dfncnt,m,n;
int b[N];
void dfs(int x,int f)
{
	dis[x]=dis[f]+1;
	sze[x]=1;
	dfn[x]=++dfncnt;
	b[dfncnt]=dis[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f) continue;
		dfs(ver[i],x);
		sze[x]+=sze[ver[i]];
	}
}
//block
int len,s;
int L[M],R[M],belong[N];
int lazy[M],c[M][N];
void change(int x,int y,int v)
{
	re int xx=belong[x],yy=belong[y],i,j;
	if(xx==yy)
	{
		for(i=L[xx];i<=R[xx];i++)
		{
			c[xx][b[i]]--;
			b[i]+=lazy[xx];
		}
		lazy[xx]=0;
		for(i=x;i<=y;i++)
		{
			b[i]+=v;
		}
		for(i=L[xx];i<=R[xx];i++)
		{
			c[xx][b[i]]++;
		}
	}
	else
	{
		for(i=xx+1;i<=yy-1;i++)
		{
			lazy[i]+=v;
		}
		for(i=L[xx];i<=R[xx];i++)
		{
			c[xx][b[i]]--;
			b[i]+=lazy[xx];
		}
		for(i=L[yy];i<=R[yy];i++)
		{
			c[yy][b[i]]--;
			b[i]+=lazy[yy];
		}
		lazy[xx]=lazy[yy]=0;
		for(i=x;i<=R[xx];i++)
		{
			b[i]+=v;
		}
		for(i=L[yy];i<=y;i++)
		{
			b[i]+=v;
		}
		for(i=L[xx];i<=R[xx];i++)
		{
			c[xx][b[i]]++;
		}
		for(i=L[yy];i<=R[yy];i++)
		{
			c[yy][b[i]]++;
		}
	}
}
int ans[N];
void dfs1(int x,int f)
{
	re int i,j;
	for(i=hh[x];i;i=a[i].nxt)
	{
		for(j=1;j<=s;j++)
		{
			if(a[i].k+1-lazy[j]>=0) ans[a[i].op]+=c[j][a[i].k+1-lazy[j]];
		}
	}
	for(i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f) continue;
		for(j=1;j<=s;j++) lazy[j]++;
		change(dfn[ver[i]],dfn[ver[i]]+sze[ver[i]]-1,-2);
		dfs1(ver[i],x);
		for(j=1;j<=s;j++) lazy[j]--;
		change(dfn[ver[i]],dfn[ver[i]]+sze[ver[i]]-1,2);
	}
}
int main()
{
	T=read();
	int i,j,x,k;
	while(T--)
	{
		//init
		memset(head,0,sizeof(head));cnt=0;
		memset(hh,0,sizeof(hh));top=0;
		dfncnt=0;
		memset(lazy,0,sizeof(lazy));
		memset(ans,0,sizeof(ans));
		//work
		n=read();
		m=read();
		for(i=1;i<n;i++) insert(read(),read());
		dfs(1,0);
		for(i=1;i<=m;i++)
		{
			x=read();
			k=read();
			insert(x,k,i);
		}
		len=sqrt(n);
		s=n/len;
		for(i=1;i<=s;i++)
		{
			L[i]=n/s*(i-1)+1;
			R[i]=n/s*i;
		}
		R[s]=n;
		for(i=1;i<=s;i++)
		{
			for(int j=L[i];j<=R[i];j++)
			{
				belong[j]=i;
			}
		}
		for(i=1;i<=s;i++)
		{
			lazy[i]=0;
			for(int j=L[i];j<=R[i];j++)
			{
				c[i][b[j]]++;
			}
		}
		dfs1(1,0);
		for(i=1;i<=m;i++) cout<<ans[i]<<endl;
		for(i=1;i<=s;i++)
		{
			lazy[i]=0;
			for(j=L[i];j<=R[i];j++)
			{
				c[i][b[j]]=0;
			}
		}
	}

	return 0;
}

