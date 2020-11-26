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
int f[50010*3];
int n,k,ans;
int getf(int x)
{
	if(x==f[x]) return x;
	return f[x]=getf(f[x]);
}
void merge(int x,int y)
{
	x=getf(x);
	y=getf(y);
	f[x]=y;
}
bool ask(int x,int y)
{
	return getf(x)==getf(y);
}
int main()
{
	n=read();
	k=read();
	for(int i=1;i<=n*3;i++) f[i]=i;
	while(k--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		if(op==1)
		{
			if(ask(x,y+n)||ask(x+n,y)) ans++;
			else
			{
				merge(x,y);
				merge(x+n,y+n);
				merge(x+n+n,y+n+n);
			}
		}
		if(op==2)
		{
			if(ask(x,y)||ask(x,y+n)||ask(x+n,y+n+n)) ans++;
			else
			{
				merge(x+n,y);
				merge(x+n+n,y+n);
				merge(x,y+n+n);
			}
		}
	}
	cout<<ans;
	return 0;
}

