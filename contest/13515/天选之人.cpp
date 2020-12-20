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
int n,m,k,p;
int main()
{
	cin>>n>>m>>k>>p;
	if(p>n||(p==n&&k%n==0))
	{
		cout<<"NO";
		return 0;
	}
	bool flag=1;
	int mx;
	for(mx=0;mx<=m;mx++)
	{
		if(mx>ceil((k-mx*p*1.0)/(n-p*1.0))) 
		{
			flag=0;break;
		}
	}
	cout<<mx<<endl;
	if(flag) cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=p;i++) cout<<mx<<" "<<m-mx<<endl;
		
	}
	return 0;
}


