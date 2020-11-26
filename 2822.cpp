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
int t,k;
LL C[2010][2010],s[2010][2010];
void pre()
{
	//C[i][j]=C[i-1][j-1]+C[i-1][j]
	C[0][0]=C[1][0]=C[1][1]=1;
	for(int i=2;i<=2000;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=2000;j++) 
			C[i][j]=C[i-1][j-1]+C[i-1][j],C[i][j]%=k;
	}
	
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=2000;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if(!C[i][j]) s[i][j]++;
		}
		s[i][i+1]=s[i][i];
	}

}
int main()
{
	t=read();
	k=read();
	pre();
	while(t--)
	{
		int i=read();
		int j=read();
		cout<<s[i][min(j,i)]<<endl;
	}
	
	return 0;
}

