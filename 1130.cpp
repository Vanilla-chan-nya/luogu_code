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
int m,n;
int a[2010][2010];	
int f[2010][2010];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
		cin>>a[i][j]; 
	for(int i=1;i<=m;i++) f[i][1]=a[i][1];
	for(int j=2;j<=n;j++)
	{
		for(int i=1;i<=m;i++)
		{
			f[i][j]=min(f[i][j-1],f[(i-1+n-1)%n+1][j-1]);
			if(i==1) f[i][j]=min(f[i][j-1],f[m][j-1]);
			else f[i][j]=min(f[i][j],f[i-1][j-1]);
			f[i][j]+=a[i][j];
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
	
	int ans=10000000;
	for(int i=1;i<=m;i++) 	ans=min(f[i][n],ans);
	cout<<ans;
	return 0;
}

