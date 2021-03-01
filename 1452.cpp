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
	LL x,y;
	IL void in()
	{
		scanf("%lld%lld",&x,&y);
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
int s;
int main()
{
	n=read();
	s=1;
	for(re int i=1;i<=n;i++)
	{
		a[i].in();
		if(a[i].y<a[s].y||(a[i].y==a[s].y&&a[i].x<a[s].x)) s=i;
	}
	swap(a[s],a[1]);
	sort(a+2,a+n+1,cmp);
	stac[top++]=a[1]; 
	stac[top++]=a[2];
	for(int i=3;i<=n;i++)
	{
		while(top>1&&check(stac[top-2],stac[top-1],stac[top-1],a[i])<=0) top--;
		stac[top++]=a[i];
	}
	stac[top++]=a[1];
	/*
	//check tubao
	//---attention! #define LL double---
	LL ans=0;
	for(int i=0;i<top-1;i++) ans+=sqrt(dis(stac[i],stac[i+1]));
	printf("%.2lf",ans);
	*/
	LL ans=0;
	int q=1;
	for(int i=0;i<top-1;i++)
	{
		while(check(stac[i],stac[i+1],stac[i],stac[(q+1)%top])>check(stac[i],stac[i+1],stac[i],stac[q]))
		{
			q=(q+1)%top;
			ans=max(ans,max(dis(stac[i],stac[q]),dis(stac[i+1],stac[q])));
		}
		ans=max(ans,max(dis(stac[i],stac[q]),dis(stac[i+1],stac[q])));
	}
	write(ans);
	return 0;
}


