/**************************************************************
 * Problem: 1337
 * Author: Vanilla_chan
 * Date: 20210323
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
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isdigit(ch);ch=getchar());
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


int n;
struct vec
{
	double x,y;
	vec(double xx=0,double yy=0)
	{
		x=xx;
		y=yy;
	}
	double size()
	{
		return sqrt(x*x+y*y);
	}
	vec operator+(const vec& z)
	{
		return vec(x+z.x,y+z.y);
	}
	vec operator-(const vec& z)
	{
		return vec(x-z.x,y-z.y);
	}
	vec operator+=(const vec& z)
	{
		x+=z.x;
		y+=z.y;
		return *this;
	}
	vec operator-=(const vec& z)
	{
		x-=z.x;
		y-=z.y;
		return *this;
	}
	vec operator*(const double& z)
	{
		return vec(x*z,y*z);
	}
	vec operator*=(const double& z)
	{
		return *this=*this*z;
	}
};
vec operator*(const double& b,const vec& a)
{
	return vec(a.x*b,a.y*b);
}
struct Thing
{
	vec xy;
	double z;
	void in()
	{
		xy.x=read();
		xy.y=read();
		z=read();
	}
}thing[2000];
#define down 0.95;
vec ans,last;
bool dX,dY;
const double eps=1e-5;
double T=1000;
void calc()
{
	vec t,d;
	for(int i=1;i<=n;i++)
	{
		t=ans-thing[i].xy;
		if(t.size()==0) continue;
		d+=thing[i].z/t.size()*(thing[i].xy-ans);
	}
	ans+=T/d.size()*d;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) thing[i].in();
	
	while(1)
	{
		//cout<<ans.x<<" "<<ans.y<<endl;
		last=ans;
		calc();
		if((ans-last).size()<=eps) break;
		if(dX!=(ans.x>last.x)||dY!=(ans.y>last.y))
		{
			dX=!(ans.x>last.x);
			dY=!(ans.y>last.y);
			T*=down;
		}
	}



	printf("%.3lf %.3lf",ans.x,ans.y);
	return 0;
}


