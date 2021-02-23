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
inline LL read()
{
	LL x=0,fu=1;
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
#define mod 19930726
LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
LL WS[2000010];
int r[2000010];
int n;
LL k,ans;
char ch[2000010];
int main()
{
	n=read();
	k=read();
	cin>>(ch+1);
	for(int i=n;i>=1;i--) ch[i*2]=ch[i],ch[i*2+1]='#';ch[1]='#';ch[0]='$';
	for(int i=1,mx=1,p=1;i<=2*n+1;i++)
	{
		r[i]=i<mx?min(mx-i,r[2*p-i]):1;
		while(ch[i+r[i]]==ch[i-r[i]]) r[i]++;
		if(i+r[i]>mx)
		{
			mx=i+r[i];
			p=i;
		}
		WS[r[i]-1]++;
	}
	ans=1;
	for(int i=n,sum=0;i>=1;i--)
	{
		if((i&1)==0) continue;
		sum+=WS[i];
		k-=sum;
		if(k<=0)
		{
			k+=sum;
			ans=ans*qpow(i,k);
			k=0;
			break;
		}
		else
		{
			ans=ans*qpow(i,sum);
		}
		ans%=mod;
	}
	if(k>0) write(-1);
	else write(ans%mod);
	return 0;
}


