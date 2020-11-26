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
#define re register
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

template<class T>inline void read(T&x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    int g=0;
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n;
int head[200010],ver[200010],nxt[200010],w[200010];
int cnt;
void insert(int a,int b,int c)
{
	nxt[++cnt]=head[a];
	head[a]=cnt;
	ver[cnt]=b;
	w[cnt]=c;
	
	nxt[++cnt]=head[b];
	head[b]=cnt;
	ver[cnt]=a;
	w[cnt]=c;
}
//dfs
int f[100010];
void dfs(int x,int now,int fa)
{
	f[x]=now;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==fa) continue;
		dfs(ver[i],now^w[i],x);
	}
}
//trie
int trie[5000010][2];
int trie_cnt;
void insert(int x)
{
	int now=0;
	for(int i=31;i>=0;i--)
	{
		if(!trie[now][(x>>i)&1]) trie[now][(x>>i)&1]=++trie_cnt;
		now=trie[now][(x>>i)&1];
	}
}
int ask(int x)
{
	int now=0,res=0;
	for(int i=31;i>=0;i--)
	{
		bool y=(x>>i)&1;
		if(trie[now][!y]) now=trie[now][!y],res+=1<<i;
		else now=trie[now][y];
	}
	return res;
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
	dfs(1,0,0);
	for(int i=1;i<=n;i++) insert(f[i]);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,ask(f[i]));
	cout<<ans;
	return 0;
}

