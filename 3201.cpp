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
#define N 100010
int n,m;
int a[N];
int ans;
int f[N*10],sze[N*10];
int head[N*10],nxt[N*10];
int main()
{
//	freopen("P3201.in","r",stdin);
//	freopen("P3201.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		f[a[i]]=a[i];
		sze[a[i]]++;
		nxt[i]=head[a[i]];
		head[a[i]]=i;
		if(a[i]!=a[i-1]) ans++;
	}
	int op,x,y;
	while(m--)
	{
		op=read();
		if(op==1)
		{
			x=read();
			y=read();
			if(x==y) continue;
			if(sze[f[x]]>sze[f[y]]) swap(f[x],f[y]);//启发式合并 
			x=f[x];
			y=f[y];
			for(int i=head[x];i;i=nxt[i])
			{
				if(a[i+1]==y) ans--;
				if(a[i-1]==y) ans--;
			}
			int j=0;
			for(int i=head[x];i;i=nxt[i]) a[j=i]=y;	
			if(head[x]) nxt[j]=head[y],head[y]=head[x];
			sze[y]+=sze[x];
			sze[x]=0;
			head[x]=0;
		}
		else write(ans);
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<endl;
	}
	return 0;
}

