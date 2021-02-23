#include<bits/stdc++.h>
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
struct edge {
	int to,nxt,f;
}e[10010];
int n,m,s,t,h[210];
int cur[210];
int cnt=1;//
void add(int u,int v,int f) {
	e[++cnt]=(edge) {v,h[u],f};
	h[u]=cnt;
	e[++cnt]=(edge) {u,h[v],0};
	h[v]=cnt;
}
int dep[210];
long long ans;
bool bfs() {
	queue<int> q;
	memset(dep,0,sizeof(dep));
	q.push(s);
	int x,v;
	dep[s]=1;
	for(int i=1;i<=n;i++) cur[i]=h[i];
	while(!q.empty()) {
		x=q.front();
		q.pop();
		for(int i=h[x];i;i=e[i].nxt) {
			v=e[i].to;
			if(!e[i].f||dep[v]) continue;
			dep[v]=dep[x]+1;
			if(v==t) return 1;
			q.push(v);
		}
	}
	return 0;
}
int dinic(int x,int flow) {
	if(x==t) return flow;
	int res=flow;
	for(int i=cur[x];i;i=e[i].nxt) {
		cur[x]=i;
		int v=e[i].to;
		if(dep[v]!=dep[x]+1||!e[i].f) continue;
		int k=dinic(v,min(res,e[i].f));
		e[i].f-=k,e[i^1].f+=k;res-=k;
	}
	return flow-res;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m>>s>>t;
	for(int u,v,f,i=1;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&f);
		add(u,v,f);
	}
	while(bfs()) ans+=dinic(s,INT_MAX);
	printf("%lld",ans);
	return 0;
}


