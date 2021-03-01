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
#define eps 1e-6
int n;
struct Point
{
	double x,y;
	IL void in()
	{
		cin>>x>>y;
	}
}b[1000010];
double x,y,r;
IL bool judge(int p)
{
	return (b[p].x-x)*(b[p].x-x)+(b[p].y-y)*(b[p].y-y)<=r+eps;
}


void equ(Point i,Point j,Point k)
{
	double a1,a2,b1,b2,c1,c2;
	a1=j.x-i.x;a1*=2;
	a2=k.x-i.x;a2*=2;
	b1=j.y-i.y;b1*=2;
	b2=k.y-i.y;b2*=2;
	c1=(j.x*j.x-i.x*i.x+j.y*j.y-i.y*i.y);
	c2=(k.x*k.x-i.x*i.x+k.y*k.y-i.y*i.y);
	x=(b2*c1-b1*c2)/(b2*a1-b1*a2);
	y=(a2*c1-a1*c2)/(a2*b1-a1*b2);
	r=(x-i.x)*(x-i.x)+(y-i.y)*(y-i.y);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		b[i].in();
	}
//	srand(20210228+'z'+'y'+'r');
	srand(20210226);
	random_shuffle(b+1,b+1+n);
	x=b[1].x;y=b[1].y;r=0;
	for(int i=2;i<=n;i++)
	{
		if(judge(i)) continue;
		r=0,x=b[i].x,y=b[i].y;
		for(int j=1;j<=i-1;j++)
		{
			if(i==j||judge(j)) continue;
			x=(b[i].x+b[j].x)/2;
			y=(b[i].y+b[j].y)/2;
			r=(x-b[j].x)*(x-b[j].x)+(y-b[j].y)*(y-b[j].y);
			for(int k=1;k<=j-1;k++)
			{
				if(i==k||j==k||judge(k)) continue;
				equ(b[i],b[j],b[k]);
			}
		}
	}
	printf("%.2lf %.2lf %.2lf",x,y,sqrt(r));
	return 0;
}


