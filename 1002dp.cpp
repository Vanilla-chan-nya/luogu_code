#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
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

int n,m;
int mn,mm;
LL map[100][100];
bool inside(int a,int b)
{
	return (a>=0&&b>=0&&a<=n&&b<=m);
}
LL calc(int i,int j)
{
	if(!inside(i,j)) return 0;
	if(i==mn&&j==mm) return 0;
	if(abs(i-mn)+abs(j-mm)==3&&abs(i-mn)*abs(j-mm)==2) return 0;
	return map[i][j];
}
int main()
{
	cin>>n>>m>>mn>>mm;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	{
		if(i==0&&j==0) map[i][j]=1;
		else map[i][j]=calc(i-1,j)+calc(i,j-1);
		
	}
	cout<<map[n][m];
	return 0;
}

