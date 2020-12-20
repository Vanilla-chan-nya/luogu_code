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
struct Zt
{
	vector<int>a;
	Zt()
	{
		a.resize(10);
//		cout<<a.size();
	}
	Zt(vector<int>b)
	{
		a=b;
	}
	bool operator==(const Zt & z)const
	{
		return z.a==a;
	}
	bool operator<(const Zt & z)const
	{
		return a<z.a;
	}
}goal,now;
int s[10];
vector<int>a,temp;
void init()
{
	int b[10]={1,2,3,8,0,4,7,6,5};
	for(int i=0;i<9;i++) a.push_back(b[i]);
	goal=Zt(a);
}
set<Zt>online;
map<Zt,LL>dis;
void bfs()
{
	queue<Zt>q;
	a.clear();
	for(int i=0;i<9;i++) a.push_back(s[i]);
	q.push({a});
	online.insert({a});
	dis[{a}]=0;
	int zero;
	while(!q.empty())
	{
//		debug
		now=q.front();
		a=now.a;
		q.pop();
		online.erase(now);
		//
		
//		for(int i=0;i<9;i++)
//		{
//			cout<<a[i]<<" ";
//			if(i%3==2) cout<<endl;
//		}
//		cout<<endl<<endl;
		
		//
		if(now==goal)
		{
			write(dis[now]);
			return;
		}
		for(int i=0;i<9;i++) if(a[i]==0) zero=i;
//		cout<<"zero="<<zero<<endl;
		if(zero<6)//in line 1
		{
			temp=a;
			swap(temp[zero],temp[zero+3]);
			if(dis.find({temp})==dis.end())
			{
				dis[{temp}]=dis[now]+1;
				q.push({temp}),online.insert({temp});
			}
			else
			if(dis[{temp}]>dis[now]+1)
			{
				dis[{temp}]=dis[now]+1;
				if(online.find({temp})==online.end()) q.push({temp}),online.insert({temp});
			}
		}
		if(zero>2)
		{
			temp=a;
			swap(temp[zero],temp[zero-3]);
			if(dis.find({temp})==dis.end())
			{
				dis[{temp}]=dis[now]+1;
				q.push({temp}),online.insert({temp});
			}
			else
			if(dis[{temp}]>dis[now]+1)
			{
				dis[{temp}]=dis[now]+1;
				if(online.find({temp})==online.end()) q.push({temp}),online.insert({temp});
			}
		}
		if(zero%3!=0)
		{
			temp=a;
			swap(temp[zero],temp[zero-1]);
			if(dis.find({temp})==dis.end())
			{
				dis[{temp}]=dis[now]+1;
				q.push({temp}),online.insert({temp});
			}
			else
			if(dis[{temp}]>dis[now]+1)
			{
				dis[{temp}]=dis[now]+1;
				if(online.find({temp})==online.end()) q.push({temp}),online.insert({temp});
			}
		}
		if(zero%3!=2)
		{
			temp=a;
			swap(temp[zero],temp[zero+1]);
			if(dis.find({temp})==dis.end())
			{
				dis[{temp}]=dis[now]+1;
				q.push({temp}),online.insert({temp});
			}
			else
			if(dis[{temp}]>dis[now]+1)
			{
				dis[{temp}]=dis[now]+1;
				if(online.find({temp})==online.end()) q.push({temp}),online.insert({temp});
			}
		}
//		debug
	}
//	debug
}
int main()
{
	init();
	
	for(int i=0;i<9;i++) s[i]=getchar()-'0';
	bfs();
	return 0;
}


