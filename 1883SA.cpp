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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define debug printf("Now is %d\n",__LINE__)
using namespace std;
int n,tm;
struct F{
	int a,b,c;
	IL void clear()
	{
		a=b=c=0;
	}
	IL void input()
	{
		scanf("%d%d%d",&a,&b,&c);
	}
	IL double calc(double x)
	{
		return (double)a*x*x+(double)b*x+c;
	}
}f[10010];
double calc(double x)
{
	double ans=0;
	for(re int i=0;i<n;i++) ans=max(f[i].calc(x),ans);
	return ans;
}
double minans,x0,T,t;
void SA()
{
	double delta=0,ans=minans,x=x0;
	while(T>1e-18)
	{
		double xx=x+(rand()%100*2-100);
		xx=min(xx,1000);
		xx=max(xx,0);
		delta=calc(xx)-ans;
//		cout<<"delta="<<delta<<endl;
		if(delta<0)
		{
			x=xx;
		}
		else
		{
			if(exp((-delta/T))>rand()) x=xx;
		}
		ans=calc(x);
		T*=t;
	}
	if(ans<minans) minans=ans,x0=x;
}
int main()
{
	scanf("%d",&tm);
	while(tm--)
	{
		scanf("%d",&n);
		for(re int i=0;i<10010;i++) f[i].clear();
		for(re int i=0;i<n;i++) f[i].input();
//		cout<<"a="<<f[i].a<<" b="<<f[i].b<<" c="<<f[i].c<<endl;
		x0=500,minans=calc(x0);
		for(int i=0;i<10;i++) T=0.003,t=0.8,SA();
		printf("%.4lf\n",minans);
	}
	return 0;
}

