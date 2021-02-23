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
	int cnt;
	int trie[1200000][30];
	int fail[1200000];
	int v[1200000];
	void insert(string str)
	{
		int pos=0;
		for(int i=0;i<str.size();i++)
		{
			if(!trie[pos][str[i]-'a']) trie[pos][str[i]-'a']=++cnt;
			pos=trie[pos][str[i]-'a'];
		}
		v[pos]++;
	}
	void init()
	{
		queue<int>q;
		for(int i=0;i<26;i++) if(trie[0][i]) q.push(trie[0][i]);
		int x;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(int i=0;i<26;i++)
			{
				if(trie[x][i]) //如果这个节点有i儿子，那么这个儿子的fail=父亲的fail的i儿子 
				{
					q.push(trie[x][i]);
					int j=fail[x];
					while(!j)
					{
						fail[trie[x][i]]=trie[j][i];
						if(fail[trie[x][i]]) break;
						j=fail[j];
					}
				}
				
				
				else trie[x][i]=trie[fail[x]][i];//如果没有这个i儿子，那么就设这个儿子是父亲的fail的i儿子。 
			}
		}
	}
	int calc(string str)
	{
		int ans=0,pos=0;
		for(int i=0,j;i<str.size();i++)
		{
			j=pos=trie[pos][str[i]-'a'];
			
			while(j&&v[j]!=-1)
			{
				ans+=v[j];
				v[j]=-1;
				j=fail[j];
			}
		}
		return ans;
	}
}ac;
int n;
string t;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ac.insert(t);
	}
	ac.init();
	cin>>t;
	cout<<ac.calc(t);
	return 0;
}


