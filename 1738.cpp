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
map<string,int>trie[1010*60];
int n,cnt;
char ch;
string str;
int main()
{
	n=read();
	for(int i=1,pos;i<=n;i++)
	{
		pos=0;
		ch=getchar();
		while(ch!='/') ch=getchar();
		while(1)
		{
			if(ch=='\n'||ch=='\r')
			{
				if(!trie[pos][str]) trie[pos][str]=++cnt;
				pos=trie[pos][str];
				str.clear();
				break;
			}
			if(ch=='/')
			{
				if(!trie[pos][str]) trie[pos][str]=++cnt;
				pos=trie[pos][str];
				str.clear();
			}
			else str+=ch;
			ch=getchar();
		}
		write(cnt-1);
	}
	
	return 0;
}


