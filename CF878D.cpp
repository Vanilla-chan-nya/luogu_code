/**************************************************************
 * Problem: CF878D
 * Author: Vanilla_chan
 * Date: 20210310
**************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<bitset>
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
	////if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define N 100010
bitset<4096>f[N];
int n,k,q,cnt;
int a[20][100010];
int op,x,y,ans;
int main()
{
	n=read();
	k=read();
	q=read();
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<(1<<k);j++)
		{
			f[i][j]=(j>>(i-1)&1);
		}
	}
	cnt=k;
	while(q--)
	{
		op=read();
		x=read();
		y=read();
		if(op==1)
		{
			f[++cnt]=f[x]|f[y];
		}
		else if(op==2)
		{
			f[++cnt]=f[x]&f[y];
		}
		else
		{
			ans=0;
			for(int i=1;i<=k;i++)
			{
				int s=0;
				for(int j=1;j<=k;j++)
				{
					if(a[j][y]>=a[i][y])
					{
						s|=1<<(j-1);
					}
				}
				if(f[x][s]) ans=max(ans,a[i][y]);
			}
			write(ans);
		}
	}
	return 0;
}


