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
struct Point
{
	double x,y;
	IL void in()
	{
		cin>>x>>y;
	}
}a[100010];
double check(Point a1,Point a2,Point b1,Point b2)
{
	 return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}
double dis(Point i,Point j)
{
	return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
}
IL bool cmp(Point i,Point j)
{
	double temp=check(a[1],i,a[1],j);
	if(temp>0) return 1;//i<j
	if(temp==0&&dis(a[1],i)<dis(a[1],j)) return 1;
	return 0;
}
int n;
int s;
int stac[100010],top;
int main()
{
	n=read();
	s=1;
	for(int i=1;i<=n;i++)
	{
		a[i].in();
		if(a[i].y<a[s].y||(a[i].y==a[s].y&&a[i].x<a[s].x)) s=i;
	}
	swap(a[1],a[s]);
	sort(a+2,a+n+1,cmp);
	stac[++top]=1;
	for(int i=2;i<=n;i++)
	{
		while(top>1&&check(a[stac[top-1]],a[stac[top]],a[stac[top]],a[i])<=0) top--;
		stac[++top]=i;
	}
	stac[++top]=1;
	double ans=0;
	for(int i=1;i<top;i++) ans+=dis(a[stac[i]],a[stac[i+1]]);
	printf("%.2lf",ans);
	return 0;
}


