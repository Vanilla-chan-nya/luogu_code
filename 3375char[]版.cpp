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
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

template<class T>inline void read(T&x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    int g=0;
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int nxt[1000010];
char p[1000010],t[1000010];
int tl,pl;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>(p+1)>>(t+1);
	tl=strlen(t+1);
	pl=strlen(p+1);
	for(int i=2,j=0;i<=tl;i++)
	{
		while(j&&t[i]!=t[j+1]) j=nxt[j];
		if(t[i]==t[j+1]) j++;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=pl;i++)
	{
		while(j&&(p[i]!=t[j+1])) j=nxt[j];
		if(p[i]==t[j+1]) j++;
		if(j==tl) cout<<i-tl+1<<endl,j=nxt[j];
	}
	for(int i=1;i<=tl;i++) cout<<nxt[i]<<" "; 
	return 0;
}

