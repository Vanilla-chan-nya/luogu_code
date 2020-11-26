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
int n,m,e,ans;
vector<int>L[5001];
int match[5001],vis[5001];
bool dfs(int x,int tag)
{
	if(vis[x]==tag) return false;
	vis[x]=tag;
	for(int i=0;i<L[x].size();i++)
	{
		if(match[L[x][i]]==0||dfs(match[L[x][i]],tag))
		{
			match[L[x][i]]=x;
			return true;
		}
	}
	return false;
}
int main()
{
	n=read();
	m=read();
	e=read();
	for(int i=1,t;i<=e;i++) t=read(),L[t].push_back(read());
	for(int i=1;i<=n;i++)
	{
		if(dfs(i,i)) ans++;
	}
	cout<<ans;
	return 0;
}

