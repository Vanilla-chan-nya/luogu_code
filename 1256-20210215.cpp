#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<queue>
#include<vector>
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

template<class T>inline void read(T&x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int map[200][200];
int dis[200][200];
int n,m;
int dt[4][2]={0,1,0,-1,1,0,-1,0};
#define pr pair<int,int>
#define mp(x,y) make_pair(x,y);
queue<pr>q;
pr t;
IL bool exist(pr x)
{
	return x.first<=n&&x.first>=1&&x.second<=m&&x.second>=1;
}
int main()
{
	n=read();
	m=read();
	char ch;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			while(ch=='\r'||ch=='\n'||ch==' ') ch=getchar();//WA!here!"ch=='\r'"!!F***??????
			if(ch=='1') map[i][j]=1,dis[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j])
			{
				while(q.size()) q.pop();
				t=mp(i,j);
				q.push(t);
				while(q.size())
				{
					t=q.front();
					q.pop();
					for(int d=0;d<4;d++)
					{
						pr v=mp(t.first+dt[d][0],t.second+dt[d][1]);
						if(exist(v)&&dis[v.first][v.second]>dis[t.first][t.second]+1)
						{
							dis[v.first][v.second]=dis[t.first][t.second]+1;
							q.push(v);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cout<<dis[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}


