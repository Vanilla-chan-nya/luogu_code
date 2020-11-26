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
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

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

double ans; 
LL n,m;
int main()
{
	n=read();
	m=read();
	if(n>100000000) cout<<(LL)(m*(log(n)+0.5772156649)/2-(1e-6))<<endl;
	else
	{
		for(LL i=1;i<=n;i++) ans+=0.5/i;
		cout<<(LL)(ans*m-(1e-6))<<endl;
	}
	return 0;
}

