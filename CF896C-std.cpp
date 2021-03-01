#include<bits/stdc++.h>
using namespace std;
long long n,m,seed,vmax;
long long rnd(){
	long long ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
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
struct node{
	long long l,r;
	mutable long long num;
	bool operator<(const node y) const{
		return l<y.l;
	}
};
set<node> s;
set<node>::iterator split(long long x){
	node tmp={x};
	set<node>::iterator it=s.lower_bound(tmp);
	if (it!=s.end()&&it->l==x){
		return it;
	}
	it--;
	long long l=it->l,r=it->r,num=it->num;
	s.erase(it);
	tmp={l,x-1,num};
	s.insert(tmp);
	tmp={x,r,num};
	return s.insert(tmp).first;
}
void assign(long long l,long long r,long long x){
	set<node>::iterator R=split(r+1);
	set<node>::iterator L=split(l);
	s.erase(L,R);
	node tmp={l,r,x};
	s.insert(tmp);
}
long long query_kth(long long l,long long r,long long k){
	set<node>::iterator R=split(r+1),L=split(l);
	vector<pair<long long,long long> > t;
	while (L!=R){
		t.push_back(make_pair(L->num,L->r-L->l+1));
		L++;
	}
	sort(t.begin(),t.end());
	for (long long i=0;i<t.size();i++){
		k-=t[i].second;
		if (k<=0){
			return t[i].first;
		}
	}
	return -2147483647;
}
long long query_pow_sum(long long l,long long r,long long x,long long y){
	set<node>::iterator R=split(r+1),L=split(l);
	long long ans=0;
	while (L!=R){
		ans+=qpow(L->num,x,y)*(L->r-L->l+1);
		ans%=y; 
		L++;
	}
	return ans;
}
void add(long long l,long long r,long long x){
	set<node>::iterator R=split(r+1),L=split(l);
	while (L!=R){
		L->num+=x;
		L++;
	}
}
int main(){
	cin>>n>>m>>seed>>vmax;
	for (long long i=1;i<=n;i++){
		node tmp={i,i,rnd()%vmax+1};
		s.insert(tmp);
	}
	for (long long i=1;i<=m;i++){
		long long op=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1,x,y;
		if (l>r){
			swap(l,r);
		}
		cout<<"op="<<op<<" l="<<l<<" r="<<r<<endl;
		if (op==3){
			x=(rnd()%(r-l+1))+1;
		}else{
			x=(rnd()%vmax)+1;
		}
		if (op==4){
			y=(rnd()%vmax)+1;
		}
		if (op==1){
			add(l,r,x);
		}
		if (op==2){
			cout<<" x="<<x<<endl;
			assign(l,r,x);
		}
		if (op==3){
			cout<<query_kth(l,r,x)<<endl;
		}
		if (op==4){
			cout<<query_pow_sum(l,r,x,y)<<endl;
		}
		
		for(set<node>::iterator it=s.begin();it!=s.end();it++)
		{
			cout<<"l="<<it->l<<" r="<<it->r<<" v="<<it->num<<endl;
		}
		
	}
}
