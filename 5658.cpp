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
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
LL n;
LL fa[500005];
char ch[500005];
LL f[500005];
LL s[500005];
LL a[500005];
LL sum[500005];
LL top;
LL head[500005],ver[500005],nxt[500005];
LL cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
}



void dfs(LL x)
{
//	debug cout<<"x="<<x<<endl;
	LL t=0;
	if(ch[x]==')'&&top)
	{
		t=s[top];
		top--;
		a[x]=a[fa[t]]+1;
	}
	if(ch[x]=='(') s[++top]=x;
	sum[x]=sum[fa[x]]+a[x];
	for(LL i=head[x];i;i=nxt[i])
	{
		dfs(ver[i]);		
	}
	if(t!=0) s[++top]=t;
	else if(top) top--;
}
int main()
{
	n=read();
	string str;cin>>str;
	for(LL i=1;i<=n;i++)
	{
		ch[i]=str[i-1];
	}
	for(LL i=2;i<=n;i++) fa[i]=read(),insert(fa[i],i);
	dfs(1);
	LL ans=0;
	for(LL i=1;i<=n;i++) ans^=i*sum[i];
	cout<<ans;
	return 0;
}

