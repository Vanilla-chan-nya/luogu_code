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
LL C[1010][1010];
LL sum[1010][1010];
int n,m,q;
int p=19260817;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	C[1][1]=C[1][0]=1;
	for(re int i=2;i<=1000;i++)
	{
		C[i][0]=1;
		for(re int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
//			cout<<C[i][j]<<" ";
		}
//		cout<<"\n";
	}
	for(re int i=1;i<=1000;i++)
	{
		for(re int j=1;j<=1000;j++)
		{
			sum[i][j]=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+C[i][j]+p)%p;
		}
	}
	re LL q,n,m;
	cin>>q;
	while(q--)
	{
		n=read(),m=read();
		cout<<sum[m][n]<<endl;
//		cout<<C[m][n]<<endl;
	}
	return 0;
}
