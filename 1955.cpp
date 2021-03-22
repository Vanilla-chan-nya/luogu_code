/**************************************************************
 * Problem: 1955
 * Author: Vanilla_chan
 * Date: 20210314
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
#define N 1000010
int n,t; 
int f[N],A[N],B[N];
int tot;
int getf(int x)
{
	if(x==f[x]) return x;
	return f[x]=getf(f[x]);
}
void merge(int x,int y)
{
	x=getf(x);
	y=getf(y);
	f[x]=y;
}
map<int,int>m;
int cnt;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=1000000;i++) f[i]=i;
		m.clear();
		cnt=tot=0;
		while(n--)
		{
			int a=read();
			int b=read();
			if(m.find(a)==m.end()) m[a]=++cnt;
			if(m.find(b)==m.end()) m[b]=++cnt;
			a=m[a];
			b=m[b];
			int op=read();
			if(op==1)
			{
				merge(a,b);
			}
			else
			{
				tot++;
				A[tot]=a;
				B[tot]=b;
			}
		}
		bool flag=1;
		for(int i=1;i<=tot;i++)
		{
			if(getf(A[i])==getf(B[i])) 
			{
				flag=0;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}



