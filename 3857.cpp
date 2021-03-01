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
LL b[60],tot;
void insert(LL x)
{
	for(int i=floor(log2(x))+1;i>=0;i--)
	{
		if((x>>i)&1)
		{
			if(!b[i])
			{
				b[i]=x;
				tot++;
				return;
			}
			else x^=b[i];
		}
	}
}
char ch[60];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		cin>>ch;
		LL x=0;
		int len=strlen(ch);
		for(int j=len-1;j>=0;j--)
		{
			if(ch[j]=='O')x+=(1ll<<(len-j));
		}
		insert(x);
	}
	cout<<(1ll<<tot)%2008;
	return 0;
}


