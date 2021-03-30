#include<algorithm>
#include<ctime>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n,m;
bool a[maxn];
int tot;
struct node{
	int l,r;
	bool v;
	int ll,rr,cnt[2],mn[2],tag[2],sum;
	bool lv,rv;
	node* ch[2];
	int rk;
	int id;
	void upd(){
		if(ch[0]) ll=ch[0]->ll;
		else ll=l;
		if(ch[1]) rr=ch[1]->rr;
		else rr=r;
		cnt[v]=1;
		cnt[!v]=0;
		mn[v]=r-l+1;
		mn[!v]=n+1;
		sum=v?r-l+1:0;
		lv=ch[0]?ch[0]->lv:v;
		rv=ch[1]?ch[1]->rv:v;
		if(ch[0]){
			cnt[0]+=ch[0]->cnt[0];
			cnt[1]+=ch[0]->cnt[1];
			mn[0]=min(mn[0],ch[0]->mn[0]);
			mn[1]=min(mn[1],ch[0]->mn[1]);
			sum+=ch[0]->sum;
		}
		if(ch[1]){
			cnt[0]+=ch[1]->cnt[0];
			cnt[1]+=ch[1]->cnt[1];
			mn[0]=min(mn[0],ch[1]->mn[0]);
			mn[1]=min(mn[1],ch[1]->mn[1]);
			sum+=ch[1]->sum;
		}
	}
	node(int l,int r,bool v):l(l),r(r),v(v),rk(rand()){
		ch[0]=ch[1]=0;
		tag[0]=tag[1]=0;
		id=++tot;
		upd();
	}
	void pushtag(bool flag,int k){
		tag[flag]+=k;
		if(flag){
			if(v) r+=k;
			else l+=k;
		}
		else{
			if(v) l-=k;
			else r-=k;
		}
		mn[0]-=k;
		mn[1]+=k;
		sum+=k*cnt[1];
	}
	void spread(){
		if(ch[0]){
			ch[0]->pushtag(0,tag[0]);
			ch[0]->pushtag(1,tag[1]);
		}
		if(ch[1]){
			ch[1]->pushtag(0,tag[0]);
			ch[1]->pushtag(1,tag[1]);
		}
		tag[0]=tag[1]=0;
	}
	int find(){
		spread();
		if(l==r+1) return l;
		else if(ch[0]&&(!ch[0]->mn[0]||!ch[0]->mn[1]))
			return ch[0]->find();
		else return ch[1]->find();
	}
	~node(){
		if(ch[0]) delete ch[0];
		if(ch[1]) delete ch[1];
	}
};
node* merge(node* l,node* r){
	if(!l) return r;
	if(!r) return l;
	
	if(l->rk>r->rk){
		l->spread();
		l->ch[1]=merge(l->ch[1],r);
		l->upd();
		return l;
	}
	else{
		r->spread();
		r->ch[0]=merge(l,r->ch[0]);
		r->upd();
		return r;
	}
}
void split1(node* i,int k,node*& x,node*& y){
	if(!i){
		x=y=0;
		return;
	}
	i->spread();
	if(k>=i->l){
		split1(i->ch[1],k,i->ch[1],y);
		x=i;
	}
	else{
		split1(i->ch[0],k,x,i->ch[0]);
		y=i;
	}
	i->upd();
}
void split2(node* i,int k,node*& x,node*& y){
	if(!i){
		x=y=0;
		return;
	}
	i->spread();
	if(k<=i->r){
		split2(i->ch[0],k,x,i->ch[0]);
		y=i;
	}
	else{
		split2(i->ch[1],k,i->ch[1],y);
		x=i;
	}
	i->upd();
}
node* rt=0;
int query(int l,int r){
	node *left,*mid,*right;
	split2(rt,l,left,mid);
	split1(mid,r,mid,right);
	int ans=mid->sum;
	if(mid->lv) ans-=l-mid->ll;
	if(mid->rv) ans-=mid->rr-r;
	rt=merge(left,merge(mid,right));
	return ans;
}
void assign(int l,int r,bool v){
	if(l==1){
		if(r==n){
			delete rt;
			rt=new node(1,n,v);
		}
		else{
			node *left,*right;
			split1(rt,r+1,left,right);
			if(left->rv^v){
				rt=new node(1,r,v);
				rt=merge(rt,new node(r+1,left->rr,!v));
			}
			else rt=new node(1,left->rr,v);
			rt=merge(rt,right);
			delete left;
		}
	}
	else{
		if(r==n){
			node *left,*right;
			split2(rt,l-1,left,right);
			rt=left;
			if(right->lv^v){
				rt=merge(rt,new node(right->ll,l-1,!v));
				rt=merge(rt,new node(l,n,v));
			}
			else rt=merge(rt,new node(right->ll,n,v));
			delete right;
		}
		else{
			node *left,*mid,*right;
			split2(rt,l-1,left,mid);
			split1(mid,r+1,mid,right);
			rt=left;
			if(mid->lv^v){
				rt=merge(rt,new node(mid->ll,l-1,!v));
				if(mid->rv^v){
					rt=merge(rt,new node(l,r,v));
					rt=merge(rt,new node(r+1,mid->rr,!v));
				}
				else rt=merge(rt,new node(l,mid->rr,v));
			}
			else{
				if(mid->rv^v){
					rt=merge(rt,new node(mid->ll,r,v));
					rt=merge(rt,new node(r+1,mid->rr,!v));
				}
				else rt=merge(rt,new node(mid->ll,mid->rr,v));
			}
			rt=merge(rt,right);
			delete mid;
		}
	}
}
void modify1(int l,int r,bool flag){
	node *left,*mid,*right;
	split1(rt,l-1,left,mid);
	split1(mid,r,mid,right);
	if(mid&&mid->lv){
		node* res;
		split2(left,mid->ll-1,left,res);
		mid=merge(res,mid);
	}
	if(mid&&!mid->rv){
		node* res;
		split2(mid,mid->rr,mid,res);
		right=merge(res,right);
	}
	if(mid) mid->pushtag(0,flag?1:-1);
	rt=merge(left,merge(mid,right));
}
void modify2(int l,int r,bool flag){
	node *left,*mid,*right;
	split2(rt,r+1,mid,right);
	split2(mid,l,left,mid);
	if(mid&&mid->rv){
		node* res;
		split1(right,mid->rr+1,res,right);
		mid=merge(mid,res);
	}
	if(mid&&!mid->lv){
		node* res;
		split1(mid,mid->ll,res,mid);
		left=merge(left,res);
	}
	if(mid) mid->pushtag(1,flag?1:-1);
	rt=merge(left,merge(mid,right));
}
void update(){
	int x=rt->find();
	node *left,*mid,*right;
	split2(rt,x-1,left,mid);
	split1(mid,x,mid,right);
	node *res=new node(mid->ll,mid->rr,mid->r+1==mid->l?!mid->v:mid->v);
	rt=merge(left,merge(res,right));
}
#include<iostream>
void out(node* x)
{
	x->spread();
	if(x->ch[0]) out(x->ch[0]);
	cout<<"id="<<x->id<<" "<<x->l<<" "<<x->r<<" "<<x->v<<endl;
	if(x->ch[1]) out(x->ch[1]);
}
int lastans;
int main(){
//	freopen("5066.in","r",stdin);
//	freopen("5066.ans","w",stdout);
	srand(20050228);
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int lst=1;
	for(int i=2;i<=n;i++) if(a[i]^a[i-1]){
		rt=merge(rt,new node(lst,i-1,a[i-1]));
		lst=i;
	}
	rt=merge(rt,new node(lst,n,a[n]));
	while(m--){
		int opt=readint();
		if(opt==1){
			int l,r;
			l=readint()^lastans;
			r=readint()^lastans;
			assign(l,r,0);
		}
		else if(opt==2){
			int l,r;
			l=readint()^lastans;
			r=readint()^lastans;
			assign(l,r,1);
		}
		else if(opt==3){
			int l,r;
			l=readint()^lastans;
			r=readint()^lastans;
			modify1(l+1,r,1);
			while(!rt->mn[0]||!rt->mn[1]) update();
		}
		else if(opt==4){
			int l,r;
			l=readint()^lastans;
			r=readint()^lastans;
			modify2(l,r-1,1);
			while(!rt->mn[0]||!rt->mn[1]) update();
		}
		else if(opt==5){
			int l,r;
			l=readint()^lastans;
			r=readint()^lastans;
			modify2(l,r-1,0);
			while(!rt->mn[0]||!rt->mn[1]) update();
		}
		else if(opt==6){
			int l,r;
			l=readint()^lastans;
			r=readint()^lastans;
			modify1(l+1,r,0);
			while(!rt->mn[0]||!rt->mn[1]) update();
		}
		else{
			int l,r;
			l=readint()^lastans;
			r=readint()^lastans;
			printf("%d\n",lastans=query(l,r));
		}
//		out(rt);
	}
	return 0;
}
