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
struct node
{
	int x,y,z;
}a[500010];
bool cmp1(node x,node y)
{
	return x.x<y.x;
}
bool cmp2(node x,node y)
{
	return x.y<y.y;
}
int b[500010];
void add(int x)
{
	while(x<=n) b[x]++,x+=x&(-x);
}
int ask(int x)
{
	int ans=0;
	while(x) ans+=b[x],x-=x&(-x);
	return ans;
}
LL ans;
int main()
{
//	freopen("P1908_1.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++) a[i].x=a[i].z=read(),a[i].y=i;
	stable_sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(a[i].z==a[i-1].z) a[i].x=a[i-1].x;
		else 
		a[i].x=i;
	}
	stable_sort(a+1,a+n+1,cmp2);
//	for(int i=1;i<=n;i++) write(a[i].x);
	for(int i=1;i<=n;i++)
	{
		add(a[i].x);
		ans+=ask(a[i].x-1);
	}
	write(ans+1);
	return 0;
}

