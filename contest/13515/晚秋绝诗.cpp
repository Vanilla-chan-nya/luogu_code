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
int n,m;
bool cloud[500010];
bool flag[500010];
int b[500010];
IL void add(int x)
{
	while(x<=n) b[x]++,x+=x&(-x);
}
IL void sub(int x)
{
	while(x<=n) b[x]++,x+=x&(-x);
}
IL int ask(int x)
{
	int ans=0;
	while(x) ans+=b[x],x-=x&(-x);
	return ans;
}
IL int ask(int x,int y)
{
	return ask(y)-ask(x-1);
}
int op,x,l,r,mid,L,R;
int main()
{
	n=read();
	m=read();
	while(m--)
	{
		op=read();
		x=read();
		if(op==1)
		{
			if(cloud[x])
			{
				cloud[x]=0;
				if(flag[x]) sub(x);
			}
			else
			{
				cloud[x]=1;
				if(flag[x]) add(x);
			}
		}
		else if(op==2)
		{
			if(flag[x])
			{
				flag[x]=0;
				if(cloud[x]) sub(x);
			}
			else
			{
				flag[x]=1;
				if(cloud[x]) add(x);
			}
		}
		else
		{
			l=1,r=x-1;
			while(l<r)
			{
				mid=l+r>>1;
				if(ask(mid,x)==x-mid+1) l=mid;
				else r=mid;
			}
			L=l;
			if(L)
		}
	}
	
	return 0;
}


