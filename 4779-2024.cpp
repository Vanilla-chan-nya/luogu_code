/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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



#define N 400010

int n,m,s;
int cnt;
int head[N],ver[N],nxt[N],w[N];
void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	w[cnt]=z;
}
#define inf (0x7fffffff)

int dis[N];
bool book[N];
struct node
{
	int id,dis;
	bool operator<(const node& z) const
	{
		return dis > z.dis;
	}
};
priority_queue<node>q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		cin>>n>>m>>s;
		while(m--)
		{
			int x,y,z;
			cin>>x>>y>>z;
			insert(x,y,z);
		}
		for(int i=1;i<=n;i++) dis[i]=inf;
		dis[s]=0;
		q.push(node(s,0));
		while(q.size())
		{
			node x=q.top();
			q.pop();
			if(book[x.id]) continue;
			book[x.id]=1;
			for(int i=head[x.id];i;i=nxt[i])
			{
				if(dis[ver[i]]>dis[x.id]+w[i])
				{
					dis[ver[i]]=dis[x.id]+w[i];
					if(!book[ver[i]])
					{
						q.push(node(ver[i],dis[ver[i]]));
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<dis[i]<<" ";
		}
		
	}
	return 0;
}
