/**************************************************************
 * Problem: CF1292B
 * Author: Vanilla_chan
 * Date: 20241028003912
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
RED;                              \
cout << #x << " : " << x << endl; \
RESET;

// 绿色
#define DEBUG2(x)                     \
GREEN;                            \
cout << #x << " : " << x << endl; \
RESET;

// 蓝色
#define DEBUG3(x)                     \
BLUE;                             \
cout << #x << " : " << x << endl; \
RESET;

// 品红
#define DEBUG4(x)                     \
MAGENTA;                          \
cout << #x << " : " << x << endl; \
RESET;

// 青色
#define DEBUG5(x)                     \
CYAN;                             \
cout << #x << " : " << x << endl; \
RESET;

// 黄色
#define DEBUG6(x)                     \
YELLOW;                           \
cout << #x << " : " << x << endl; \
RESET;

#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 110
LL x[N],y[N],a,b,c,d,xs,ys,t;
LL M,MX=1e18;
LL dis(int p1,int p2=-1)
{
	LL x1=x[p1],y1=y[p1],x2,y2;
	if(p2==-1) x2=xs,y2=ys;
	else x2=x[p2],y2=y[p2];
	return std::abs(x1-x2)+std::abs(y1-y2);
}
void solve()
{
	cin>>x[0]>>y[0]>>a>>c>>b>>d>>xs>>ys>>t;
	for(int i=1;;i++)
	{
		x[i]=x[i-1]*a+b;
		y[i]=y[i-1]*c+d;
		if(x[i]-xs+y[i]-ys	>t)
		{
			M=i;
			break;
		}
	}
	int maxans=0;
	for(int s=0;s<=M;s++)
	{
		if(dis(s)<=t) maxans=max(1,maxans);
		for(int e=s+1;e<=M;e++)
		{
			LL need=min(dis(e),dis(s));
			for(int i=s+1;i<=e;i++)
			{
				need+=dis(i,i-1);
			}
			if(need<=t)
			{
				maxans=max(e-s+1,maxans);
			}
//			cout<<s<<" "<<e<<" "<<need<<endl;
		}
		
	}
	cout<<maxans<<endl;
	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
