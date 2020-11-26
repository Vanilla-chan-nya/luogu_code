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
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);
}
int n,now,ans;
int a[100010];
vector< pair<int,int> >s[4],tot;
int book[100010];
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	now=n;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0)
		{
			continue;
		}
		if(a[i]==1)
		{
			s[1].push_back(make_pair(now,i));
			tot.push_back(s[1].back());
			now--; 
			ans++;
		}
		if(a[i]==2)
		{
			if(s[1].empty()) {
				cout<<"-1"<<endl;
				return 0;
			}
			pair<int,int> x=s[1].back();s[1].pop_back();
			s[2].push_back(make_pair(x.first,i));
			tot.push_back(s[2].back());
			now--;
		}
		if(a[i]==3)
		{
			if(s[1].empty()&&s[2].empty()&&s[3].empty())
			{
				cout<<"-1"<<endl;
				return 0;
			}
			if(!s[3].empty())
			{
				pair<int,int> x=s[3].back();
				s[3].pop_back();
				ans+=2;
				s[3].push_back(make_pair(now,i));
				tot.push_back(s[3].back());
				tot.push_back(make_pair(now,x.second));
				now--;
				continue;
			}
			if(!s[2].empty())
			{
				pair<int,int> x=s[2].back();
				s[2].pop_back();
				ans+=2;
				s[3].push_back(make_pair(now,i));
				tot.push_back(s[3].back());
				tot.push_back(make_pair(now,x.second));
				now--;
				continue;
			}
			pair<int,int> x=s[1].back();
			s[1].pop_back();
			ans+=2;
			s[3].push_back(make_pair(now,i));
			tot.push_back(s[3].back());
			tot.push_back(make_pair(now,x.second));
			now--;
		}
	}
	cout<<tot.size()<<endl;
	while(!tot.empty()) cout<<tot.back().first<<" "<<tot.back().second<<endl,tot.pop_back();
	return 0;
}

