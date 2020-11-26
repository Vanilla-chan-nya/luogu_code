#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<tr1/unordered_map>
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

const LL p = 998244353;
string str;
LL n,k,sum;
LL f[20][2000][2000];
int main()
{
	cin>>n>>k>>str;
	for(int l=0;l<str.size();l++)
	{
		int L=0;
		for(int r=l;r<str.size();r++)
		{
			if(str[r]=='(') L++;
			if(str[r]==')') L--;
			if(L<0) f[0][l][r]++,L++;
			f[0][l][r]+=L;
//			cout<<"l="<<l<<" r="<<r<<" f="<<f[0][l][r]<<endl;
		}
		
	}
	for(int i=1;i<=k;i++)
	{
		for(int l=0;l<n;l++)
		for(int r=0;r<n;r++) 
			f[i][l][r]=0; 
		for(int L=0;L<n;L++)
		{
			for(int R=L;R<n;R++)
			{
				for(int l=L;l<=R;l++)
				{
					for(int r=l;r<=R;r++)
					{
						f[i][L][R]+=f[i-1][l][r];
					}
				}
			}
		}
	}
	cout<<f[k][0][n-1];
	return 0;
}

