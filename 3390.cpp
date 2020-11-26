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
#define re register
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

template<class T>inline void read(T&x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline LL read()
{
	re LL x=0,fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar(' ');
}
struct matrix{
	LL a[110][110];
	LL size;
	matrix()
	{
		memset(a,0,sizeof(a));
		size=0;
	}
	matrix(LL x)
	{
		size=x;
		for(LL i=0;i<=size;i++)
		for(LL j=0;j<=size;j++)
			a[i][j]=0;
	}
	void make(LL x=0)
	{
		memset(a,0,sizeof(a));
		size=x;
		for(LL i=1;i<=size;i++) a[i][i]=1;
	}
//	LL * operator[](int x)
//	{
//		return a[x];
//	}
	matrix operator %(const LL & mod)
	{
		matrix rec=*this;
		for(LL i=1;i<=size;i++)
		for(LL j=1;j<=size;j++)
			rec.a[i][j]%=mod;
		return rec;
	}
	matrix operator %=(const LL & mod)
	{
		for(LL i=1;i<=size;i++)
		for(LL j=1;j<=size;j++)
			a[i][j]%=mod;
		return *this;
	}
	matrix operator *(matrix & b)
	{
		matrix c(size);
		for(LL i=1;i<=size;i++)
		for(LL j=1;j<=size;j++)
		for(LL k=1;k<=size;k++)
		{
			c.a[i][j]+=a[i][k]*b.a[k][j];
			c.a[i][j]%=1000000007;
		}
		return c;
	}
	IL matrix operator *=(matrix & b)
	{
		*this=*this*b;
		return *this;
	}
	matrix pow(LL k,LL mod)
	{
//		cout<<"pow\n*this.size="<<size<<endl;
		matrix ans(size),a(size);
//		cout<<"ans.size="<<ans.size<<endl;
		ans.make(size);//ans=1;
		a=*this;
		while(k)
		{
			if(k&1) ans*=a,ans%=mod;
			a=a*a%mod;
			k>>=1;
		}
//		cout<<"ans.size="<<ans.size<<endl;
		return ans%mod;
	}
	matrix input()
	{
//		cout<<"input\n";
		for(re LL i=1;i<=size;i++)
		for(re LL j=1;j<=size;j++)
		{
			a[i][j]=read();
		}
		return *this;
	}
	void output()
	{
//		cout<<"output\nsize="<<size;
		for(re LL i=1;i<=size;i++)
		{
			for(re LL j=1;j<=size;j++)
				write(a[i][j]);
			putchar('\n');
		}
	}
};
LL n,k;
int main()
{
	n=read();
	k=read();
	matrix A(n);
	A.input();
	(A.pow(k,1000000007)).output();
	return 0;
}

