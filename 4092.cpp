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

IL void read(char & ch)
{
	ch=getchar();
	while(ch=='\n'||ch==' ') ch=getchar();
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
int n,q;
int black[100010];
int f[100010]; 
char op[100010];
int num[100010];
int head[200010],nxt[200010],ver[200010],fa[100010];
int cnt,sze;
int ans[100010];
IL void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
}
IL int getf(int x)
{
	while(x!=f[x]) f[x]=f[f[x]],x=f[x]; 
	return x;
}
IL void dfs(int x,int father)
{
	fa[x]=father;
	if(black[x])
	{
		f[x]=x;
	}
	else
	{
		f[x]=getf(fa[x]);
	}
	for(re int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==father) continue;
		dfs(ver[i],x);
	}
}
int main()
{
	n=read();
	q=read();
	for(re int i=1;i<=n;i++) f[i]=i;
	black[1]=1;
	for(re int i=1,a,b;i<n;i++)
	{
		a=read();
		b=read();
		insert(a,b);
		insert(b,a);
	}
	for(re int i=1;i<=q;i++)
	{
		read(op[i]);
		num[i]=read();
		if(op[i]=='C')
		{
			black[num[i]]++;
		}
	}
	dfs(1,1);
	while(q)
	{
		if(op[q]=='C') 
		{
			black[num[q]]--;
			if(!black[num[q]]) f[num[q]]=f[fa[num[q]]];
		}
		else
		{
			ans[++sze]=getf(num[q]);
		}
		q--;
	}
	while(sze) write(ans[sze--]);
	return 0;
}

