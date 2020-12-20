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
int cnt;
map<LL,int>dis1,dis2;
set<LL>online1,online2;
queue<LL>q1,q2;
const LL goal=123804765;
int dt[4][2]={1,0,-1,0,0,1,0,-1};
int now[3][3];
int i,j,way;
LL x,t,zx,zy,tx,ty;
int minstep=10000;
void two_way_bfs()
{
	q1.push(read());
	online1.insert(q1.front());
	q2.push(goal);
	online2.insert(goal);
	dis1[q1.front()]=0;
	dis2[goal]=0;
	while(!(q1.empty()||q2.empty()))
	{
//		debug
//		cnt++;
		if(q1.size()>q2.size())
		{
			t=x=q1.front();
			q1.pop();
			online1.erase(x);
			if(dis1[x]>minstep) continue;
			for(int i=2;i>=0;i--)
			for(int j=2;j>=0;j--)
			{
				now[i][j]=t%10;
				t/=10;
				if(now[i][j]==0) zx=i,zy=j;
			}
			for(int way=0;way<4;way++)
			{
				tx=zx+dt[way][0];
				ty=zy+dt[way][1];
				if(tx<0||ty<0||tx>3||ty>3) continue;
				t=0;
				swap(now[tx][ty],now[zx][zy]);
				for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					t=t*10+now[i][j];
				if(dis1.find(t)==dis1.end()||dis1[t]>dis1[x]+1)
				{
					dis1[t]=dis1[x]+1;
					if(online1.find(x)==online1.end()) online1.insert(t),q1.push(t);
				}
				if(dis2.find(t)!=dis2.end())
				{
					minstep=min(minstep,dis2[t]+dis1[t]);
				}
				swap(now[tx][ty],now[zx][zy]);
			}
		}
		else
		{
			t=x=q2.front();
			q2.pop();
			online2.erase(x);
			if(dis2[x]>minstep) continue;
			for(int i=2;i>=0;i--)
			for(int j=2;j>=0;j--)
			{
				now[i][j]=t%10;
				t/=10;
				if(now[i][j]==0) zx=i,zy=j;
			}
			for(int way=0;way<4;way++)
			{
				tx=zx+dt[way][0];
				ty=zy+dt[way][1];
				if(tx<0||ty<0||tx>3||ty>3) continue;
				t=0;
				swap(now[tx][ty],now[zx][zy]);
				for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					t=t*10+now[i][j];
				if(dis2.find(t)==dis2.end()||dis2[t]>dis2[x]+1)
				{
					dis2[t]=dis2[x]+1;
					if(online2.find(x)==online2.end()) online2.insert(t),q2.push(t);
				}
				if(dis1.find(t)!=dis1.end())
				{
					minstep=min(minstep,dis1[t]+dis2[t]);
				}
				swap(now[tx][ty],now[zx][zy]);
			}
		}
	}
}

int main()
{
	two_way_bfs();
	write(minstep);
//	cout<<cnt<<endl;
	return 0;
}


