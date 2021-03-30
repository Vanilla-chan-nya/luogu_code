/**************************************************************
 * Problem: 5960
 * Author: Vanilla_chan
 * Date: 20210329
 * E-Mail: Vanilla_chan@outlook.com
**************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
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
};
using namespace oi;

#define N 50010
int n,m;
int head[N],nxt[N<<1],ver[N<<1],w[N<<1];
int cnt;
void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	w[cnt]=z;
}
int dis[N];
struct node
{
	int x,dis;
	node(int xx=0,int dd=0)
	{
		x=xx;
		dis=dd;
	}
	IL bool operator<(const node &z)const
	{
		return dis>z.dis;
	}
};
priority_queue<node>q;
bool book[N];
int tme[N];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1,a,b,c;i<=m;i++)
	{
		oi::cin>>a>>b>>c;
		insert(b,a,c);
	}
	int s=0,x;
	for(int i=1;i<=n;i++)
	{
		insert(s,i,0);
		dis[i]=1000000000;
	}
	q.push(node(s,0));
	bool flag=0;
	book[s]=1;
	while(q.size()&&!flag)
	{
		x=q.top().x;
		q.pop();
		book[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
			if(dis[ver[i]]>dis[x]+w[i])
			{
				tme[ver[i]]=tme[x]+1;
				if(tme[ver[i]]>n)
				{
					flag=1;
					break;
				}
				dis[ver[i]]=dis[x]+w[i];
				if(!book[x])
				{
					q.push(node(ver[i],dis[ver[i]]));
					book[ver[i]]=1;
				}
			}
		}
	}
	if(flag) cout<<"NO"<<endl;
	else
	{
		for(int i=1;i<=n;i++) write(dis[i]);
	}
	return 0;
}


