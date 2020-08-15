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
using namespace std;

int n,m;
int map[200][200];

struct point{
	int x,y;
	point(){
		x=y=0;
	}
	point(int a,int b)
	{
		x=a,y=b;
	}
};

int delta[4][2]={0,1,0,-1,1,0,-1,0};

void expand(int a,int b)
{
	bool book[200][200];
	memset(book,0,sizeof(book));
	book[a][b]=1;
	deque<point>line;
	line.push_back({a,b});
	while(!line.empty())
	{
		point t=line.front();
		line.pop_front();
		book[t.x][t.y]=0;
//		cout<<"拓展到"<<t.x<<" "<<t.y<<endl;
		for(int i=0;i<4;i++)
		{
			if(t.x+delta[i][0]>=0&&t.x+delta[i][0]<n&&t.y+delta[i][1]>=0&&t.y+delta[i][1]<m&&map[t.x+delta[i][0]][t.y+delta[i][1]]>map[t.x][t.y]+1)
			{
				map[t.x+delta[i][0]][t.y+delta[i][1]]=map[t.x][t.y]+1;
				if(!book[t.x+delta[i][0]][t.y+delta[i][1]]) book[t.x+delta[i][0]][t.y+delta[i][1]]=1,line.push_back({t.x+delta[i][0],t.y+delta[i][1]});
			}
		}
	}
}


int main()
{
	cin>>n>>m;
	memset(map,0x7F,sizeof(map));
	char t;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		t=getchar();
		while(t==' '||t=='\n') t=getchar();
		if(t=='1')
		{
			map[i][j]=0;
//			cout<<i<<" "<<j<<"被更新为0\n";
		}
	} 
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
//		cout<<"更新"<<i<<" "<<j<<endl; 
		expand(i,j);
//		cout<<"更新完毕\n"; 
	} 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cout<<map[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}


