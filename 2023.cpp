#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define int long long
using namespace std;
struct Edge{
	LL l,r,sum,add,mul;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
	#define mul(x) tree[x].mul
}tree[400010];
LL n,m,P; 
LL ans[100010];
void build(LL l,LL r,LL p)
{
	l(p)=l,r(p)=r;
	if(l==r){sum(p)=ans[l]%P;return;}
	LL mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
	sum(p)%=P;
	mul(p)=1;
}
void spread(LL p)
{
	if(add(p)||mul(p)!=1)
	{
		sum(p<<1)%=P;
		sum(p<<1|1)%=P;
		mul(p<<1)%=P;
		mul(p<<1|1)%=P;
		add(p<<1)%=P;
		add(p<<1|1)%=P;
		
		sum(p<<1)*=mul(p);
		sum(p<<1)%=P;
		sum(p<<1)+=add(p)*(r(p<<1)-l(p<<1)+1);
		sum(p<<1)%=P;
		sum(p<<1|1)*=mul(p);
		sum(p<<1|1)%=P;
		sum(p<<1|1)+=add(p)*(r(p<<1|1)-l(p<<1|1)+1);
		sum(p<<1|1)%=P;
		
		mul(p<<1)*=mul(p);
		mul(p<<1|1)*=mul(p);
		mul(p<<1)%=P;
		mul(p<<1|1)%=P;
		
		add(p<<1)*=mul(p);
		add(p<<1)%=P;
		add(p<<1|1)*=mul(p);
		add(p<<1|1)%=P;
		
		add(p<<1)+=add(p);
		add(p<<1|1)+=add(p);
		add(p<<1)%=P;
		add(p<<1|1)%=P;
		
		add(p)=0;
		mul(p)=1;
	}
}
void change(LL l,LL r,LL p,LL k)
{
	if(l<=l(p)&&r>=r(p)){add(p)+=k;sum(p)+=k*(r(p)-l(p)+1);return;}
	LL mid=l(p)+r(p)>>1;
	spread(p);
	if(l<=mid) change(l,r,p<<1,k);
	if(r>mid) change(l,r,p<<1|1,k);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
void change_mul(LL l,LL r,LL p,LL k)
{
	if(l<=l(p)&&r>=r(p)){
		add(p)*=k;
		add(p)%=P;
		mul(p)*=k;
		mul(p)%=P;
		sum(p)*=k;
		sum(p)%=P;
		return;
	}
	spread(p);
	sum(p)=sum(p<<1)+sum(p<<1|1);
	LL mid=l(p)+r(p)>>1;
	if(l<=mid) change_mul(l,r,p<<1,k);
	if(r>mid) change_mul(l,r,p<<1|1,k);
	sum(p)=sum(p<<1)+sum(p<<1|1);
	sum(p)%=P;
}
LL ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	LL mid=l(p)+r(p)>>1,val=0;
	if(l<=mid) val+=ask(l,r,p<<1);
	val%=P;
	if(r>mid) val+=ask(l,r,p<<1|1);
	val%=P;
	return val;
}
signed main()
{
	cin>>n>>P;
	for(int i=1;i<=n;i++) cin>>ans[i];
	cin>>m;
	build(1,n,1);
	LL t,a,b,c;
	while(m--)
	{
		cin>>t;
		if(t==1){
			cin>>a>>b>>c;
			change_mul(a,b,1,c);
		}
		if(t==2){
			cin>>a>>b>>c;
			change(a,b,1,c);
		}
		if(t==3){
			cin>>a>>b;
			cout<<ask(a,b,1)%P<<endl;
		}
	}
}
