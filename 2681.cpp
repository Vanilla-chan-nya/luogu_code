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
map<int,int>M;
int n,m;
int a[1010];
int ans;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int op,x,y;
	while(m--)
	{
		op=read();
		x=read();
		y=read();
		if(op==0)
		{
			M.clear();ans=0;
			for(int i=x;i<=y;i++) M[a[i]]++;
			for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
			{
				if(it->second>M[ans]) ans=it->first;
			}
			write(ans);
		}
		else
		{
			a[x]=y;
		}
	}
	return 0;
}


