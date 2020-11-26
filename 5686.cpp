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
	re int x=0;
    re char ch=getchar();
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
#define maxn 500010
#define p 1000000007
int n;
LL ans;
LL a[maxn],b[maxn],suma[maxn],sumb[maxn],ssa,ssb;
int main()
{
	n=read();
	for(re int i=1;i<=n;i++)
	{
		a[i]=read();
		suma[i]=suma[i-1]+a[i];
		suma[i]%=p;
		ssa=(ssa+suma[i])%p;
	}
	for(re int i=1;i<=n;i++)
	{
		b[i]=read();
		sumb[i]=sumb[i-1]+b[i];
		sumb[i]%=p;
		ssb=(ssb+sumb[i])%p;
	}
	for(re int i=1;i<=n;i++)
	{
		ans=(ans+(n+1)*suma[i]%p*sumb[i]%p)%p;
	}
	ans=ans+p-ssa*ssb%p;
	cout<<ans%p;
	return 0;
}

