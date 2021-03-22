/**************************************************************
 * Problem: SP13980
 * Author: Vanilla_chan
 * Date: 20210313
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
IL int belong(int x,int y)
{
	return x/3*3+y/3;
}
int book[3][9];
int ans;
int Ans[9][9],now[9][9];
void dfs(int x,int y)
{
	//debug cout<<"x="<<x<<" y="<<y<<endl;
	if(y==9) x++,y=0;
	if(x==9)
	{
		if(!ans)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					Ans[i][j]=now[i][j];
				}
			}
		}
		ans++;
		return;
	}
	if(now[x][y])
	{
		dfs(x,y+1);
	}
	else
	{
		for(int i=1;i<=9;i++)
		{
			if((book[0][x]>>i)&1) continue;
			if((book[1][y]>>i)&1) continue;
			if((book[2][belong(x,y)]>>i)&1) continue;
			now[x][y]=i;
			book[0][x]^=(1<<i);
			book[1][y]^=(1<<i);
			book[2][belong(x,y)]^=(1<<i);
			dfs(x,y+1);
			now[x][y]=0;
			book[0][x]^=(1<<i);
			book[1][y]^=(1<<i);
			book[2][belong(x,y)]^=(1<<i);
		}
	}
}
int t;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	t=read();
	while(t--)
	{
		ans=0;
		memset(book,0,sizeof(book));
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
			{
				now[i][j]=read();
				if(now[i][j])
				{
					book[0][i]|=(1<<now[i][j]);
					book[1][j]|=(1<<now[i][j]);
					book[2][belong(i,j)]|=(1<<now[i][j]);
				}
			}
		dfs(0,0);
		write(ans);
		if(ans==1)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					cout<<Ans[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		cout<<endl<<endl<<endl;
	}
	return 0;
}


