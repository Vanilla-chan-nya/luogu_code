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
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m,s,sum;
int a[2000010];
char ch;
int x,y;
void ask()
{
	re int l=1,r=1;
	x=a[1];
	if(sum==s)
	{
		cout<<"1 "<<n<<endl;
		return;
	}
	if(s>=1&&s<=sum)
	while(l<=n&&r<=n)
	{
		if(x==s){
			cout<<l<<" "<<r<<endl;
			return;
		}
		if(x>s&&l<=r) x-=a[l],l++;
		else r++,x+=a[r];
	}
	cout<<"none\n";
}
int main()
{
	n=read();
	m=read();
	for(re int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	while(m--)
	{
		do{
			ch=getchar();
		}while(ch!='A'&&ch!='C');
		if(ch=='C')
		{
			x=read();
			sum-=a[x];
			a[x]=read();
			sum+=a[x];
		}
		else
		{
			s=read();
			ask();
		}	
	}
	return 0;
}

