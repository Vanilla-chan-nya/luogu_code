#include<iostream>
#include<cstdio>
#include<cmath>
#define IL inline
#define re register
using namespace std;

IL int read()
{
    re int res=0;
    re char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
    return res;
}
struct edge{
	double x,y;
}node[100001];
IL double dis(edge a,edge b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int n;
double ans=1e7;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>node[i].x>>node[i].y;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++) ans=min(ans,dis(node[i],node[j]));
	printf("%.4lf",ans);
	return 0;
}




