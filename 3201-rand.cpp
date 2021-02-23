#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#include<ctime>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
using namespace std;

template<class T>inline void read(T&x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m;
#define N 100000
#define M 100
int main()
{
	freopen("P3201.in","w",stdout);
	srand(time(NULL));
	n=rand()%10+10;
	m=rand()%(n+5)+10;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++) cout<<rand()%(n+10)+1<<" ";
	cout<<endl;
	for(int i=1;i<m;i++)
	{
		if(rand()%10<7)
		{
			cout<<"1 "<<rand()%(n+1)+1<<" "<<rand()%(n+1)+1<<endl;
		}
		else
		{
			write(2);
		}
	}
	write(2);
	return 0;
}


