/**************************************************************
 * Problem: 5066
 * Author: Vanilla_chan
 * Date: 20210329
 * E-Mail: Vanilla_chan@outlook.com
**************************************************************/
#include<iostream>
#define int unsigned
#define IL inline
#define re register
#define LL long long
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
using namespace oi;
namespace Random
{
	int s=0;
	IL void srand(int seed=0)
	{
		s=seed;
	}
	IL void rand(int &x)
	{
		x=s=s*13%19260817;
	}
};
#define N 3000010
int n,m;
bool a[N];
struct node{
	int l,r;
	bool v;
	int ll,rr,cnt[2],mn[2],lazy[2],sum;
	bool lv,rv;
	node *ls,*rs;
	int key;
	IL void upd()
	{
		ll=ls?ls->ll:l;
		rr=rs?rs->rr:r;
		cnt[v]=1;
		cnt[!v]=0;
		mn[v]=r-l+1;
		mn[!v]=n+1;
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
		Random::rand(key);
		ls=rs=0;
		lazy[0]=lazy[1]=0;
		upd();
	}
	IL void work(bool flag,int len)
	{
		lazy[flag]+=len;
		if(flag)
		{
			if(v) r+=len;
			else l+=len;
		}
		else
		{
			if(v) l-=len;
			else r-=len;
		}
		mn[0]-=len;
		mn[1]+=len;
		sum+=len*cnt[1];
	}
	IL void spread()
	{
		if(ls)
		{
			ls->work(0,lazy[0]);
			ls->work(1,lazy[1]);
		}
		if(rs)
		{
			rs->work(0,lazy[0]);
			rs->work(1,lazy[1]);
		}
		lazy[0]=lazy[1]=0;
	}
	int dfs()
	{
		spread();
		if(l==r+1) return l;
		else if(ls&&(!ls->mn[0]||!ls->mn[1])) return ls->dfs();
		else return rs->dfs();
	}
	~node()
	{
//		if(ls) delete ls;
//		if(rs) delete rs;
	}
}*root;
node* merge(node* x,node* y)
{
	if(!x) return y;
	if(!y) return x;
	if(x->key > y->key)
	{
		x->spread();
		x->rs=merge(x->rs,y);
		x->upd();
		return x;
	}
	else
	{
		y->spread();
		y->ls=merge(x,y->ls);
		y->upd();
		return y;
	}
}
void split1(node* i,int k,node *&x,node *&y)
{
	if(!i)
	{
		x=y=0;
		return;
	}
	i->spread();
	if(k>=i->l)
	{
		split1(i->rs,k,i->rs,y);
		x=i;
	}
	else
	{
		split1(i->ls,k,x,i->ls);
		y=i;
	}
	i->upd();
}
void split2(node* i,int k,node *&x,node *&y)
{
	if(!i)
	{
		x=y=0;
		return;
	}
	i->spread();
	if(k<=i->r)
	{
		split2(i->ls,k,x,i->ls);
		y=i;
	}
	else
	{
		split2(i->rs,k,i->rs,y);
		x=i;
	}
	i->upd();
}
IL int ask(int l,int r)
{
	node *x,*y,*z;
	split2(root,l,x,y);
	split1(y,r,y,z);
	int ans=y->sum;
	if(y->lv) ans-=l-y->ll;
	if(y->rv) ans-=y->rr-r;
	root=merge(x,merge(y,z));
	return ans;
}
IL void assign(int l,int r,bool v)
{
	node *x,*y,*z;
	if(l==1)
	{
		if(r^n)
		{
			split1(root,r+1,x,z);
			if(x->rv^v)
			{
				root=merge(merge(new node(1,r,v),new node(r+1,x->rr,!v)),z);
			}
			else
			{
				root=merge(new node(1,x->rr,v),z);
			}
//			delete x;
		}
		else
		{
//			delete root;
			root=new node(l,r,v);
		}
	}
	else{
		if(r^n)
		{
			split2(root,l-1,x,y);
			split1(y,r+1,y,z);
			if(y->lv^v){
				if(y->rv^v)
				{
					root=merge(merge(merge(merge(x,new node(y->ll,l-1,!v)),new node(l,r,v)),new node(r+1,y->rr,!v)),z);
				}
				else
				{
					root=merge(merge(merge(x,new node(y->ll,l-1,!v)),new node(l,y->rr,v)),z);
				}
			}
			else
			{
				if(y->rv^v)
				{
					root=merge(merge(merge(x,new node(y->ll,r,v)),new node(r+1,y->rr,!v)),z);
				}
				else
				{
					root=merge(merge(x,new node(y->ll,y->rr,v)),z);
				}
			}
//			delete y;
		}
		else
		{
			split2(root,l-1,x,z);
			if(z->lv^v)
			{
				root=merge(merge(x,new node(z->ll,l-1,!v)),new node(l,n,v));
			}
			else
			{
				root=merge(x,new node(z->ll,n,v));
			}
//			delete z;
		}
	}
}
IL void change1(int l,int r,bool flag)
{
	node *x,*y,*z,*t;
	split1(root,l-1,x,y);
	split1(y,r,y,z);
	if(y)
	{
		if(y->lv)
		{
			split2(x,y->ll-1,x,t);
			y=merge(t,y);
		}
		if(!y->rv)
		{
			split2(y,y->rr,y,t);
			z=merge(t,z);
		}
		if(y) y->work(0,flag?1:-1);//见下面 
	}
	root=merge(x,merge(y,z));
}
IL void change2(int l,int r,bool flag)
{
	node *x,*y,*z,*t;
	split2(root,r+1,y,z);
	split2(y,l,x,y);
	if(y)
	{
		if(y->rv)
		{
			split1(z,y->rr+1,t,z);
			y=merge(y,t);
		}
		if(!y->lv)
		{
			split1(y,y->ll,t,y);//注意这里有可能使得y=NULL!!! 
			x=merge(x,t); 
		}
		if(y) y->work(1,flag?1:-1);//所以这里还是要if(y)的 
	}
	root=merge(x,merge(y,z));
}
IL void update()
{
	int x=root->dfs();
	node *left,*mid,*right;
	split2(root,x-1,left,mid);
	split1(mid,x,mid,right);
	node *res=new node(mid->ll,mid->rr,((mid->r+1)^mid->l)?mid->v:!mid->v);
	root=merge(left,merge(res,right));
}
void out(node* x)
{
	x->spread();
	if(x->ls) out(x->ls);
	cout<<x->l<<" "<<x->r<<" "<<x->v<<endl;
	if(x->rs) out(x->rs);
}
int i,lst;
int op,l,r,lastans;
signed main()
{
//	freopen("5066.in","r",stdin);
//	freopen("5066.out","w",stdout);
	Random::srand(20050228);
	read(n);
	read(m);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=2;i<=n;i++)
	if(a[i]^a[i-1])
	{
		root=merge(root,new node(lst,i-1,*(a+i-1)));
		lst=i;
	}
	root=merge(root,new node(lst,n,*(a+n)));
	while(m--)
	{
		read(op);
		read(l);
		read(r);
		l^=lastans;
		r^=lastans;
		if(op==1)
		{
			assign(l,r,0);
		}
		else if(op==2)
		{
			assign(l,r,1);
		}
		else if(op==3)
		{
			change1(l+1,r,1);
		}
		else if(op==4)
		{
			change2(l,r-1,1);
		}
		else if(op==5)
		{
			change2(l,r-1,0);
		}
		else if(op==6)
		{
			change1(l+1,r,0);
		}
		else
		{
			write(lastans=ask(l,r));
		}
		if(op==3||op==4||op==5||op==6) while(!root->mn[0]||!root->mn[1]) update();
//		out(root);
	}
	return 0;
}

