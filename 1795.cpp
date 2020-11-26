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
bool book[1000000010];
vector<int>n;
int maxn;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	re int t;t=read();
	while(t--)
	{
		n.push_back(read());
		if(maxn<n.back()) maxn=n.back();//卡卡常就过了！ 
	}
	for(re int i=1,k=0;i<=maxn;i+=k,k++)
	{
		book[i]=1;
	}
	for(int i=0;i<n.size();i++) write(book[n[i]]);//卡卡常就过了！ 
	return 0;
}

