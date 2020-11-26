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
inline int read()
{
	int x=0;
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
int q;
LL a[4];
int main()
{
	cin>>q;
	while(q--)
	{
		for(int i=0;i<4;i++) cin>>a[i];
		sort(a,a+4);
		if(a[0]==a[3])
		{
			cout<<"1"<<endl;
			continue;
		}
		if(a[0]+a[3]!=a[1]+a[2])
		{
			cout<<"0"<<endl;
			continue;
		}
		if(a[0]==a[1])
		{
			cout<<"4"<<endl;
			continue;
		}
		else
		{
			cout<<"8"<<endl;
			continue;
		}
		
	}
	
	return 0;
}

