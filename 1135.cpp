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
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int k[210];
int n,a,b,minans;
int dis[210];
void dfs(int depth,int ans) 
{
	if(depth<1||depth>200) return;
	if(ans>minans) return;
	if(dis[depth]<ans) return;
	else dis[depth]=ans;
	if(depth==b){
		minans=min(minans,ans);
		return;
	}
	dfs(depth+k[depth],ans+1);
	dfs(depth-k[depth],ans+1);
}
int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++) cin>>k[i];
	memset(dis,0x3f,sizeof(dis));
	minans=10000000;
	dfs(a,0);
	if(minans>5000000) cout<<-1;
	else cout<<minans;
	return 0;
}

