#include <bits/stdc++.h>
const int SIZE=30;
using namespace std;
int n,m,x,y;//B(n,m),horse(x,y)
long long qp[SIZE][SIZE];//第一个坐标表示右，第二个坐标表示下 
void zu(int a,int b)//卒(a,b) 
{
	if(a>n||b>m) return;//检查卒是否越界 
	if(qp[a+1][b]!=-1) {qp[a+1][b]+=qp[a][b]; zu(a+1,b);}//向右走 
	if(qp[a][b+1]!=-1) {qp[a][b+1]+=qp[a][b]; zu(a,b+1);}//向下走 
	return; 
} 
int main()
{
	cin>>n>>m>>x>>y;
	qp[0][0]=1;//要先把A点初始化为"一种" 
	//用-1来表示不可到的点
	for(int a=0;a<SIZE;a++)
	{
		for(int b=0;b<SIZE;b++)
		if(a>n||b>n)
			qp[a][b]=-1;
	}
	qp[x][y]=-1;
	
	qp[x+1][y+2]=-1;
	qp[x+1][y-2]=-1;
	qp[x+2][y+1]=-1;
	qp[x+2][y-1]=-1;
	
	qp[x-1][y+2]=-1;
	qp[x-1][y-2]=-1;
	qp[x-2][y+1]=-1;
	qp[x-2][y-1]=-1;
	zu(0,0);
	for(int a=0;a<=m;a++)
	{
		for(int b=0;b<=n;b++)
		cout<<qp[a][b]<<"\t";
		cout<<"\n";
	}
	cout<<qp[n][m];
	return 0;
} 
