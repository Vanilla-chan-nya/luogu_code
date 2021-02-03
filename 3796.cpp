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
	int trie[120000][30];
	int fail[120000];
	int v[120000];
	string a[200];
	int ys[200];//string node->pos
	int n;
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
	void insert(string str)
	{
		int pos=0;
		for(int i=0;i<str.size();i++)
		{
			if(!trie[pos][str[i]-'a']) trie[pos][str[i]-'a']=++cnt;
			pos=trie[pos][str[i]-'a'];
		}
		
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
				if(trie[x][i]) fail[trie[x][i]]=trie[fail[x]][i],q.push(trie[x][i]);//�������ڵ���i���ӣ���ô������ӵ�fail=���׵�fail��i���� 
				else trie[x][i]=trie[fail[x]][i];//���û�����i���ӣ���ô������������Ǹ��׵�fail��i���ӡ� 
			}
		}
	}
	void calc(string str)
	{
		int pos=0;
		for(int i=0,j;i<str.size();i++)
		{
			j=pos=trie[pos][str[i]-'a'];
			while(j)
			{
				v[j]++;
				j=fail[j];
			}
		}
	}
	void output()
	{
		vector<int>ans;
		int maxans=0;
		for(int i=0;i<n;i++)
		{
			if(maxans<v[ys[i]]) maxans=v[ys[i]],ans.clear();
			if(maxans==v[ys[i]]) ans.push_back(i);
		}
		write(maxans);
		for(int i=0;i<ans.size();i++) cout<<a[ans[i]]<<endl;
	}
}ac;
int n;
string t;
int main()
{
	n=read();
	if(n==0) return 0;
	ac.input(n);
	ac.init();
	cin>>t;
	ac.calc(t);
	ac.output();
	main();
	return 0;
}


