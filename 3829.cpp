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
#define LL double
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
#define N 50010
int n;
struct Point
{
	double x,y;
	Point(double xx=0,double yy=0)
	{
		x=xx;y=yy;
	}
	IL void in()
	{
		cin>>x>>y;
	}
}a[N],stac[N];
int top;
IL LL dis(Point i,Point j)
{
	return (i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y);
}
IL LL check(Point a1,Point a2,Point b1,Point b2)
{
	return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}
IL bool cmp(Point i,Point j)
{
	LL temp=check(a[1],i,a[1],j);
	if(temp>0) return 1;
	if(temp==0&&(dis(a[1],i)<dis(a[1],j))) return 1;
	return 0;
}
IL Point rotate(Point a,double t) { // Ðý×ª
    double c = cos(t), s = sin(t);
    return Point(a.x*c-a.y*s,a.x*s+a.y*c);
}
int s;
double aa,bb,rr;
int main()
{
	n=read();
	cin>>aa>>bb>>rr;
	aa-=2*rr;bb-=2*rr;
	double l=sqrt(aa*aa+bb*bb)/2;
	double phi=atan(aa/bb);
	s=1;
	double dx,dy;
	for(int i=1;i<=n;i++)
	{
		double x,y,theta;
		cin>>x>>y>>theta;
		dx=cos(theta+phi)*l;
		dy=sin(theta+phi)*l;
		a[(i-1)*4+1]=Point(x+dx,y+dy);
		a[(i-1)*4+2]=Point(x-dx,y-dy);
		dx=cos(theta-phi)*l;
		dy=sin(theta-phi)*l;
		a[(i-1)*4+3]=Point(x+dx,y+dy);
		a[(i-1)*4+4]=Point(x-dx,y-dy);
	}
	n*=4;
	for(int i=2;i<=n;i++) if(a[i].y<a[s].y||(a[i].y==a[s].y&&a[i].x<a[s].x)) s=i;
	swap(a[s],a[1]);
	sort(a+2,a+n+1,cmp);
	stac[++top]=a[1];
	for(int i=2;i<=n;i++)
	{
		while(top>1&&check(stac[top-1],stac[top],stac[top],a[i])<=0) top--;
		stac[++top]=a[i];
	}
	stac[++top]=a[1];
	double ans=0;
	for(int i=1;i<top;i++) ans+=sqrt(dis(stac[i],stac[i+1]));
	printf("%.2lf",ans+3.141592653589793*2*rr);
	return 0;
}


