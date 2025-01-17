/**************************************************************
 * Problem: 1548
 * Author: Vanilla_chan
 * Date: 20210309
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
int n,m;
IL bool exist(int x,int y)
{
	return x<=n&&y<=m;
}
LL ans;
int main()
{
	n=read();
	m=read();
	{
		ans=0;
		for(int len=1;len<=n;len++)
		{
			for(int x=1;x<=n;x++)
			{
				for(int y=1;y<=m;y++)
				{
					if(exist(x+len-1,y+len-1)) ans++;
					else break;
				}
			}
		}
		cout<<ans<<" ";
	}

	{
		ans=0;
		for(int xx=1;xx<=n;xx++)
		{
			for(int yy=1;yy<=m;yy++)
			{
				if(xx!=yy)
				for(int x=1;x<=n;x++)
				{
					for(int y=1;y<=m;y++)
					{
						if(exist(x+xx-1,y+yy-1)) ans++;
						else break;
					}
				}
			}
		}
		write(ans);
	}
	return 0;
}


