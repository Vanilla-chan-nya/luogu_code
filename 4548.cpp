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
int t,n,m,ans;
int ch[100010];
int nxt[100010];
#define mod 10000
int pown[100010];
int main()
{
	n=read();
	t=read();
	for(int i=pown[0]=1;i<=100010;i++)
	{
		pown[i]=pown[i-1]*n%mod;
	}
	while(t--)
	{
		memset(nxt,0,sizeof(nxt));
		memset(ch,0,sizeof(ch));
		ans=0;
		m=read();
		for(int i=1;i<=m;i++)
		{
			cin>>ch[i];
		}
		for(int i=2,j=0;i<=m;i++)
		{
			while(j&&ch[i]!=ch[j+1]) j=nxt[j];
			if(ch[i]==ch[j+1]) j++;
			nxt[i]=j;
		}
		for(int i=m;i;i=nxt[i]) ans=(ans+pown[i])%mod;
		if(ans<1000) putchar('0');
		if(ans<100) putchar('0');
		if(ans<10) putchar('0');
		cout<<ans<<endl;
	}
	
	return 0;
}


