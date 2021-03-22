/**************************************************************
 * Problem: 1549
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
#define M 210
#define N 20
int n;
bool book[M];
int prime[M][M];
void init()
{
	book[1]=1;
	for(int i=2;i<=200;i++)
	{
		if(!book[i])
		{
			for(int j=2;i*j<=200;j++)
			{
				book[i*j]=1;
			}
		}
	}
	for(int i=1;i<=n*n;i++)
		for(int j=1;j<=n*n;j++)
			prime[i][j]=book[i+j];
}
int ans;
int ANS[N][N];
int now[N][N];
bool vis[M];
int dt[4][2]={0,1,0,-1,1,0,-1,0};
IL bool exist(int x)
{
	return x>=1&&x<=n;
}
bool check(int x,int y)
{
	for(int t=0;t<4;t++)
	{
		if(exist(x+dt[t][0])&&exist(y+dt[t][1]))
		{
			if(now[x+dt[t][0]][y+dt[t][1]]!=0)
			{
				if(prime[now[x][y]][now[x+dt[t][0]][y+dt[t][1]]])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
void dfs3(int x,int y,int sum)
{
	if(sum>=ans) return;
	if(y==n+1) y=2,x++;
	if(x==n+1)
	{
		ans=sum;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ANS[i][j]=now[i][j];
			}
		}
		return;
	}
	for(int i=n*n;i>=1;i--)
	{
		if(vis[i]) continue;
		vis[i]=1;
		now[x][y]=i;
		if(check(x,y)) dfs3(x,y+1,sum);
		vis[i]=0;
		now[x][y]=0;
	}
}
void dfs2(int y,int sum)
{
	if(sum>=ans) return;
	if(y==n+1)
	{
		dfs3(2,2,sum);
		return;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		now[1][y]=i;
		if(check(1,y)) dfs2(y+1,sum+i);
		now[1][y]=0;
		vis[i]=0;
	}
}
void dfs1(int x,int sum)
{
	if(sum>=ans) return;
	if(x==n+1)
	{
		dfs2(2,sum);
		return;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		now[x][1]=i;
		if(check(x,1)) dfs1(x+1,sum+i);
		vis[i]=0;
		now[x][1]=0;
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	init();
	now[1][1]=1;
	vis[1]=1;
	ans=100000;
	dfs1(2,0);
	if(ans==100000) cout<<"NO"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<ANS[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}


