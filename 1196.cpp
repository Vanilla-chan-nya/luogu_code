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
int f[30010],sze[30010],dis[30010];
int getf(int x)
{
	if(f[x]==x) return x;
	int xx=getf(f[x]);
	dis[x]+=dis[f[x]];
	return f[x]=xx;
}
void merge(int x,int y)
{
	x=getf(x);
	y=getf(y);
	dis[x]+=sze[y];
	f[x]=y;
	sze[y]+=sze[x];
	sze[x]=0;
}
bool ask(int x,int y)
{
	x=getf(x);
	y=getf(y);
	return x==y;
}
int T;
int main()
{
	T=read();
	for(int i=1;i<=30000;i++)
	{
		f[i]=i;
		dis[i]=0;
		sze[i]=1;
	}
	while(T--)
	{
		char op=getchar();
		while(op!='C'&&op!='M') op=getchar();
		int x=read();
		int y=read();
		if(op=='M')
		{
			merge(x,y);
		}
		else
		{
			if(ask(x,y)) write(abs(dis[x]-dis[y])-1);
			else cout<<"-1"<<endl; 
		}
	}
	
	return 0;
}


