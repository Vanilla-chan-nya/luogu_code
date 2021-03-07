/**************************************************************
 * Problem: 1664
 * Author: Vanilla_chan
 * Date: 20210307
**************************************************************/
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

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int t,n,a,m;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		if(read()==1)
		{
			if(a)
			{
				m-=(1<<(a-1));
				m=max(m,0);
			}
			m++;
			a=0;
			if(m>=1) t+=1;
			if(m>=3) t+=1;
			if(m>=7) t+=1;
			if(m>=30) t+=1;
			if(m>=120) t+=1;
			if(m>=365) t+=1;
		}
		else
		{
			a++;
		}
		//cout<<"m="<<m<<endl;
	}
	write(t);
	return 0;
}


