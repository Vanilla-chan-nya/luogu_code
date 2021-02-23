#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
#define N 100000
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
int n;
int head[200010],ver[200010],nxt[200010],f[200010];
int cnt=1;
void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	f[cnt]=z;
	ver[cnt]=y;
	
	nxt[++cnt]=head[y];
	head[y]=cnt;
	f[cnt]=0;
	ver[cnt]=x;
}

int s=200004,t=200005;

int dep[200010],cur[200010];
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
//		debug
	}
	return flow-res;
}
LL k;
int main()
{
	n=read();
	for(int ans=1;;ans++)
	{
		for(int i=1,res;i<ans;i++)
		{
			res=(int)sqrt(i+ans);
			if(res*res==i+ans)
			{
				insert(i,ans+N,1);
			}
		}
		insert(s,ans,1);
		insert(ans+N,t,1);
		while(bfs()) k+=dinic(s,INT_MAX);
		if(ans-k>n)
		{
			write(ans-1);
			return 0;
		}
	}
	return 0;
}


