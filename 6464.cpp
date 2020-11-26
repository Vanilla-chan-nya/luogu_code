#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<limits.h>
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
int n,m,ans=INT_MAX;
int f[110][110],F[110][110];
IL void init()
{
	for(re int i=1;i<=n;i++)
	for(re int j=1;j<=n;j++)
		f[i][j]=F[i][j];
}
int main()
{
	n=read();m=read();
	for(re int i=1;i<=n;i++)
	for(re int j=1;j<=n;j++)
		F[i][j]=f[i][j]=-1;
	for(re int i=0,a,b,c;i<m;i++)
	{
		a=read();b=read();c=read();
		F[a][b]=F[b][a]=c;
	}
	for(re int k=1;k<=n;k++)
	for(re int i=1;i<=n;i++)
	for(re int j=1;j<=n&&F[i][k]!=-1;j++)
	{
		if(F[k][j]!=-1)
			if(F[i][j]==-1||F[i][j]>F[i][k]+F[k][j]) F[i][j]=F[i][k]+F[k][j];
	}
	for(re int x=1;x<=n;x++)
	for(re int y=1;y<x;y++)
	{
		init();
		f[x][y]=f[y][x]=0;
		for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n&&f[i][x]!=-1;j++)
		{
			if(f[x][j]!=-1)
				if(f[i][j]==-1||f[i][j]>f[i][x]+f[x][j]) f[i][j]=f[i][x]+f[x][j];
		}
		for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n&&f[i][y]!=-1;j++)
		{
			if(f[y][j]!=-1)
				if(f[i][j]==-1||f[i][j]>f[i][y]+f[y][j]) f[i][j]=f[i][y]+f[y][j];
		}
		re int sum=0;
		for(re int i=1;i<=n;i++)
		for(re int j=1;j<i;j++)
		{
			if(f[i][j]!=-1) sum+=f[i][j];
		}
		if(ans>sum) ans=sum;
	}
	cout<<ans;
	return 0;
}

