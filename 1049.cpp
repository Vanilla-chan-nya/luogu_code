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
int n,V,minans;
int sum[40],v[40];
void dfs(int least,int depth)
{
	if(depth>=n){
		if(least<minans) minans=least;
		return;
	}
//	if(least-v[depth]<0){
//		if(least<minans) minans=least;
//		return;
//	}不知道为什么WA了 
	if(least-v[depth]>=0) dfs(least-v[depth],depth+1);
	dfs(least,depth+1);
	
}
IL bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	V=read();
	n=read();
	for(int i=0;i<n;i++) v[i]=read();
	minans=V+1;
	sort(v,v+n,cmp);
	dfs(V,0);
	cout<<minans;
	return 0;
}

