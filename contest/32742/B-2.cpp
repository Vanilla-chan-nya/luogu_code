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
};
int t,n,a,b,c,ans,delta;
queue<node>q;
void bfs()
{
	while(q.size()) q.pop();
	q.push(node(a,b,c));
	node x,t;
	while(q.size())
	{
		t=x=q.front();
		q.pop();
		if(x.cnt>8) break;
		q.push(x.L());
		q.push(x.R());
		while(true)
		{
			if(t.cnt&1) t=t.L();
			else t=t.R();
			if(t.c>n)
			{
				ans=min(ans,t.cnt);
				break;
			}
		}
		t=x;
		while(true)
		{
			if(t.cnt&1) t=t.R();
			else t=t.L();
			if(t.c>n)
			{
				ans=min(ans,t.cnt);
				break;
			}
		}
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
		ans=2000000000;
		while(true)
		{
//			delta=s.c-s.b;
//			ans=min(ans,(int)ceil((n-s.c)*1.0/delta)+s.cnt);
			if(s.R().c>n)
			{
				ans=min(ans,s.cnt+1);
				break;
			}
			if(s.cnt&1) s=s.L();
			else s=s.R();
			if(s.c>n)
			{
				ans=min(ans,s.cnt);
				break;
			}
		}
		s=node(a,b,c);
		while(true)
		{
//			delta=s.c-s.b;
//			ans=min(ans,(int)ceil((n-s.c)*1.0/delta)+s.cnt);
			if(s.R().c>n)
			{
				ans=min(ans,s.cnt+1);
			}
			if(s.cnt&1) s=s.R();
			else s=s.L();
			if(s.c>n)
			{
				ans=min(ans,s.cnt);
				break;
			}
		}
//		bfs();
		write(ans);
	}
	
	return 0;
}


