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
#define min(a,b) ((a<b)?a:b)
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
#define N 120
#define M 12000
int head[N+10],ver[2*M+10],nxt[2*M+10],f[2*M+10];
int cnt=1;
IL void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	f[cnt]=z;
	
	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
	f[cnt]=0;
}
int n,m,s,t;
LL ans;

int dep[N+10],cur[N+10];
int i;
bool bfs()
{
	queue<int>q;
	memset(dep,0,sizeof(dep));
	dep[s]=1;
	q.push(s);
	int x;
	for(i=1;i<=n;i++) cur[i]=head[i];
	while(!q.empty())
	{
		x=q.front();
		q.pop();
//		debug
		for(i=head[x];i;i=nxt[i])
		{
			if(!f[i]||dep[ver[i]]) continue;
			dep[ver[i]]=dep[x]+1;
			if(ver[i]==t) return 1;
			q.push(ver[i]);
		}
	}
	return 0;
}
LL dinic(int x,int flow)
{
	if(x==t) return flow;
	int res=flow,k;
	for(int i=cur[x];i;i=nxt[i])
	{
		cur[x]=i;
		if(dep[x]+1!=dep[ver[i]]||!f[i]) continue;
		k=dinic(ver[i],min(res,f[i]));
		f[i]-=k;
		f[i^1]+=k;
		res-=k;
		if(!res) break;
	}
	return flow-res;
}
char a,b;
int c;
int main()
{
	m=read();
	n=100;
	s=1;
	t=26;
	for(i=1;i<=m;i++)
	{
		scanf(" %c %c %d",&a,&b,&c);
		insert(a-'A'+1,b-'A'+1,c);
	}
	while(bfs()) ans+=dinic(s,INT_MAX);
	write(ans);
	return 0;
}


