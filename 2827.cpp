/**************************************************************
 * Problem: 2827
 * Author: Vanilla_chan
 * Date: 20210315
**************************************************************/
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

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define N 12000010
LL n,m,q,u,v,t;
LL a[4][N];
int l[4],r[4];
IL bool cmp(const LL x,const LL y)
{
	return x>y;
}
int tmp[N];
int cnt;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>q>>u>>v>>t;
	for(int i=1;i<=3;i++) l[i]=1,r[i]=0;
	for(int i=1;i<=n;i++) a[1][i]=read();
	r[1]=n;
	sort(a[1]+1,a[1]+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		LL len=-100000000000ll,num=1;
		for(int j=1;j<=3;j++)
		{
			if(r[j]>=l[j]&&a[j][l[j]]>len) len=a[j][l[j]],num=j;
		}
		len+=(i-1)*q;
		l[num]++;
		int x=len*u/v,y=len-x;
		if(x<y) swap(x,y);
		a[2][++r[2]]=x-i*q;
		a[3][++r[3]]=y-i*q;
		if(i%t==0) cout<<len<<" ";
	}
	cout<<endl;
	for(int j=1;j<=3;j++)
	{
		for(int i=l[j];i<=r[j];i++) tmp[++cnt]=a[j][i];
	}
	sort(tmp+1,tmp+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(i%t==0) cout<<tmp[i]+q*m<<" ";
	}
	return 0;
}


