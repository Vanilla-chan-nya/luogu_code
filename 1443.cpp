#include<iostream>//不想OI一场空，千万别用万能头
#include<queue>
#include<cstdio>//能不用cin就不用
#include<cstring>
#include<iomanip>
#define IL inline
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,hx,hy;
int move[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
int map[402][402];
bool vis[402][402];
struct NODE{
	int x;
	int y;
};
queue<NODE> node;
void bfs(int depth)
{
	
	NODE now;
	while(!node.empty())
	{
		now=node.front();
		node.pop();
		vis[now.x][now.y]=1;
		map[now.x][now.y]=depth;
	}
	
	now.x=0,now.y=0;
	for(int i=0;i<8;i++)
	{
		if(map[now.x+move[i][0]][now.y+move[i][1]]>depth+1)
		{
			if(now.x<1||now.x>=n||now.y<1||now.y>=m) continue;
			if(vis[now.x][now.y]) continue;
			now.x=now.x+move[i][0];
			now.y=now.y+move[i][1];
			node.push(now);
		} 
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&hx,&hy);
	memset(map,inf,sizeof(map));
	NODE s;
	s.x=hx;
	s.y=hy;
	node.push(s);
	bfs(0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j!=0) cout<<setw(5);
			if(map[i][j]<inf/2) cout<<cout<<map[i][j];
			else cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}

