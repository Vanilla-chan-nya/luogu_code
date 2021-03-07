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
vector<int>a;
#define IT vector<int>::iterator
int op,x,ans,lastans;
int main()
{
	n=read();
	m=read();
	while(n--) x=read(),a.insert(lower_bound(a.begin(),a.end(),x),x);
	while(m--)
	{
		op=read();
		x=read()^lastans;
		if(op==1)
		{
			a.insert(lower_bound(a.begin(),a.end(),x),x);
		}
		else if(op==2)
		{
			a.erase(lower_bound(a.begin(),a.end(),x));
		}
		else if(op==3)
		{
			lastans=(lower_bound(a.begin(),a.end(),x)-a.begin())+1;
		}
		else if(op==4)
		{
			lastans=a[x-1];
		}
		else if(op==5)
		{
			lastans=*(lower_bound(a.begin(),a.end(),x)-1);
		}
		else
		{
			lastans=*(upper_bound(a.begin(),a.end(),x));
		}
		if(op>=3) ans^=lastans;
	}
	write(ans);
	return 0;
}


