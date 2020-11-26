#include<iostream>
#include<algorithm>
#include<cstdio>
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
#define re register
using namespace std;

template<class T>inline void read(T&x)

{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline LL read()
{
	LL x=0;
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
    do{G[++g]=x%10;x/=10;}while(x);
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
LL head[30010],ver[30010],w[30010],nxt[30010],dis[20010],recy[20010];
bool online[20010];
LL n,m,t,cnt;
struct node{
	LL p;
};
queue<node>q;
void insert(LL u,LL v,LL wi)
{
	cnt++;
	nxt[cnt]=head[u];
	ver[cnt]=v;
	w[cnt]=wi;
	head[u]=cnt;
}
void init()
{
	cnt=0;
	memset(head,0,sizeof(head));
	memset(online,0,sizeof(online));
	memset(ver,0,sizeof(ver));
	memset(w,0,sizeof(w));
	memset(nxt,0,sizeof(nxt));
	memset(recy,0,sizeof(recy));
	online[1]=1;
	recy[1]=1;
	memset(dis,63,sizeof(dis));
	dis[1]=0;
	while(!q.empty()) q.pop();
	q.push((node){1});
}
int main()
{
	cin>>t;
//	if(t==8)
//	{
//		for(int i=0;i<8;i++) cout<<"YE5\n";
//		return 0;
//	}
	while(t--)
	{
		cin>>n>>m;
		init();
		bool flag=0;
		for(LL i=0,a,b,c;i<m;i++)
		{
			cin>>a>>b>>c;
			if(a==b){
				if(c<0) flag=1;
				continue;
			}
			insert(a,b,c);
			if(c>=0) insert(b,a,c);
		}
		re int u;
		while(!q.empty()&&!flag)
		{
			u=q.front().p;
			q.pop();
			online[u]=0;
			for(int i=head[u],v;i;i=nxt[i])
			{
//				cout<<"updata:"<<ver[i]<<endl;
				v=ver[i];
				if(dis[v]>dis[u]+w[i])
				{
					dis[v]=dis[u]+w[i];
					recy[v]=recy[u]+1;
					if(recy[v]>2*n)
					{
						flag=1;
						break;
					}
					if(!online[v])
					{
						q.push((node){v});
						online[v]=1;
					}
				}
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
//		for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	}
	
	
	return 0;
}

