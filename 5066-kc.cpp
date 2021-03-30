/**************************************************************
 * Problem: 5066
 * Author: Vanilla_chan
 * Date: 20210329
 * E-Mail: Vanilla_chan@outlook.com
**************************************************************/
#include<iostream>
#define IL inline
#define re register
#define LL long long
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;
namespace oi
{
	int x;
	char ch; 
	inline int read()
	{
		x=0;
		ch=getchar();
		while(!isdigit(ch)) ch=getchar();
		x=ch-'0';ch=getchar();
		while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
		return x;
	}
	template<class T>inline void read(T &xx)
	{
		xx=0;
		ch=getchar();
		while(!isdigit(ch)) ch=getchar();
		xx=ch-'0';ch=getchar();
		while(isdigit(ch)) { xx=xx*10+ch-'0';ch=getchar(); }
	}
	int G[55];
	int g;
	template<class T>inline void write(T x)
	{
		g=0;
		do { G[++g]=x%10;x/=10; } while(x);
		for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
	}
};
using oi::read;
using oi::write;
#define N 3000010
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
int n,m;
unsigned int s=1;
bool a[N];
struct node{
	int l,r,v,ll,rr,cnt[2],mn[2],lazy[2],sum,lv,rv,key;
	node *ls,*rs;
	IL void upd()
	{
		ll=ls?ls->ll:l;
		rr=rs?rs->rr:r;
		cnt[v]=1;
		cnt[!v]=0;
		mn[v]=r-l+1;
		mn[!v]=N;
		sum=v?r-l+1:0;
		lv=ls?ls->lv:v;
		rv=rs?rs->rv:v;
		if(ls)
		{
			cnt[0]+=ls->cnt[0];
			cnt[1]+=ls->cnt[1];
			mn[0]=min(mn[0],ls->mn[0]);
			mn[1]=min(mn[1],ls->mn[1]);
			sum+=ls->sum;
		}
		if(rs)
		{
			cnt[0]+=rs->cnt[0];
			cnt[1]+=rs->cnt[1];
			mn[0]=min(mn[0],rs->mn[0]);
			mn[1]=min(mn[1],rs->mn[1]);
			sum+=rs->sum;
		}
	}
	node(int L,int R,bool V)
	{
		l=L;
		r=R;
		v=V;
		key=(s*=19260817);
		ls=rs=0;
		lazy[0]=lazy[1]=0;
		upd();
	}
	IL void work0(int len)
	{
		lazy[0]+=len;
		if(v) l-=len;
		else r-=len;
		mn[0]-=len;
		mn[1]+=len;
		sum+=len*cnt[1];
	}
	IL void work1(int len)
	{
		lazy[1]+=len;
		if(v) r+=len;
		else l+=len;
		mn[0]-=len;
		mn[1]+=len;
		sum+=len*cnt[1];
	}
	IL void spread()
	{
		if(ls)
		{
			if(lazy[0]) ls->work0(lazy[0]);
			if(lazy[1]) ls->work1(lazy[1]);
		}
		if(rs)
		{
			if(lazy[0]) rs->work0(lazy[0]);
			if(lazy[1]) rs->work1(lazy[1]);
		}
		lazy[0]=lazy[1]=0;
	}
	int dfs()
	{
		if(lazy[0]||lazy[1]) spread();
		if(l==r+1) return l;
		else if(ls&&(!ls->mn[0]||!ls->mn[1])) return ls->dfs();
		else return rs->dfs();
	}
	/*
	~node()
	{
		if(ls) delete ls;
		if(rs) delete rs;
	}
	*/
}*root,*x,*y,*z,*t;
node* merge(node* x,node* y)
{
	if(!x) return y;
	if(!y) return x;
	if(x->key > y->key)
	{
		if(x->lazy[0]||x->lazy[1])  x->spread();
		x->rs=merge(x->rs,y);
		x->upd();
		return x;
	}
	else
	{
		if(y->lazy[0]||y->lazy[1]) y->spread();
		y->ls=merge(x,y->ls);
		y->upd();
		return y;
	}
}
int k;
void split1(node* i,node *&x,node *&y)
{
	if(!i)
	{
		x=y=0;
		return;
	}
	if(i->lazy[0]||i->lazy[1]) i->spread();
	if(k>=i->l)
	{
		split1(i->rs,i->rs,y);
		x=i;
	}
	else
	{
		split1(i->ls,x,i->ls);
		y=i;
	}
	i->upd();
}
void split2(node* i,node *&x,node *&y)
{
	if(!i)
	{
		x=y=0;
		return;
	}
	if(i->lazy[0]||i->lazy[1]) i->spread();
	if(k<=i->r)
	{
		split2(i->ls,x,i->ls);
		y=i;
	}
	else
	{
		split2(i->rs,i->rs,y);
		x=i;
	}
	i->upd();
}
int ans;
IL void ask(int l,int r)
{
	k=l;split2(root,x,y);
	k=r;split1(y,y,z);
	ans=y->sum;
	if(y->lv) ans-=l-y->ll;
	if(y->rv) ans-=y->rr-r;
	root=merge(x,merge(y,z));
}
IL void assign0(int l,int r)
{
	if(l^1)
	{
		if(r^n)
		{
			k=l-1;split2(root,x,y);
			k=r+1;split1(y,y,z);
			if(y->lv){
				if(y->rv)
				{
					root=merge(merge(merge(merge(x,new node(y->ll,l-1,1)),new node(l,r,0)),new node(r+1,y->rr,1)),z);
				}
				else
				{
					root=merge(merge(merge(x,new node(y->ll,l-1,1)),new node(l,y->rr,0)),z);
				}
			}
			else
			{
				if(y->rv)
				{
					root=merge(merge(merge(x,new node(y->ll,r,0)),new node(r+1,y->rr,1)),z);
				}
				else
				{
					root=merge(merge(x,new node(y->ll,y->rr,0)),z);
				}
			}
//			delete y;
		}
		else
		{
			k=l-1;split2(root,x,z);
			if(z->lv)
			{
				root=merge(merge(x,new node(z->ll,l-1,1)),new node(l,n,0));
			}
			else
			{
				root=merge(x,new node(z->ll,n,0));
			}
//			delete z;
		}
	}
	else
	{
		if(r^n)
		{
			k=r+1;split1(root,x,z);
			if(x->rv)
			{
				root=merge(merge(new node(1,r,0),new node(r+1,x->rr,1)),z);
			}
			else
			{
				root=merge(new node(1,x->rr,0),z);
			}
//			delete x;
		}
		else
		{
//			delete root;
			root=new node(l,r,0);
		}
	}
}
IL void assign1(int l,int r)
{
	if(l^1)
	{
		if(r^n)
		{
			k=l-1;split2(root,x,y);
			k=r+1;split1(y,y,z);
			if(y->lv){
				if(y->rv)
				{
					root=merge(merge(x,new node(y->ll,y->rr,1)),z);
				}
				else
				{
					root=merge(merge(merge(x,new node(y->ll,r,1)),new node(r+1,y->rr,0)),z);
				}
			}
			else
			{
				
				if(y->rv)
				{
					root=merge(merge(merge(x,new node(y->ll,l-1,0)),new node(l,y->rr,1)),z);
				}
				else
				{
					root=merge(merge(merge(merge(x,new node(y->ll,l-1,0)),new node(l,r,1)),new node(r+1,y->rr,0)),z);
				}
			}
//			delete y;
		}
		else
		{
			k=l-1;split2(root,x,z);
			if(z->lv)
			{
				root=merge(x,new node(z->ll,n,1));
			}
			else
			{
				root=merge(merge(x,new node(z->ll,l-1,0)),new node(l,n,1));
			}
//			delete z;
		}
	}
	else
	{
		if(r^n)
		{
			k=r+1;split1(root,x,z);
			if(x->rv)
			{
				root=merge(new node(1,x->rr,1),z);
			}
			else
			{
				root=merge(merge(new node(1,r,1),new node(r+1,x->rr,0)),z);
			}
//			delete x;
		}
		else
		{
//			delete root;
			root=new node(l,r,1);
		}
	}
}
IL void change10(int l,int r)
{
	k=l-1;split1(root,x,y);
	k=r;split1(y,y,z);
	if(y)
	{
		if(y->lv)
		{
			k=y->ll-1;split2(x,x,t);
			y=merge(t,y);
		}
		if(!y->rv)
		{
			k=y->rr;split2(y,y,t);
			z=merge(t,z);
		}
		if(y) y->work0(-1);
	}
	root=merge(x,merge(y,z));
}
IL void change11(int l,int r)
{
	k=l-1;split1(root,x,y);
	k=r;split1(y,y,z);
	if(y)
	{
		if(y->lv)
		{
			k=y->ll-1;split2(x,x,t);
			y=merge(t,y);
		}
		if(!y->rv)
		{
			k=y->rr;split2(y,y,t);
			z=merge(t,z);
		}
		if(y) y->work0(1);//¼ûÏÂÃæ 
	}
	root=merge(x,merge(y,z));
}
IL void change20(int l,int r)
{
	k=r+1;split2(root,y,z);
	k=l;split2(y,x,y);
	if(y)
	{
		if(y->rv)
		{
			k=y->rr+1;split1(z,t,z);
			y=merge(y,t);
		}
		if(!y->lv)
		{
			k=y->ll;split1(y,t,y);
			x=merge(x,t); 
		}
		if(y) y->work1(-1);
	}
	root=merge(x,merge(y,z));
}
IL void change21(int l,int r)
{
	k=r+1;split2(root,y,z);
	k=l;split2(y,x,y);
	if(y)
	{
		if(y->rv)
		{
			k=y->rr+1;split1(z,t,z);
			y=merge(y,t);
		}
		if(!y->lv)
		{
			k=y->ll;split1(y,t,y);
			x=merge(x,t); 
		}
		if(y) y->work1(1);
	}
	root=merge(x,merge(y,z));
}
int num;
IL void update()
{
	num=root->dfs();
	k=num-1;split2(root,x,y);
	k=num;split1(y,y,z);
	t=new node(y->ll,y->rr,((y->r+1)^y->l)?y->v:!y->v);
	root=merge(x,merge(t,z));
}
int i;
int op,l,r;
signed main()
{
//	freopen("5066.in","r",stdin);
//	freopen("5066.out","w",stdout);
	read(n);
	read(m);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=2;i<=n;i++)
	if(a[i]^a[i-1])
	{
		root=merge(root,new node(num,i-1,*(a+i-1)));
		num=i;
	}
	root=merge(root,new node(num,n,*(a+n)));
	while(m--)
	{
		read(op);
		read(l);
		read(r);
		l^=ans;
		r^=ans;
		if(op==1)
		{
			assign0(l,r);
		}
		else if(op==2)
		{
			assign1(l,r);
		}
		else if(op==3)
		{
			change11(l+1,r);
			while(!(root->mn[0]&&root->mn[1])) update();
		}
		else if(op==4)
		{
			change21(l,r-1);
			while(!(root->mn[0]&&root->mn[1])) update();
		}
		else if(op==5)
		{
			change20(l,r-1);
			while(!(root->mn[0]&&root->mn[1])) update();
		}
		else if(op==6)
		{
			change10(l+1,r);
			while(!(root->mn[0]&&root->mn[1])) update();
		}
		else
		{
			ask(l,r);
			write(ans);
		}
//		if(op==3||op==4||op==5||op==6) while(!root->mn[0]||!root->mn[1]) update();
	}
	return 0;
}

