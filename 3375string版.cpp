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
using namespace std;

template<class T>inline void read(T&x)
{
	int fu=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-') fu=-1,ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=fu;
}
inline int read()
{
	int x=0,fu=1;
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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
string a,b;
int nxt[1000010];
int main()
{
	cin>>a>>b;
	int j=-1;
	nxt[0]=-1;
	for(int i=1;i<b.size();i++)
	{
		while(j>-1&&b[i]!=b[j+1]) j=nxt[j];
		if(b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
	j=-1;
	for(int i=0;i<a.size();i++)
	{
		while(j>-1&&a[i]!=b[j+1]) j=nxt[j];
		if(a[i]==b[j+1]) j++;
		if(j==b.size()-1){
			cout<<i-b.size()+2<<endl;
			j=nxt[j];
		}
	}
	for(int i=0;i<b.size();i++) cout<<nxt[i]+1<<" ";
	return 0;
}
