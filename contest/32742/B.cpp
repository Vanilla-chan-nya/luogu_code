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
struct node
{
	int a,b,c;
	int cnt;
	node(int aa=0,int bb=0,int cc=0,int tt=0)
	{
		a=aa,b=bb,c=cc;
		cnt=tt;
	}
	node L()
	{
		return node(2*a-b,a,c,cnt+1);
	}
	node R()
	{
		return node(a,c,2*c-b,cnt+1);
	}
}y;
int flag1,flag2;
queue<node>q;
int t,n,a,b,c;
void pre(node s)
{
	while(q.size()) q.pop();
	q.push(s);
	node x;
	while(q.size())
	{
		x=q.front();
		q.pop();
//		if(x.cnt>100000) continue;
//		debug cout<<x.a<<" "<<x.b<<" "<<x.c<<" "<<x.cnt<<endl;
		if(x.c>n)
		{
			flag1=x.cnt+1;
			break;
		}
		if(x.b>=x.c)
		{
//			debug
			flag2=1;
			y=x;
			break;
		}
		q.push(x.L());
		q.push(x.R());
	}
}
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		a=read();
		b=read();
		c=read();
		node s=node(a,b,c);
		flag1=flag2=0;
		pre(s);
//		if(flag1)
//		{
//			debug
			write(flag1-1);
//			continue;
//		}
//		if(flag2)
//		{
////			debug
//			while(y.c<=n)
//			{
////				debug cout<<y.a<<" "<<y.b<<" "<<y.c<<" "<<y.cnt<<endl;
//				y=y.R();
//			}
//			write(s.cnt);
//		}
		
		
		
	}
	
	
	return 0;
}


