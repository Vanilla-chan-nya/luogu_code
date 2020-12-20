#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
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
int ans;
int a,b,c;
int res(char ch)
{
	if(ch>='0'&&ch<='9') return ch-'0';
	return ch-'A'+10;
}
int main()
{
	getchar();
	cout<<"#";
	a=res(getchar())*16+res(getchar());
	b=res(getchar())*16+res(getchar());
	c=res(getchar())*16+res(getchar());
//	cout<<a<<" "<<b<<" "<<c<<endl;
	a=255-a;
	b=255-b;
	c=255-c;
//	cout<<a<<" "<<b<<" "<<c<<endl;
	cout<<setiosflags(ios::uppercase)<<setw(2)<<setfill('0')<<hex<<a<<setw(2)<<setfill('0')<<hex<<b<<setw(2)<<setfill('0')<<hex<<c;
	return 0;
}


