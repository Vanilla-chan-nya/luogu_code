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
int r[1000010];
int n;
int ll[1000010];
char ch[1000010];
int main()
{
	n=read();
	cin>>ch+1;
	ch[0]='$';
	for(int i=n;i>=1;i--) ch[i*2]=ch[i],ch[i*2+1]='#';ch[1]='#';ch[2*n+2]='\0';
	for(int i=1,mx=1,p=1;i<=2*n+1;i++)
	{
		r[i]=i<mx?min(mx-i,r[2*p-i]):1;
		while(ch[i-r[i]]==ch[i+r[i]]) r[i]++;
		if(mx<i+r[i])
		{
			mx=i+r[i];
			p=i;
		}
		ll[i+r[i]-1]=max(ll[i+r[i]-1],r[i]-1);
	}
	for(int i=2*n+1;i>=3;i--)
	{
		ll[i-2]=max(ll[i-2],ll[i]-2);
	}
	for(int i=1;i<=2*n+1;i++) cout<<ch[i];
	cout<<endl;
	for(int i=1;i<=2*n+1;i++) cout<<ll[i];
	return 0;
}


