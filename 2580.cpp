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

struct Trie
{
	int son[26],flag;
	bool exist;
}trie[2000010];
int trie_cnt;
void insert(string str)
{
	int now=0;
	for(int i=0;i<str.size();i++)
	{
		if(!trie[now].son[str[i]-'a']) trie[now].son[str[i]-'a']=++trie_cnt;
		now=trie[now].son[str[i]-'a'];
	}
	if(!trie[now].exist) trie[now].exist=true;
}
int find(string str)
{
	int now=0;
	for(int i=0;i<str.size();i++)
	{
		if(!trie[now].son[str[i]-'a']) return -1;
		now=trie[now].son[str[i]-'a'];
	}
	if(!trie[now].exist) return -1;
	return trie[now].flag++;
}
int n,m;
int main()
{
	cin>>n;
	string t;
	int x;
	for(int i=0;i<n;i++) cin>>t,insert(t);
	cin>>m;
	while(m--)
	{
		cin>>t;
		x=find(t);
		if(x==-1) cout<<"WRONG"<<endl;
		else if(x) cout<<"REPEAT"<<endl;
		else cout<<"OK"<<endl;
	}
	return 0;
}

