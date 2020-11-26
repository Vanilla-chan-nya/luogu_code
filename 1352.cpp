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
using namespace std;

template<class T>inline void read(T&x)
{
	int fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-') fu=-1,ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=fu;
}
inline int read()
{
	int x=0,fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}

int n;
int f[6010][2],h[6010],fa[6010];
vector<int>son[6010];
void dfs(int now)
{
//	cout<<"dfs "<<now<<endl;
	for(int i=0;i<son[now].size();i++)
	{
		dfs(son[now][i]);
	}
//	cout<<"rec "<<now<<endl;
	if(son[now].size()==0)
	{
		f[now][0]=0;
		f[now][1]=h[now];
		return;
	}
	f[now][0]=0;
	for(int i=0;i<son[now].size();i++)
	{
		f[now][0]+=max(f[son[now][i]][0],f[son[now][i]][1]);
	}
	f[now][1]=0;
	for(int i=0;i<son[now].size();i++)
	{
		f[now][1]+=f[son[now][i]][0];
	}
	f[now][1]+=h[now];
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) h[i]=read();
	for(int i=1,a,b;i<n;i++) a=read(),b=read(),fa[a]=b,son[b].push_back(a);
	for(int i=1;i<=n;i++) if(fa[i]==0) dfs(i),cout<<max(f[i][0],f[i][1]);
	return 0;
}

