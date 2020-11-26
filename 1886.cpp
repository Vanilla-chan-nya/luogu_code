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
using namespace std;

template<class T>inline void read(T&x)
{
	int fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-') fu=-1,ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=fu;
}
inline int read()
{
	int x=0,fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
deque<int>mx,mn;
int a[1000010];
int n,k;
int main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		while(!mn.empty()&&a[mn.back()]>a[i]) mn.pop_back();
		mn.push_back(i);
		while(!mn.empty()&&mn.front()+k<=i) mn.pop_front();
		if(i>=k) cout<<a[mn.front()]<<" ";
	}
	putchar('\n');
	for(int i=1;i<=n;i++)
	{
		while(!mx.empty()&&a[mx.back()]<a[i]) mx.pop_back();
		mx.push_back(i);
		while(!mx.empty()&&mx.front()+k<=i) mx.pop_front();
		if(i>=k) cout<<a[mx.front()]<<" ";
	}
	return 0;
}

