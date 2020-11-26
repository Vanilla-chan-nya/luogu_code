#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
//#include<map>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#define re register
using namespace std;

template<class T>inline void read(T&x)

{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    int g=0;
    do{G[++g]=x%10;x/=10;}while(x);
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m;
int map[4000][4000];
int dis[4000][4000];
bool book[4000][4000];
struct edge{
	int x,y;
};
bool exist(int i,int j)
{
	return i>=0&&i<n&&j>=0&&j<m;
}
int dt[4][2]={1,0,-1,0,0,-1,0,1};
void bfs(int i,int j)
{
	deque<edge>q;
	q.push_back((edge){i,j});
	memset(book,0,sizeof(book));
	book[i][j]=1;
	edge now;
	while(!q.empty())
	{
		now=q.front();
		q.pop_front();
		book[now.x][now.y]=0;
		for(int t=0;t<4;t++)
		{
			if(exist(now.x+dt[t][0],now.y+dt[t][1])==0) continue;
			if(map[now.x+dt[t][0]][now.y+dt[t][1]]==0)
			{
				if(dis[now.x+dt[t][0]][now.y+dt[t][1]]>abs(i-now.x-dt[t][0])+abs(j-now.y-dt[t][1]))
				{
					dis[now.x+dt[t][0]][now.y+dt[t][1]]=abs(i-now.x-dt[t][0])+abs(j-now.y-dt[t][1]);
					if(!book[now.x+dt[t][0]][now.y+dt[t][1]]) q.push_back((edge){now.x+dt[t][0],now.y+dt[t][1]}),book[now.x+dt[t][0]][now.y+dt[t][1]]=1;
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	char t;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dis[i][j]=0x3f3f3f3f;
			do{
				t=getchar();
			}while(t==' '||t=='\n');
			map[i][j]=t-'0';
			if(t=='1') dis[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(map[i][j]) bfs(i,j);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cout<<dis[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

