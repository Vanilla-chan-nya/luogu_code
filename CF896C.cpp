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
#define int long long
#define ULL unsigned long long
#define re register
#define debug printf("Now is %d\n",__LINE__);
#define IT set<node>::iterator
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
LL n,m,seed,vmax,ret;
struct node
{
	int l,r;
	mutable LL v;
	node(int L,int R=-1,LL V=0):l(L),r(R),v(V){}
	IL bool operator<(const node & x) const
	{
		return l<x.l;
	}
};
set<node>s;
LL a[100010];
LL rnd()
{
//	cout<<"seed="<<seed<<endl; 
	ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
IT split(int pos)
{
	IT it=s.lower_bound((node(pos)));
	if(it!=s.end()&&it->l==pos) return it;
	it--;
	LL L=it->l,R=it->r,V=it->v;
	s.erase(it);
	s.insert(node(L,pos-1,V));
	debug
	return s.insert(node(pos,R,V)).first;
}
void assign(int l,int r,LL val)
{
	debug
	IT itr=split(r+1);
	debug 
	IT itl=split(l);
	debug
	s.erase(itl,itr);
	debug
	s.insert(node(l,r,val));
	debug;
}
void add(int l,int r,LL val=1)
{
	IT itl=split(l),itr=split(r+1);
	for(;itl!=itr;++itl) itl->v+=val;
	debug;
}
LL rnk(int l,int r,int k)
{
	vector< pair<LL,int> >vp;
	IT itl=split(l),itr=split(r+1);
	for(;itl!=itr;++itl)
		vp.push_back(pair<LL,int>(itl->v,itl->r-itl->l+1));
	sort(vp.begin(),vp.end());
	debug;
	for(LL i=0;i<vp.size();i++)
	{
		k-=vp[i].second;
		if(k<=0) return vp[i].first;
	}
	return -1LL;
}
inline long long qpow(long long a,long long b,long long p){
    long long ans=1;
    a%=p;
    while(b){
        if(b&1){
        	ans=ans*a%p;
		}
        a=a*a%p;
    	b>>=1;
    }
    return ans;
}
LL sum(int l,int r,int ex,int mod)
{
	IT itl=split(l),itr=split(r+1);
	LL res=0;
	for(;itl!=itr;++itl)
	{
		res=(res+(itl->r-itl->l+1)*qpow(itl->v,ex,mod))%mod;
	}
	return res;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m>>seed>>vmax;
	for(int i=1;i<=n;i++)
	{
		a[i]=(rnd()%vmax)+1;
		s.insert(node(i,i,a[i]));
//		debug;
	}
	int op,l,r;
	while(m--)
	{
		op=(rnd()%4)+1;
		l=(rnd()%n)+1;
		r=(rnd()%n)+1;
		if(l>r) swap(l,r);
		cout<<"op="<<op<<" l="<<l<<" r="<<r<<endl;
		debug;
		int x,y;
//		debug;
		if(op==1)
		{
			x=rnd()%vmax+1;
			add(l,r,x);
		}
//		debug;
		if(op==2)
		{
//			debug;
			x=rnd()%vmax+1;
			assign(l,r,x);
		}
		if(op==3)
		{
//			debug;
		x=rnd()%(r-l+1)+1;
			cout<<rnk(l,r,x)<<endl;
		}
		if(op==4)
		{
//			debug;
			x=rnd()%(r-l+1)+1;
			y=rnd()%vmax+1;
			cout<<sum(l,r,x,y)<<endl;
		}
	}
	return 0;
}

