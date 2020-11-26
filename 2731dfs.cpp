#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
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
int map[600][600];
int m;
int degree[600];
vector<int>way;
bool succ;
void dfs(int depth,int x)
{
//	cout<<"dfs dep="<<depth<<" x="<<x<<endl;
	if(succ) return;
	if(depth==m)
	{
		for(int i=0;i<way.size();i++)
		{
			cout<<way[i]<<endl;
		} 
		succ=1;
		return;
	}
	for(int i=1;i<=500;i++)
	{
		if(map[x][i])
		{
			way.push_back(i);
			map[x][i]--;map[i][x]--;
			dfs(depth+1,i);
			way.pop_back();
			map[x][i]++;map[i][x]++;
		}
	}
}
int main()
{
//	freopen("P2731_6.in","r",stdin);
	m=read();
	for(int i=1,a,b;i<=m;i++)
	{
		a=read();
		b=read();
		map[a][b]++;map[b][a]++;
		degree[a]++;
		degree[b]++;
	}
	int flag=0;
	for(int i=1;i<=500;i++) if(degree[i]) {flag=i;break;}
	for(int i=1;i<=500;i++) if(degree[i]&1) {flag=i;break;}
	cout<<flag<<endl;
	dfs(0,flag);
	return 0;
}
