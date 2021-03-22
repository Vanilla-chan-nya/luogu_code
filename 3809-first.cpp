/**************************************************************
 * Problem: 3809
 * Author: Vanilla_chan
 * Date: 20210311
**************************************************************/
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

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
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
#define N 1000100
char s[N];
int n,m;
int sa[N],x[N],y[N],c[N];
void work()
{
	for(int i=1;i<=n;i++) c[x[i]=s[i]]++;//c is bucket
	for(int i=2;i<=m;i++) c[i]+=c[i-1];//c????,?????????????? 
	for(int i=n;i>=1;i--) sa[c[x[i]]--]=i;//?????????sa
	for(int k=1;k<=n;k<<=1)
	{
		int num=0;
		for(int i=n-k+1;i<=n;i++) y[++num]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) y[++num]=sa[i]-k;
		for(int i=1;i<=m;i++) c[i]=0;//init
		for(int i=1;i<=n;i++) c[x[i]]++;
		for(int i=2;i<=m;i++) c[i]+=c[i-1];//c????,?????????????? 
		for(int i=n;i>=1;i--) sa[c[x[y[i]]]--]=y[i],y[i]=0;
		swap(x,y);
		x[sa[1]]=1;
		num=1;
		for(int i=2;i<=n;i++)
		{
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num ;
		}
		if(num==n) break;
		m=num;
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	m='z';
	work();
	for(int i=1;i<=n;i++) cout<<sa[i]<<" ";
	return 0;
}


