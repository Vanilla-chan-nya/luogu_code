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
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,m;
struct lr{
	int l,r,val;
	#define l(x) a[x].l 
	#define r(x) a[x].r 
	#define v(x) a[x].val 
}a[500010];
bool ta[500010]; 
int f[500010];
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>l(i)>>r(i)>>v(i);
	}
	for(int i=0;i<=n;i++) f[i]=i;
	bool succ=0;
	do{
		succ=1;
		for(int i=0;i<m&&succ;i++)
		{
			memset(ta,0,sizeof(ta));
			for(int j=l(i);j<=r(i);j++)
			{
				ta[f[j]]=1;
			}
			bool flag=1;
			for(int j=0;j<v(i)&&flag;j++) if(ta[j]==0) flag=0;
			if(!flag){
				succ=0;
			}
		}
		if(!succ) continue;
		for(int i=0;i<=n;i++) cout<<f[i]<<" ";
		break;
	}while(next_permutation(f,f+n+1));
	if(!succ) cout<<"-1";
	return 0;
}

