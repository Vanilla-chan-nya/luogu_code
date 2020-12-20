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
int head[2000010],nxt[2000010],ver[2000010];
LL cnt,ans,pos;
LL size[1000010],son[1000010],f[1000010];
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	ver[cnt]=y;
	head[x]=cnt;
//	cout<<x<<"to"<<y<<endl;
	nxt[++cnt]=head[y];
	ver[cnt]=x;
	head[y]=cnt;
}
void dfs(int x,int fa)
{
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==fa) continue;
		dfs(ver[i],x);
		size[x]+=size[ver[i]];
		son[x]+=son[ver[i]]+size[ver[i]];
	}
}
void dfs2(int x,int fa)
{
	if(x!=1) f[x]=f[fa]+(n-size[x])-size[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]!=fa) dfs2(ver[i],x);
	}
}
int main()
{
	n=read();
	for(int i=2;i<=n;i++) insert(read(),read());
	dfs(1,0);
	f[1]=son[1];
	dfs2(1,0);
	
	for(int i=1;i<=n;i++) if(f[i]>ans) ans=f[i],pos=i;
	cout<<pos;
	return 0;
}


