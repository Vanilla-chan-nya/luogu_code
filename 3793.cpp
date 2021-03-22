/**************************************************************
 * Problem: 3793
 * Author: Vanilla_chan
 * Date: 20210321
 * E-Mail: Vanilla_chan@outlook.com
**************************************************************/
#include<iostream>
#include<algorithm>
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
namespace GenHelper
{
	unsigned z1,z2,z3,z4,b;
	unsigned rand_()
	{
		b=((z1<<6)^z1)>>13;
		z1=((z1&4294967294U)<<18)^b;
		b=((z2<<2)^z2)>>27;
		z2=((z2&4294967288U)<<2)^b;
		b=((z3<<13)^z3)>>21;
		z3=((z3&4294967280U)<<7)^b;
		b=((z4<<3)^z4)>>12;
		z4=((z4&4294967168U)<<13)^b;
		return (z1^z2^z3^z4);
	}
}
void srand(unsigned x)
{
	using namespace GenHelper;
	z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;
}
int read()
{
	using namespace GenHelper;
	int a=rand_()&32767;
	int b=rand_()&32767;
	return a*32768+b;
}
#define N 20000010
int n,m,s;
struct node
{
	int x,pos;
	node(int xx=0,int y=0)
	{
		x=xx;
		pos=y;
	}
	IL bool operator<(const node&z)const
	{
		return x>z.x;
	}
}a[N];
ULL ans;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=oi::read();
	m=oi::read();
	s=oi::read();
	srand(s);
	for(int i=1;i<=n;i++) a[i]=node(::read(),i);
	sort(a+1,a+n+1);
	int l,r;
	while(m--)
	{
		l=::read()%n+1;
		r=::read()%n+1;
		if(l>r) l^=r^=l^=r;
		for(int i=1;i<=n;i++)
		{
			if(a[i].pos<=r&&a[i].pos>=l)
			{
				ans+=a[i].x;
				break;
			}
		}
	}
	write(ans);
	return 0;
}


