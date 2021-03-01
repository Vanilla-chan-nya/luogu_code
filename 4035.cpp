#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
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

/*
IN THE n-D
let O=(x1,x2,x3,...,xn)
then
	

*/
int n;
double a[13][13],b[13][13];
void Guess()
{
	for(int i=1;i<=n;i++)
	{
		int mx=i;
		for(int j=i+1;j<=n;j++)
		{
			if(fabs(b[j][i])>fabs(b[mx][i])) mx=j;
		}
		for(int j=1;j<=n+1;j++)
		{
			swap(b[i][j],b[mx][j]);
		}
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			for(int k=i+1;k<=n+1;k++)
			{
				b[j][k]-=b[i][k]*b[j][i]/b[i][i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%.3lf",b[i][n+1]/b[i][i]);
		if(i!=n) printf(" ");
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		b[i][j]=2*(a[i][j]-a[i+1][j]);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		b[i][n+1]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
	}
	Guess();
	return 0;
}


