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
int sum[3000010];
int nxt[3000010];
char ch[3000010];
int r[3000010];
int ans;
char s[3000010];
int n,m;


/*
20 2
cbcaacabcbacbbabacca ba


*/
int main()
{
	n=read();
	m=read();
	ch[0]='$';
	scanf("%s%s",ch+1,s+1);
	for(int i=2,j=0;i<=m;i++)
	{
		while(j&&s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) j++;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&ch[i]!=s[j+1]) j=nxt[j];
		if(ch[i]==s[j+1]) j++;
		if(j==m) sum[i-m+1]++;
	}
//	for(int i=1;i<=n;i++) cout<<sum[i];
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(int i=1,p=1,mx=1;i<=n;i++)
	{
		r[i]=i<mx?min(mx-i,r[2*p-i]):1;
		while(ch[i-r[i]]==ch[i+r[i]]) r[i]++;
		if(mx<i+r[i])
		{
			mx=i+r[i];
			p=i;
		}
		ans+=sum[i+r[i]-1-m+1]-sum[i-r[i]-1];
	}
	write(ans);
	return 0;
}


