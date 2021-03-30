/**************************************************************
 * Problem: 1038
 * Author: Vanilla_chan
 * Date: 20210329
 * E-Mail: Vanilla_chan@outlook.com
**************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
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
};
using namespace oi;

#define N 100
int n,p;
int u[N],c[N];
int head[N],ver[N*N],nxt[N*N],w[N*N];
int cnt;
void insert(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	w[cnt]=z;
}
int in[N],out[N],q[N];
int l,r,x;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	p=read();
	l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		oi::cin>>c[i]>>u[i];
		if(c[i]) q[++r]=i;
		else c[i]-=u[i];
	}
	for(int i=1,a,b;i<=p;i++)
	{
		a=read();
		b=read();
		insert(a,b,read());
		in[b]++;
		out[a]++;
	}
	while(l<=r)
	{
		x=q[l];
		l++;
		for(int i=head[x];i;i=nxt[i])
		{
			if(c[x]>0&&in[ver[i]])
			{
				c[ver[i]]+=c[x]*w[i];
			}
			in[ver[i]]--;
			if(in[ver[i]]==0) q[++r]=ver[i];
			
		}
	}

	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!out[i]&&c[i]>0) flag=1;
	}
	if(flag)
	{
		for(int i=1;i<=n;i++) if(!out[i]&&c[i]>0) cout<<i<<" "<<c[i]<<endl;
	}
	else cout<<"NULL";
	return 0;
}


