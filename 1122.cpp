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

int n,ans;
int f[16010],h[16010];
vector<int>son[16010];
void dfs(int now,int father)
{
	f[now]=h[now];
//	cout<<"dfs "<<now<<endl;
	for(int i=0;i<son[now].size();i++)
	{
		if(son[now][i]!=father){
			dfs(son[now][i],now);
			if(f[son[now][i]]>0) f[now]+=f[son[now][i]];
		}
	}
//	cout<<"f["<<now<<"] = "<<f[now]<<endl;
	ans=max(ans,f[now]);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1,a,b;i<n;i++) cin>>a>>b,son[b].push_back(a),son[a].push_back(b);
//	for(int i=1;i<=n;i++) memset(f,0,sizeof(f)),dfs(i,0);
	dfs(1,0);
	cout<<ans;
	return 0;
}

