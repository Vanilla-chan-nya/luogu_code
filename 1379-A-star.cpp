#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<ctime>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
using namespace std;

template<class T>inline void read(T&x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
const string goal="123804765";
int dt[4][2]={1,0,-1,0,0,1,0,-1};
int limit;
bool succ;
int test(string x)
{
	int ans=0;
	for(int i=0,j;i<x.size();i++)
	{
		if(x[i]=='0') continue;
		j=goal.find(x[i]);
		ans+=abs(j/3-i/3)+abs(j%3-i%3);
	}
	return ans;
}
void A_star(string x,int step)
{
	if(step+test(x)>limit) return;
	if(step==limit)
	{
		if(x==goal) succ=1;
		return;
	}
	if(succ) return;
	int zero=x.find('0'),zt;
	for(int way=0;way<4;way++)
	{
		zt=dt[way][0]*3+dt[way][1]+zero;
		if(zt<0||zt>=9) continue;
		swap(x[zt],x[zero]);
		A_star(x,step+1);
		swap(x[zt],x[zero]);
	}
}
int main()
{
	string str;
	cin>>str;
	if(str==goal)
	{
		write(0);
		return 0;
	}
	while(++limit)
	{
		A_star(str,0);
		if(succ)
		{
			write(limit);
			return 0;
		}
	}
	return 0;
}


