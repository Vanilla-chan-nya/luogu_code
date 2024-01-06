#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define LL long long
#define N 30000
const LL p=22739;
vector<int>h[N];

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
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar(' ');
}

LL t,n,x,x1;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=0;i<p;i++) h[i].clear();
		while(n--)
		{
			x=read();
			x1=(x%p+p)%p;
			bool flag=0;
			for(unsigned int i=0;i<h[x1].size()&&flag==0;i++)
			{
				if(h[x1][i]==x) flag=1;
			}
			if(!flag)
			{
				h[x1].push_back(x);
				write(x);
			}
		}
		putchar('\n');
	}
}
