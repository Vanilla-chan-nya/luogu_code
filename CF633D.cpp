#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<tr1/unordered_map>
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
int n;
#define N 1010
int a[N];
/*tr1::unordered_*/map<int,int>s,temp;
int ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),s[a[i]]++;
	if(s.find(0)!=s.end()) ans=max(ans,s[0]);
	sort(a+1,a+n+1);
	for(re int i=1;i<=n;i++)
	for(re int j=1;j<=n&&(i<=1||a[i]!=a[i-1]);j++)
	{
		if(i==j) continue;
		if(a[i]==0&&a[j]==0) continue;
		temp.clear();
		int cnt=2;
		int x=a[j],y=a[i]+a[j];
		temp[a[i]]++;temp[a[j]]++;
		while(temp[y]<s[y])
		{
			cnt++;
			temp[y]++;
			x^=y^=x^=y;
			y+=x;
		}
		ans=max(ans,cnt);
	}
	write(ans);
	return 0;
}


