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
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
LL pow(LL a,LL b,LL p)
{
	LL x=1;
	while(b)
	{
		if(b&1) x*=a,x%=p;
		a=a*a%p;
		b>>=1;
	}
	return x;
}
LL n,p;
int main()
{
	cin>>n>>p;
	for(LL i=1;i<=n;i++)
	{
		cout<<pow(i,p-2,p)<<endl;
	}
	
	return 0;
}

