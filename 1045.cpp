/**************************************************************
 * Problem: 1045
 * Author: Vanilla_chan
 * Date: 20210307
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
struct number
{
	LL num[70];
	void upd()
	{
		for(int i=0;i<=60;i++)
		{
			if(num[i]<10000000000) continue;
			num[i+1]+=num[i]/10000000000;
			num[i]%=10000000000;
		}
	}
	void times(int x)
	{
		for(int i=0;i<=60;i++)
		{
			num[i]*=x;
		}
		upd();
	}
	void init(int x)
	{
		num[0]=x;
		upd();
	}
	void sub1()
	{
		num[0]-=1;
	}
	void out()
	{
		for(int i=49;i>=0;i--)
		{
			printf("%010lld",num[i]);
			if(i%5==0) putchar('\n');
		}
	}
}ans;
int b;
int main()
{
	//freopen("temp.in","r",stdin);
	b=read();
	cout<<(int)(log10(2.0)*b+1)<<endl;
	ans.init(1);
	while(b)
	{
		//write(b);
		if(b>=10) ans.times(1024),b-=10;
		else ans.times(2),b--;
	}
	ans.sub1();
	ans.out();
	return 0;
}


