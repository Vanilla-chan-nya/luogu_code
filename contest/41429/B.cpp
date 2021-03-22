/**************************************************************
 * Problem:
 * Author: Vanilla_chan
 * Date:
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
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
#define N 200000
LL t,n,m;
LL a[N],b[2][N];
bool pre;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	t=read();
	n=1;
	for(int i=1;i<=t;i++) n*=2;
	m=read();
	
	for(int i=1,op,x;i<=m;i++)
	{
		op=read();
		x=read();
		if(op==1)
		{
			if(!pre)
			{
				for(LL i=0;i<n;i++) a[i]=i;
				pre=1;
			}
			for(int j=0;j<n;j++)
			{
				b[x^(j&1)][j>>1]=a[j];
			}
			for(int j=0;j<n/2;j++)
			{
				a[j]=b[0][j];
			}
			for(int j=0;j<n/2;j++)
			{
				a[j+n/2]=b[1][j];
			}
		}
		else
		{
			if(!pre)
			{
				write(x);
			}
			else
			{
				write(a[x]);
			}
		}
	}
	return 0;
}



