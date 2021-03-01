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
#define N 110
//bool book[N];
double a[N][N];
int n;
void Guess()
{
	for(int i=1;i<=n;i++)
	{
		//let a[i][i] max
		//find a[mx][i] in [i,n]
		int mx=i;
		for(int j=i+1;j<=n;j++)
		{
			if(fabs(a[j][i])>fabs(a[mx][i])) mx=j;
		}
		//swap(a[i],a[mx])
		for(int j=1;j<=n+1;j++)
		{
			swap(a[i][j],a[mx][j]);
		}
		if(!a[i][i])
		{
			cout<<"No Solution"<<endl;
			exit(0);
		}
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			for(int k=i+1;k<=n+1;k++)
			{
				a[j][k]-=a[i][k]*a[j][i]/a[i][i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%.2lf\n",a[i][n+1]/a[i][i]);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>a[i][j];
		}
	}
	Guess();
	return 0;
}


