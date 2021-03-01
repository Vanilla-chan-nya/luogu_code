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
int n;
struct node
{
	LL num,magic;
	IL bool operator<(const node& z)const
	{
		return magic>z.magic;
	}
}a[100010];
LL b[63];
int ans;
bool insert(LL x)
{
	for(int i=floor(log2(x))+1;i>=0;i--)
	{
		if((x>>i)&1)
		{
			if(!b[i])
			{
				b[i]=x;
				return 1;
			}
			else x^=b[i];
		}
	}
	return 0;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].magic;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(insert(a[i].num)) ans+=a[i].magic;
	}
	cout<<ans;
	return 0;
}


