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
struct AC
{
	int cnt,n;
	int trie[200010][30];
	int fail[200010];
	int v[200010];
	int in[200010];
	string a[200010];
	int ys[200010];//string node->pos
	void clear()
	{
		cnt=0;
		memset(trie,0,sizeof(trie));
		memset(fail,0,sizeof(fail));
		memset(v,0,sizeof(v));
	}
	void input(int nn)
	{
		clear();
		n=nn;
		for(int i=0,pos;i<n;i++)
		{
			cin>>a[i];
			pos=0;
			for(int j=0;j<a[i].size();j++)
			{
				if(!trie[pos][a[i][j]-'a']) trie[pos][a[i][j]-'a']=++cnt;
				pos=trie[pos][a[i][j]-'a'];
			}
			ys[i]=pos;
		}
	}
	int head[200010],nxt[200010],ver[200010];
	int failcnt;
	IL void insert(int x,int y)
	{
		nxt[++failcnt]=head[x];
		head[x]=failcnt;
		ver[failcnt]=y;
	}
	void init()
	{
		queue<int>q;
		for(int i=0;i<26;i++) if(trie[0][i]) q.push(trie[0][i]),insert(0,trie[0][i]);
		int x;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(int i=0;i<26;i++)
			{
				if(trie[x][i]) fail[trie[x][i]]=trie[fail[x]][i],q.push(trie[x][i]),insert(trie[fail[x]][i],trie[x][i]);//如果这个节点有i儿子，那么这个儿子的fail=父亲的fail的i儿子 
				else trie[x][i]=trie[fail[x]][i];//如果没有这个i儿子，那么就设这个儿子是父亲的fail的i儿子。 
			}
		}
	}
	IL void calc(string str)
	{
		int pos=0;
		for(int i=0;i<str.size();i++)
		{
			pos=trie[pos][str[i]-'a'];
			v[pos]++;
		}
	}
	IL void dfs(int x)
	{
		for(int i=head[x];i;i=nxt[i])
		{
			dfs(ver[i]);
			v[x]+=v[ver[i]];
		}
	}
	IL void output()
	{
		for(int i=0;i<n;i++)
		{
			write(v[ys[i]]);
		}
	}
}ac;
int n;
string t;
int main()
{
	n=read();
	ac.input(n);
	ac.init();
	cin>>t;
	ac.calc(t);
	ac.dfs(0);
	ac.output();
	return 0;
}


