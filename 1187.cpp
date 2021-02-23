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
int n,m;
IL bool exist(int x,int y)
{
	return x>=0&&x<=n+1&&y>=0&&y<=m+1;
}
int map[1010][1010];
char ch;
LL ans;
int dt[4][2]={1,0,-1,0,0,1,0,-1};
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			while(ch==' '||ch=='\n') ch=getchar();
			map[i][j]=ch-'0';
//			cout<<map[i][j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j])
			{
				ans+=2;//top&down
				for(int t=0;t<4;t++)
				{
					if(exist(i+dt[t][0],j+dt[t][1]))
					{
						ans+=max(0,map[i][j]-map[i+dt[t][0]][j+dt[t][1]]);
					}
				}
			}
		}
	} 
	cout<<ans;
	return 0;
}


