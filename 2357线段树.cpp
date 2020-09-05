#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
struct Edge{
	LL l,r,sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
}tree[800010];
LL n,m; 
LL ans[200010];
void build(int l,int r,int p)
{
	l(p)=l,r(p)=r;
	if(l==r){sum(p)=ans[l];return;}
	LL mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	sum(p)=sum(p*2)+sum(p*2+1);
}
void spread(LL p)
{
	if(add(p))
	{
		sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
		add(p*2)+=add(p);
		add(p*2+1)+=add(p);
		add(p)=0;
	}
}
void change(LL l,LL r,LL p,LL k)
{
	if(l<=l(p)&&r>=r(p)){add(p)+=k;sum(p)+=k*(r(p)-l(p)+1);return;}
	LL mid=(l(p)+r(p))/2;
	spread(p);
	if(l<=mid) change(l,r,p*2,k);
	if(r>=mid+1) change(l,r,p*2+1,k);
	sum(p)=sum(p*2)+sum(p*2+1);
}
LL ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	LL mid=(l(p)+r(p))/2,val=0;
	if(l<=mid) val+=ask(l,r,p*2);
	if(r>=mid+1) val+=ask(l,r,p*2+1);
	return val;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ans[i];
	build(1,n,1);
	int t,a,b,c;
	while(m--)
	{
		cin>>t;
		if(t==1){
			cin>>a>>b>>c;
			change(a,b,1,c);
		}
		if(t==2){
			cin>>c;
			change(1,1,1,c);
		}
		if(t==3){
			cin>>c;
			change(1,1,1,-c);
		}
		if(t==4){
			cin>>a>>b;
			cout<<ask(a,b,1)<<endl;
		}
		if(t==5){
			cout<<ask(1,1,1)<<endl;
		}
	}
}
