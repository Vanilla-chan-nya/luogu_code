/**************************************************************
 * Problem:
 * Author: Vanilla_chan
 * Date:
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
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}

int n,m;
int a[100010];
int cnt[1000011],mx;
#define p 19260817
int main()
{
	freopen("5071.in","r",stdin);
	freopen("5071.ans","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
//	debug
//	cout<<"n="<<n<<" m="<<m<<endl;
	for(int i=1,l,r;i<=m;i++)
	{
		l=read();
		r=read();
//		cout<<"l="<<l<<" r="<<r<<endl;
		memset(cnt,0,sizeof(cnt));
		mx=10;
		for(int j=l,x;j<=r;j++)
		{
			x=a[j];
			for(int k=2;k<=x;k++)
			{
				
				while(x%k==0)
				{
//					cout<<k<<" ";
					x/=k;
					cnt[k]++;
					mx=max(mx,k);
				}
			}
//			cout<<endl;
		}
//		debug
		LL ans=1;
		for(int j=1;j<=mx;j++)
		{
			ans=ans*(cnt[j]+1)%p;
		}
		write(ans);
	}
	return 0;
}



