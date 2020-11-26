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
}a[500010];
bool table[500010][500010];
bool succ;
vector<int>c;
bool book[500010];
void dfs(int depth)
{
	if(succ) return;
	if(depth>n){
		succ=1;
		for(int i=0;i<c.size();i++) cout<<i<<" ";
		return;
	}
	for(int i=0;i<=n;i++)
	{
		if(table[depth][i])
		if(!book[b[depth][i]])
		{
			book[b[depth][i]]=1;
			c.push_back(b[depth][i]);
			dfs(depth+1);
			c.pop_back();
			book[b[depth][i]]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0,l,r,v;i<m;i++){
		cin>>l>>r>>v;
		for(int j=l;j<=r;j++) for(int k=0;k<v;k++) table[j][k]=1;
	}
	dfs(0);
	if(!succ) cout<<"-1";
	return 0;
}

