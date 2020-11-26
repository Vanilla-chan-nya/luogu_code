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
template<class T>inline void write(T x,int m)
{
    int g=0;
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar((char)('0'+G[i])); if(m>0) putchar('\n');
}
int n,m;
int lg[2000010];
int mx[2000010][24]; 
void pre()
{
	lg[1]=0;
	for(int i=2;i<=2000010;i++) lg[i]=lg[i>>1]+1;
	for(int j=1;j<=21;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			mx[i][j]=min(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	}
}
int ask(int l,int r)
{
	return min(mx[l][lg[r-l+1]],mx[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);
}

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=n;i++) cin>>mx[i][0];
	pre();
	while(m--){
		cin>>a>>b;
		cout<<ask(a,b)<<" ";
	}
	return 0;
}

