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
bool a[1000010];
int n,m1=10000000,m2,ans1,ans2;
int main()
{
	n=read();
	int l,r;
	while(n--)
	{
		l=read();
		r=read();
		m2=max(m2,r);
		m1=min(m1,l);
		for(int i=l;i<r;i++) a[i]=1;
	}
	for(int i=m1,cnt1=0,cnt2=0;i<m2;i++)
	{
		if(a[i]) cnt1++,cnt2=0;
		else cnt2++,cnt1=0;
		ans1=max(ans1,cnt1);
		ans2=max(ans2,cnt2);
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}


