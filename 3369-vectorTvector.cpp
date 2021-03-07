#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0'; ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0'; ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10; x/=10; } while(x);
	for(int i=g; i>=1; --i)putchar('0'+G[i]); putchar('\n');
}
#define S 450
int n,m;
vector<vector<int> >a;
vector<int>b;
void init()
{
	a.clear();
	b.clear();
	vector<int>c;
	int x=0;
	while(n--) cin>>x,c.push_back(x);
	sort(c.begin(),c.end());
	for(int i=0;i<c.size();i++)
	{
		b.push_back(c[i]);
		if(b.size()==S) a.push_back(b),b.clear();
	}
	if(b.size()) a.push_back(b),b.clear();
	if(a.size()==0) a.push_back(b);
}
void split(int p)
{
	b.insert(b.begin(),a[p].end()-S,a[p].end());
	a[p].erase(a[p].end()-S,a[p].end());
	a.insert(a.begin()+p+1,b);
	b.clear();
}
void merge(int p)
{
	a[p].insert(a[p].end(),a[p+1].begin(),a[p+1].end());
	a.erase(a.begin()+p+1);
}
int find(int v)
{
	if(a.size()==1&&a[0].size()==0) return 0;
	int l=0,r=a.size()-1,mid,pos=a.size()-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid][a[mid].size()-1]>=v)
		{
			r=mid-1;
			pos=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return pos;
}
void insert(int v)
{
	if(a.size()==0)
	{
		b.push_back(v);
		a.push_back(b);
		b.clear();
		return;
	}
	int p=find(v);
	a[p].insert(lower_bound(a[p].begin(),a[p].end(),v),v);
	if(a[p].size()>=(S<<2)) split(p);
}
void erase(int v)
{
	int p=find(v);
	a[p].erase(lower_bound(a[p].begin(),a[p].end(),v));
	if(a[p].size()<=(S>>2))
	{
		if(a.size()==1) return;
		if(p==0) merge(p);
		else if(p==a.size()-1) merge(p-1);
		else
		{
			if(a[p+1].size()<a[p-1].size()) merge(p);
			else merge(p-1);
		}
	}
}
int rnk(int x)
{
	int p=find(x),ans=1;
	for(int i=0;i<p;i++)
	{
		ans+=a[i].size();
	}
	ans+=lower_bound(a[p].begin(),a[p].end(),x)-a[p].begin();
	return ans;
}
int kth(int x)
{
	x--;
	int p=0;
	while(x>=a[p].size()) x-=a[p++].size();
	return a[p][x];
}
int pre(int x)
{
	int p=find(x);
	vector<int>::iterator it=lower_bound(a[p].begin(),a[p].end(),x);
	if(it==a[p].begin()) return a[p-1][a[p-1].size()-1];
	return (*(--it));
}
int nxt(int x)
{
	int p=find(x+1);
	vector<int>::iterator it=upper_bound(a[p].begin(),a[p].end(),x);
	if(it==a[p].end()) return a[p+1][0];
	return (*it);
}
int op,x;
int main()
{
	n=read();
	while(n--)
	{
		op=read();
		x=read();
		if(op==1)
		{
			insert(x);
		}
		else if(op==2)
		{
			erase(x);
		}
		else if(op==3)
		{
			write(rnk(x));
		}
		else if(op==4)
		{
			write(kth(x));
		}
		else if(op==5)
		{
			write(pre(x));
		}
		else
		{
			write(nxt(x));
		}
	}
	return 0;
}
