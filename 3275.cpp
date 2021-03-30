/**************************************************************
 * Problem: 3275
 * Author: Vanilla_chan
 * Date: 20210330
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
#define int long long
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

#define N 500010
int n,m,s;
int head[N],ver[N<<1],cnt[N],nxt[N<<1],w[N<<1],dis[N],book[N];
int tot;
void insert(int x,int y,int z)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	w[tot]=z;
	ver[tot]=y;
}
struct node
{
	int x,dis;
	node(int xx,int vv)
	{
		x=xx,dis=vv;
	}
	IL bool operator<(const node&z)const
	{
		return dis<z.dis;
	}
};
priority_queue<node>q;
LL ans;
signed main()
{
// 	freopen("P3275_7.in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	m=read();
	s=n+1;
	for(int i=1;i<=n;i++)
	{
		dis[i]=-1;
		insert(s,i,0);
	}
	for(int i=1,x,a,b;i<=m;i++)
	{
		x=read();
		a=read();
		b=read();
		if(x==1)
		{
			insert(a,b,0);
			insert(b,a,0);
		}
		else if(x==2)
		{
			insert(a,b,1);
		}
		else if(x==3)
		{
			insert(b,a,0);
		}
		else if(x==4)
		{
			insert(b,a,1);
		}
		else if(x==5)
		{
			insert(a,b,0);
		}
		if(x%2==0&&a==b)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	int x;
	q.push(node(s,0));
	while(!q.empty())
	{
		x=q.top().x;
		q.pop();
//		debug cout<<"x="<<x<<" dis="<<dis[x]<<endl;
		book[x]=0;
		for(int i=head[x],v;i;i=nxt[i])
		{
			v=ver[i];
			if(dis[v]<dis[x]+w[i])
			{
				dis[v]=dis[x]+w[i];
				if(!book[v])
				{
					if(cnt[v]>n)
					{
						cout<<"-1";
						return 0;
					}
					
					q.push(node(v,dis[v])),book[v]=1,cnt[v]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) ans+=dis[i];
	write(ans+n);
	return 0;
}

