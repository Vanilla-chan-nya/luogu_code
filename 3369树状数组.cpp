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

int a[20000010];
const int N = 20000010;
const int M = 10000000;
void add(int x)
{
	while(x<=N) a[x]++,x+=x&-x;
}
void del(int x)
{
	while(x<=N) a[x]--,x+=x&-x;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=x&-x) ans+=a[x];
	return ans;
}
int t;
int main()
{
	t=read();
	int op,x;
	while(t--)
	{
		cin>>op>>x;
		if(op==1) add(x+M);
		if(op==2) del(x+M);
		if(op==3) cout<<(ask(x+M-1)+1)<<endl;
		if(op==4) 
		{
			int l=0,r=N,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ask(mid-1)+1>x) r=mid;
				else l=mid+1;
			}
			cout<<l-1-M<<endl;
		}
		if(op==5)
		{
			x=ask(x+M-1);
			int l=0,r=N,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ask(mid-1)+1>x) r=mid;
				else l=mid+1;
			}
			cout<<l-1-M<<endl;
		}
		if(op==6)
		{
			x=ask(x+M)+1;
			int l=0,r=N,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ask(mid-1)+1>x) r=mid;
				else l=mid+1;
			}
			cout<<l-M-1<<endl;
		}
	}
	
	return 0;
}

