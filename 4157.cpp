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
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n; 
int three,two;
int a[50010];
IL void upd()
{
	for(int i=0;i<5000;i++) a[i+1]+=a[i]/10,a[i]%=10;
}
int main()
{
	n=read();
	if(n%3==0) three=n/3;
	else if(n%3==1) two=2,three=(n-4)/3;
	else two=1,three=(n-1)/3;
	a[0]=1;
	for(int i=1;i<=three;i++)
	{
		for(int j=0;j<5000;j++)	a[j]*=3;
		upd();
	}
	for(int i=1;i<=two;i++)
	{
		for(int j=0;j<5000;j++)	a[j]*=2;
		upd();
	}
	upd();
	bool flag=0;
	int w=0;
	for(int i=5000;i>=0&&i>=w-100;i--)
	{
//		cout<<"i="<<i<<" a[i]="<<a[i]<<endl;
		if(a[i])
		{
			if(flag==0) cout<<i+1<<endl,w=i+1;
			flag=1;
		}
		if(flag) printf("%d",a[i]);
	}
	return 0;
}


