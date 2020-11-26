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
int n,m;
int k[310],s[310];
vector<int>son[310];
int f[310][310];
void dfs(int now)
{
//	cout<<"dfs "<<now<<endl;
	f[now][1]=s[now];//初始化为自己的得分 
	for(int i=0;i<son[now].size();i++)
	{
//		cout<<"predfs now="<<now<<" i="<<i<<" son="<<son[now][i]<<endl;
		dfs(son[now][i]);//先把子树遍历完 
		for(int j=m+1;j>=1;j--)//j>=1:至少要选择now，这样这个f才有意义 
		{
			for(int k=0;k<j;k++)
			{
				f[now][j]=max(f[now][j],f[now][j-k]+f[son[now][i]][k]);
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i]>>s[i],son[k[i]].push_back(i);
	dfs(0);
	cout<<f[0][m+1];
	return 0;
}

