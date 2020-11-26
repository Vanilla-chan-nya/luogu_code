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
#define int long long
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
int n;
struct num
{
	int v1,rank,v2;
}a[500010];
int b[500010];
bool cmp1(num a,num b)
{
	return a.v2<b.v2;
}
void add(int x,int y)
{
//	debug;
	for(;x<=n;x+=x&(-x)) b[x]+=y;
}
int ask(int x)
{
//	debug;
	int ans=0;
	for(;x>0;x-=x&(-x)) ans+=b[x];
	return ans;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i].v1=read();
		a[i].v2=i;
	}
	sort(a+1,a+n+1,cmp1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i].rank=a[i].v2; 
		add(i,a[i].rank);
		ans+=ask(a[i].rank-1);
	}
	cout<<ans;
	return 0;
}

