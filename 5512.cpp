/**************************************************************
 * Problem: 5512
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
	if(n>=8)
	{
		if(n==8)
		{
			cout<<"1 2 3 4 7 6 5 14"<<endl;
			cout<<"12 17 20 27 34 25 18 23"<<endl;
			cout<<"11 26 21 32 39 28 61 36"<<endl;
			cout<<"8 15 46 51 58 31 48 35"<<endl;
			cout<<"9 22 57 52 55 42 41 62"<<endl;
			cout<<"10 19 40 49 54 47 56 45"<<endl;
			cout<<"13 24 43 60 53 50 33 64"<<endl;
			cout<<"16 37 30 29 44 59 38 63"<<endl;
		}
		if(n==9)
		{
			cout<<"1 2 3 4 7 6 5 8 9"<<endl;
			cout<<"10 21 20 27 34 25 18 23 38"<<endl;
			cout<<"13 40 33 26 45 28 19 24 35"<<endl;
			cout<<"16 31 76 81 68 69 70 79 72"<<endl;
			cout<<"15 22 51 56 71 80 57 52 37"<<endl;
			cout<<"14 39 62 41 60 47 32 75 64"<<endl;
			cout<<"17 44 65 48 49 54 77 74 63"<<endl;
			cout<<"12 29 42 55 58 73 36 53 50"<<endl;
			cout<<"11 30 67 46 43 66 61 78 59"<<endl;
		}
		if(n==10)
		{
			cout<<"1 2 3 4 7 6 5 8 9 10"<<endl;
			cout<<"12 29 38 33 34 25 36 23 44 27"<<endl;
			cout<<"11 30 59 68 45 28 43 24 35 26"<<endl;
			cout<<"18 41 42 71 56 75 64 37 66 47"<<endl;
			cout<<"13 48 19 60 53 98 93 100 91 90"<<endl;
			cout<<"16 31 40 97 54 83 74 99 82 67"<<endl;
			cout<<"15 22 49 52 55 96 77 80 57 46"<<endl;
			cout<<"14 39 58 79 72 95 62 87 70 61"<<endl;
			cout<<"17 50 51 88 85 78 89 92 81 76"<<endl;
			cout<<"20 21 32 69 94 73 84 65 86 63"<<endl;
		}
		return 0;
	}
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


