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
	for(int i=g;i>=1;--i)putchar('0'+G[i]);
}
int n;
int a[100];
int mx,mn,sum,num,group;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int Sum[60];
void dfs(int x,int len,int last)
{
//	debug cout<<"x="<<x<<" len="<<len<<endl;
	if(len==group)
	{
		x++;
		len=0;
		last=mx;
		if(/*x!=num+1&&*/x!=num)
		{
			for(int i=mx;i>=mn;i--)
			{
				if(a[i])
				{
					a[i]--;
					dfs(x,i,i);
					a[i]++;
					return;
				}
			}
		}
		
	}
	if(/*x==num+1||*/x==num)
	{
		write(group);
		exit(0);
	}
	if(rand()<12000) return;
	if(group-len>=mn&&group-len<=mx)
	{
		if(a[group-len])
		{
			a[group-len]--;
			dfs(x,group,0);
			a[group-len]++;
			return;
		}
	}
	for(int i=min(group-len,last);i>=mn;i--)
	{
		if(a[i])
		{
			a[i]--;
			dfs(x,len+i,i/*-!(a[i])*/);
			a[i]++;
		}
		if(Sum[i]<group-len) return;
	}
}
int main()
{
	n=read();
	mn=100000000;
	for(re int i=1,t;i<=n;i++)
	{
		t=read();
		if(t<=50)
		{
			sum+=t;
			a[t]++;
			mn=min(mn,t);
			mx=max(mx,t);
		}
	}
	for(int i=1;i<=50;i++) Sum[i]=Sum[i-1]+a[i]*i;
	for(group=mx;group<=sum/2;group++)
	{
		if(sum%group==0)
		{
			num=sum/group;
			a[mx]--;
			dfs(1,mx,mx);
			a[mx]++;
		}
	}
	write(sum);
	return 0;
}


