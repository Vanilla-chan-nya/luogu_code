#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
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

map<LL,int>dis;
set<LL>online;
//queue<LL>q;
LL q[1000000];int l,r;
const LL goal=123804765;
int dt[4][2]={1,0,-1,0,0,1,0,-1};
int now[3][3];
int i,j,way;
void bfs()
{
//	q.push(read());
	q[++r]=read();
	LL x,zx,zy,t,tx,ty;
	while(/*!q.empty()*/l<=r)
	{
//		t=x=q.front();
//		q.pop();
		t=x=q[l++];
		online.erase(x);
		if(x==goal)
		{
			write(dis[x]);
			return;
		}
		for(i=2;i>=0;i--)
		for(j=2;j>=0;j--)
		{
			now[i][j]=t%10;
			t/=10;
			if(now[i][j]==0) zx=i,zy=j;
		}
//		for(int i=0;i<3;i++)
//		{
//			for(int j=0;j<3;j++)
//			{
//				cout<<now[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
		for(way=0;way<4;way++)
		{
			tx=zx+dt[way][0];
			ty=zy+dt[way][1];
			if(tx<0||ty<0||tx>2||ty>2) continue;
			swap(now[tx][ty],now[zx][zy]);
			t=0;
			for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
				t=t*10;
				t+=now[i][j];
			}
//			cout<<t<<endl;
			if(dis.find(t)==dis.end())
			{
				dis[t]=dis[x]+1;
//				q.push(t);
				q[++r]=t;
				online.insert(t);
			}
			else
			{
				if(dis[t]>dis[x]+1)
				{
					dis[t]=dis[x]+1;
					if(online.find(t)==online.end())
					{
						online.insert(t);
//						q.push(t);
						q[++r]=t;
					}
				}
			}
			swap(now[tx][ty],now[zx][zy]);
		}
	}
}

int main()
{
	bfs();
	
	return 0;
}


