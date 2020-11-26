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
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
bool book[200000000];
LL prime[200000000];
LL size;
LL n,q;
int main()//n=3*10^7
{
//	freopen("prime.in","r",stdin);
//	freopen("Eratosthenes.out","w",stdout);
	std::ios::sync_with_stdio(0);
	n=read();
	book[1]=1;
	for(re LL i=2;i<=n;i++)
	{
		if(!book[i]) prime[size++]=i;
		for(re LL j=0;j<size&&i*prime[j]<=n;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	q=read();
	while(q--) write(prime[read()-1]);
	return 0;
}

