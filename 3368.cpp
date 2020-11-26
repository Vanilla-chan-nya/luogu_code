#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#define re register
using namespace std;

template<class T>inline void read(T&x)
{
	int fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-') fu=-1,ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=fu;
}
inline int read()
{
	int x=0,fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int a[500010];
int n,m;
void add(int x,int k)
{
	while(x<=n)
	{
		a[x]+=k;
		x+=x&(-x);
	}
}
int ask(int x)
{
	int ans=0;
	while(x)
	{
		ans+=a[x];
		x-=x&(-x);
	}
	return ans;
}
int main()
{
	n=read();
	m=read();
	re int now=0,last=0;
	for(re int i=1;i<=n;i++){
		now=read();
		a[i]+=now-last;
		if(i+(i&(-i))<=n) a[i+(i&(-i))]+=a[i];
		last=now;
	}
	re int t,x,y,k;
	while(m--)
	{
		t=read();
		if(t==1)
		{
			x=read();
			y=read();
			k=read();
			add(x,k);
			add(y+1,-k);
		}
		else
		{
			x=read();
			write(ask(x));
		}
	}
	
	return 0;
}

