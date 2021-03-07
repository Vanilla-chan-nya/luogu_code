#include<iostream>
#include<algorithm>
#include<cstdio>
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
char ch[1010][1010];
//int dt[8][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,1,-1};
int dt[4][2]={0,1,0,-1,1,0,-1,0};
IL bool exist(int x,int y)
{
	return x>=1&&y>=1&&x<=n&&y<=m;
}
struct Point
{
	int x,y;
	Point(int xx,int yy)
	{
		x=xx,y=yy;
	}
	void turn(int t)
	{
		x+=dt[t][0];
		y+=dt[t][1];
	}
	bool exist()
	{
		return x>=1&&y>=1&&x<=n&&y<=m;
	}
};
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	LL ans=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(ch[i][j]=='h')
		{
			for(int t=0;t<4;t++)
			{
				Point now=Point(i,j);
//				cout<<"start t="<<t<<" "<<i<<" "<<j<<endl;
				int k=1;
				for(;k<=3;k++)
				{
					now.turn(t);
//					cout<<"check "<<"k="<<k<<" "<<now.x<<" "<<now.y<<endl;
					if(now.exist()&&ch[now.x][now.y]==((k&1)?'e':'h'))
					{
						;
					}
					else break;
				}
				if(k==4) ans++;
			}
			
		}
	}
	cout<<ans;
	return 0;
}


