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
#define p 1000000007
int i,j,k;
struct matrix
{
	LL a[4][4];
	int x,y;
	matrix()
	{
		memset(a,0,sizeof(a));
		x=3;
		y=3;
	}
	void clear()
	{
		*this=matrix();
	}
	matrix operator+(matrix z)
	{
		matrix now=*this;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				now.a[i][j]+=z.a[i][j];
			}
		}
		return now;
	}
	matrix operator+=(matrix z)
	{
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				a[i][j]+=z.a[i][j];
			}
		}
		return *this;
	}
	matrix operator*(matrix z)
	{
		matrix now;
//		re int i,j,k;
		for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)//here,we just calc kinds of size of [3*3]*[3*3]
		{
			for(k=1;k<=3;k++)
			{
				now.a[i][j]+=a[i][k]*z.a[k][j];
				now.a[i][j]%=p;
			}
		}
		return now;
	}
	matrix operator*=(matrix z)
	{
		*this=*this*z;
		return *this;
	}
}ans,a,s;
int t;
int n;
//int a[12]={1,2,3}
int main()
{
	t=read();
	s.x=3,s.y=1;
	s.a[1][1]=s.a[2][1]=s.a[3][1]=1;
	re int i,j,k;
	while(t--)
	{
		n=read()-1;
		ans.clear();
		a.clear();
		a.x=a.y=ans.x=ans.y=3;
		ans.a[1][1]=ans.a[2][2]=ans.a[3][4]=1;
		a.a[1][2]=a.a[2][3]=a.a[3][1]=a.a[3][3]=1;
		while(n)
		{
			if(n&1) ans*=a;
			a*=a;
			n>>=1;
		}
		a.clear();
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=1;j++)
			{
				for(k=1;k<=3;k++)
				{
					a.a[i][j]+=ans.a[i][k]*s.a[k][j];
					a.a[i][j]%=p;
				}
			}
		}
		write(a.a[1][1]);
	}
	
	return 0;
}


