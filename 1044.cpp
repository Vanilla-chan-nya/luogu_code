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
int n;
LL ans;
int a,b,c;
int memory[1000000];
bool had[1000000];
int calc()
{
	return a*20+b;
}
int dfs()
{
	if(had[calc()]) return memory[calc()]; 
	int res=0;
	if(c==n) return 1;
	if(a){
		b++;
		a--;
		res+=dfs();
		a++;
		b--;
	}
	if(b){
		c++;
		b--;
		res+=dfs();
		c--;
		b++;
	}
	had[calc()]=1;
	return memory[calc()]=res;
} 
int main()
{
	cin>>n;
	a=n;
	cout<<dfs();
	return 0;
}

