/**************************************************************
 * Problem:
 * Author: Vanilla_chan
 * Date:
**************************************************************/
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
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int pr[]={1063,1069};
int prime[100000];
int cnt;
bool book[10000];
int n=100000,m=100000;
#include<ctime>
int main()
{
	srand(time(0));
//	freopen(".in","r",stdin);
	freopen("5071.in","w",stdout);
	for(int i=2;i<=1000;i++)
	{
		if(book[i]==0)
		{
			prime[++cnt]=i;
			for(int j=i+i;j<=1000;j++)
			{
				book[j]=1;
			}
		}
	}
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		LL x=1;
		if(i%3==0)
		{
			x=(LL)rand()*rand()*rand()%1000000000;
			x++;
		}
		else if(i%3==1)
		{
			x=pr[0];
			for(int j=1;j<=cnt;j++)
			{
				if(rand()%10==0)
				{
					if(x*prime[j]<=1000000000) x*=prime[j];
				}
			}
			for(int j=1;j<=cnt;j++)
			{
				if(rand()%10==0)
				{
					if(x*prime[j]<=1000000000) x*=prime[j];
				}
			}
			for(int j=1;j<=cnt;j++)
			{
				if(rand()%10==0)
				{
					if(x*prime[j]<=1000000000) x*=prime[j];
				}
			}
		}
		else
		{
			x=pr[1];
			for(int j=1;j<=cnt;j++)
			{
				if(rand()%10==0)
				{
					if(x*prime[j]<=1000000000) x*=prime[j];
				}
			}
			for(int j=1;j<=cnt;j++)
			{
				if(rand()%10==0)
				{
					if(x*prime[j]<=1000000000) x*=prime[j];
				}
			}
			for(int j=1;j<=cnt;j++)
			{
				if(rand()%10==0)
				{
					if(x*prime[j]<=1000000000) x*=prime[j];
				}
			}
		}
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"1 "<<n<<endl;
	cout<<"1 "<<n/2<<endl;
	cout<<n/2+1<<" "<<n<<endl;
	for(int i=4;i<=m;i++)
	{
		int x=rand()*3%n+1,y=rand()*3%n+1;
		if(abs(x-y)<=10) y=y+n/10,y%=n,y++;
		if(x>y) swap(x,y);
		if(x<=0||y>n) exit(1);
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}



