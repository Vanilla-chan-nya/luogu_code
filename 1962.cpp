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
#define LL ULL
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
	LL x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    int g=0;
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
map<LL,LL>fbnq;
#define P 1000000007
LL f(LL n)
{
	if(n<=2) return 1;
	if(n==3) return 2;
	if(fbnq.find(n)!=fbnq.end()) return fbnq[n];
	LL a,b,ans,num=n>>1;
	if(n&1)
	{
		a=f(num+1);
		b=f(num);
		ans=a*a+b*b;
		ans%=P;
//		ans=f(num+1)*f(num+1)%P;
//		ans+=f(num)*f(num)%P;
	}
	else
	{
		a=f(num);
		b=f(num-1);
		ans=a*(a+2*b);
		ans%=P;
//		ans=2*f(num-1)%P+f(num);
//		ans%=P;
//		ans*=f(num);
	}
	fbnq[n]=ans;
	return ans;
}
int main()
{
	write(f(read()));
	return 0;
}
