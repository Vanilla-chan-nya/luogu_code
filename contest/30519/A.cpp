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
LL n,t,cnt,maxans;
bool book[200][200];
IL void init()
{
	memset(book,0,sizeof(book));
	maxans=0;
}
void dfs(int now,int ans)
{
	for(int i=1;i<=n;i++)
	{
		if(i==now) continue;
		if(book[i][now]==0&&book[now][i]==0)
		{
			book[i][now]=book[now][i]=1;
			dfs(i,ans+1);
			book[i][now]=book[now][i]=0;
		}
	}
	if(ans>maxans) maxans=ans;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
//		init();
//		dfs(1,0);
//		cout<<maxans<<endl;
		if(n&1) cout<<n*(n-1)/2<<endl;
		else cout<<n*(n-2)/2+1<<endl;
	}
	return 0;
}

