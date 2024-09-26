/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 500010
map<int,int>lsh;
int cnt;


int n,m;
int a[N];


struct Node
{
	int l,r,mx,mn,nxt;
	Node(int ll=0,int rr=0,int nn=0,int Max=0,int Min=0)
	{
		l=ll;
		r=rr;
		nxt=nn;
		mx=Max;
		mn=Min;
	}
#define l(x) tree[x].l
#define r(x) tree[x].r
#define nxt(x) tree[x].nxt
#define mx(x) tree[x].mx
#define mn(x) tree[x].mn
}tree[N<<3];

set<int>pos[N<<3];

Node merge(Node x,Node y)
{
	return Node(x.l,y.r,min(x.nxt,y.nxt),min(x.mn,y.mn),max(x.mx,y.mx));
}

void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		nxt(p)=*pos[lsh[a[l]]].upper_bound(l);
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}

void change(int p,int x,int k)
{
	if(l(p)==r(p))
	{
		a[x]=k;
		nxt(p)=*pos[lsh[k]].upper_bound(x);
		mn(p)=k;
		mx(p)=k;
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) change(p<<1,x,k);
	else change(p<<1|1,x,k);
	tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}

void refresh(int p,int x)
{
	if(l(p)==r(p))
	{
		nxt(p)=*pos[lsh[a[x]]].upper_bound(x);
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) refresh(p<<1,x);
	else refresh(p<<1|1,x);
	tree[p]=merge(tree[p<<1],tree[p<<1|1]);
}

Node ask(int p,int l,int r)
{
//	debug
	if(l<=l(p)&&r(p)<=r)
	{
		return tree[p];
	}
	int mid=(l(p)+r(p))>>1;
	if(r<=mid) return ask(p<<1,l,r);
	if(l>mid) return ask(p<<1|1,l,r);
	return merge(ask(p<<1,l,r),ask(p<<1|1,l,r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(lsh.find(a[i])==lsh.end())
			{
				lsh[a[i]]=++cnt;
				pos[lsh[a[i]]].insert(0);
				pos[lsh[a[i]]].insert(n+1);
			}
			pos[lsh[a[i]]].insert(i);
		}
		build(1,1,n);
		while(m--)
		{
			int op;
			cin>>op;
			if(op==1)
			{
				int p,k2;
				cin>>p>>k2;
				int k1=a[p];
				if(lsh.find(k2)==lsh.end())
				{
					lsh[k2]=++cnt;
					pos[lsh[k2]].insert(0);
					pos[lsh[k2]].insert(n+1);
				}
				pos[lsh[k2]].insert(p);
				pos[lsh[k1]].erase(p);
				change(1,p,k2);
				auto pre=pos[k1].lower_bound(p);
				pre--;
				if(*pre)
				{
					refresh(1,*pre);
				}
				pre=pos[k2].lower_bound(p);
				pre--;
				if(*pre)
				{
					refresh(1,*pre);
				}
			}
			if(op==2)
			{
				int l,r;
				cin>>l>>r;
				Node ans=ask(1,l,r);
				if(ans.nxt>r&&ans.mx-ans.mn==ans.r-ans.l) cout<<"damushen"<<endl;
				else cout<<"yuanxing"<<endl;
			}
		}
	}
	return 0;
}
