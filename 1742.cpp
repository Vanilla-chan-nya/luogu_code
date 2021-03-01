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
}b[100010];
double x,y,r;//r==R^2
IL bool judge(int p)
{
	return (b[p].x-x)*(b[p].x-x)+(b[p].y-y)*(b[p].y-y)<=r+eps;
}


double a[10][10];
void Guess()
{
	int n=2;
	int mx;
	for(int i=1;i<=n;i++)
	{
		mx=i;
		for(int j=i+1;j<=n;j++)
		{
			if(fabs(a[j][i])>fabs(a[mx][i])) mx=j;
		}
		for(int j=1;j<=n+1;j++)
		{
			swap(a[mx][j],a[i][j]);
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
	
}
/*
namespace equ
{
	double a,b,c,d,e,f;
	double px,py;
	void init(double x1,double y1,double x2,double y2,double x3,double y3)
	{
		px=x1;
		py=y1;
		a=x1-x2;
		b=y1-y2;
		c=x2-x3;
		d=y2-y3;
		e=x1*x1-x2*x2-y2*y2+y1*y1;
		f=x2*x2-x3*x3-y3*y3+y2*y2;
	}
	double x()
	{
		return (d*e-b*f)/(b*c-a*d);
	}
	double y()
	{
		return (a*f-c*e)/(b*c-a*d);
	}
	double r()
	{
		return (px-x())*(px-x())+(py-y())*(py-y());
	}
};
*/



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
//	equ(b[1],b[2],b[3]);
//	cout<<"r="<<r<<" x="<<x<<" y="<<y<<endl;
//	srand(20210228+'z'+'y'+'r');
//	srand(20210226);
	srand(2);
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
				/*
				a[1][1]=(b[i].x-b[j].x)*2;
				a[1][2]=(b[i].y-b[j].y)*2;
				a[1][3]=(b[i].x*b[i].x+b[i].y*b[i].y-b[j].x*b[j].x-b[j].y*b[j].y);
				a[2][1]=(b[j].x-b[k].x)*2;
				a[2][2]=(b[j].y-b[k].y)*2;
				a[2][3]=(b[j].x*b[j].x+b[j].y*b[j].y-b[k].x*b[k].x-b[k].y*b[k].y);
				Guess();
				x=a[1][1];
				y=a[2][2];
				r=(x-b[i].x)*(x-b[i].x)+(y-b[i].y)*(y-b[i].y);
				*/
				equ(b[i],b[j],b[k]);
			}
		}
	}
	printf("%.10lf\n%.10lf %.10lf",sqrt(r),x,y);
	return 0;
}


