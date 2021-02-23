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
int n;
struct Point
{
	double x,y;
	IL bool operator<(const Point& z)const
	{
		return x==z.x?y<z.y:x<z.x;
	}
}point[200010];
int top;
int stac[200010];
double dis(int x,int y)
{
	return sqrt(fabs((point[x].x-point[y].x)*(point[x].x-point[y].x)+(point[x].y-point[y].y)*(point[x].y-point[y].y)));
}
IL bool cmp(const int& x,const int&y)
{
	return point[x].y<point[y].y;
}
double solve(int l,int r)
{
//	debug cout<<"l="<<l<<" r="<<r<<endl;
	if(l+1==r)
	{
		return dis(l,r);
	}
	if(l+2==r)
	{
		return min(min(dis(l,l+1),dis(l,l+2)),dis(l+1,l+2));
	}
	if(l==r) return 1e5;
	int mid=(l+r)/2;
	double delta=min(solve(l,mid),solve(mid+1,r));
	top=0;
	for(int i=l;i<=r;i++)
	{
		if(point[i].x<=point[mid].x+delta&&point[i].x>=point[mid].x-delta) stac[++top]=i;
	}
	sort(stac+1,stac+top+1,cmp);
	for(int i=1;i<=top;i++)
	{
		for(int j=i+1;j<=top;j++)
		{
			if(point[stac[j]].y-point[stac[i]].y>delta) break;
			delta=min(delta,dis(stac[i],stac[j]));
		}
		
	}
	return delta;
}
int main()
{
//	freopen("P1429_8.in","r",stdin);
	cin>>n;
//	cout<<"n="<<n<<endl;
	for(int i=1;i<=n;i++) cin>>point[i].x>>point[i].y;
	sort(point+1,point+n+1);
	printf("%.4lf",solve(1,n));
	return 0;
}


