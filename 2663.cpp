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
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,ans,sum;
int a[110];
bool had[200000000];
int memory[200000000];
IL int calc(int x,int y,int z)
{
	return x*1000000+y*100+z;
}
int dfs(int depth,int k,int num)
{
	if(num==n/2) return k;
	if(n-depth+num+1<n/2) return 0;
	if(had[calc(depth,k,num)]) return memory[calc(depth,k,num)];
	if(depth==n+1) return 0;
	int mx=-1000;
	if(k+a[depth]<=sum/2) mx=dfs(depth+1,k+a[depth],num+1);
	mx=max(mx,dfs(depth+1,k,num));
	had[calc(depth,k,num)]=1;
	return memory[calc(depth,k,num)]=mx;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	cout<<dfs(1,0,0);
	return 0;
}

