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
int head[5010],ver[10010],nxt[10010],w[10010];
int cnt1;
void insert(int z,int x,int y)
{
//	cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;	
	nxt[++cnt1]=head[x];
	head[x]=cnt1;
	ver[cnt1]=y;
	w[cnt1]=z;
}
int dis[5010];
struct node
{
	int p;
	IL bool operator<(const node & z)const
	{
		return p>z.p;
	}
};
priority_queue<node>q;
bool book[5010];
int cnt[5010];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		insert(read(),read(),read());
	}
	int s=n+1,x;
	for(int i=1;i<=n;i++)
	{
		insert(0,s,i);
		dis[i]=10000000;
	}
	q.push((node){s});
	bool flag=0;
	book[s]=1;
	while(!q.empty()&&!flag)
	{
		x=q.top().p;
		q.pop();
		book[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
//			debug
			if(dis[ver[i]]>dis[x]+w[i])
			{
				dis[ver[i]]=dis[x]+w[i];
				cnt[ver[i]]=cnt[x]+1;
				if(cnt[ver[i]]>n)
				{
					flag=1;
					break;
				}
				if(!book[ver[i]]) book[ver[i]]=1,q.push((node){ver[i]});
			}
		}
	}
	if(flag) cout<<"NO";
	else 
	{
		for(int i=1;i<=n;i++) write(dis[i]);
	}
	return 0;
}


