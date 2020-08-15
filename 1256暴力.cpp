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

void expand(int a,int b)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(abs(a-i)+abs(b-j)<map[i][j]) map[i][j]=abs(a-i)+abs(b-j);
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
		if(t=='1') map[i][j]=0,expand(i,j);
	} 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cout<<map[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}


