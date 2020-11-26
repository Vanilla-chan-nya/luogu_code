//°¢¹ÅÂ·ÓÐ£¬´øÞú£¡ 
#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
struct Edge{
	LL l,r,sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
}tree[400010];
LL n,m; 
LL ans[100010];
void build(LL l,LL r,LL p)
{
	l(p)=l,r(p)=r;
	if(l==r){sum(p)=ans[l];return;}
	LL mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
void spread(LL p)
{
	if(add(p))
	{
		sum(p<<1)+=add(p)*(r(p<<1)-l(p<<1)+1);
		sum(p<<1|1)+=add(p)*(r(p<<1|1)-l(p<<1|1)+1);
		add(p<<1)+=add(p);
		add(p<<1|1)+=add(p);
		add(p)=0;
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
LL ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	LL mid=l(p)+r(p)>>1,val=0;
	if(l<=mid) val+=ask(l,r,p<<1);
	if(r>mid) val+=ask(l,r,p<<1|1);
	return val;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",ans+i); 
	build(1,n,1);
	LL t,a,b,c;
	while(m--)
	{
		cin>>t;
		if(t==1){
			scanf("%lld%lld%lld",&a,&b,&c);
			change(a,b,1,c);
		}
		if(t==2){
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",ask(a,b,1));
		}
	}
}
