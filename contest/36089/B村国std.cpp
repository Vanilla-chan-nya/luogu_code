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
	int x=0;
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
int head[4000010],nxt[4000010],ver[4000010],cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	ver[cnt]=y;
	head[x]=cnt;
	
	nxt[++cnt]=head[y];
	ver[cnt]=x;
	head[y]=cnt;
}
LL t,n,m,pos,mx,cpos,cmx;
int w[2000010];
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		cin>>m;
		cmx=mx=-1;
		for(re int i=1;i<=n;i++) 
		{
			w[i]=read();
			if(w[i]>mx) mx=w[i],pos=i;
		}
		for(re int i=1;i<n;i++)
		{
			insert(read(),read());
		}
		for(re int i=head[pos];i;i=nxt[i])
		{
			if(w[ver[i]]>cmx) cmx=w[ver[i]],cpos=ver[i];
		}
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		re LL i=1;
//		for(i=1;i<=m;i++)
//		{
//			if(mx==cmx) break;
//			if(cmx>mx) mx++;
//			else if(cmx<mx) cmx++;
//			else if(pos<cpos) cmx++;
//			else if(pos>cpos) mx++;
//		}
		i=mx-cmx-1;
		if(m<=i)
		{
			cout<<pos<<endl;
			continue;
		}
		cmx=mx;
//		if(i==m+1)
//		{
//			if(cmx>mx) cout<<cpos<<endl;
//			else if(mx>cmx) cout<<pos<<endl;
//			else cout<<min(pos,cpos)<<endl;
//		}
//		else
		{
			if(pos>cpos) swap(pos,cpos);
			if((m-i+1)&1) cout<<cpos<<endl;
			else cout<<pos<<endl;
		}
		
		
		
	}
	
	return 0;
}

