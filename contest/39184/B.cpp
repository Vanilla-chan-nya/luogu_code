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
int p[410];
int n,k,ans;
int main()
{
	n=read();
	k=read();
	if(k<=2) k=2;
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		cout<<"now=";
		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
		for(int l=1;l<=n;l++)
		{
			for(int r=l+k-1;r<=n;r++)//l+k-1<=r
			{
				int mx=p[l],mn=p[l];
				for(int i=l+1;i<=r;i++)
				{
					mx=max(mx,p[i]);
					mn=min(mx,p[i]);
				}
				if(mx-mn==r-l)
				{
					ans++;
					if(ans>=1000000007) ans-=1000000007;
					goto nxt;
				}
			}
		}
		nxt:;
	}while(next_permutation(p+1,p+n+1));
	write(ans);
	return 0;
}


