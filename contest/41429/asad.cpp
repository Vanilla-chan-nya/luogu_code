#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
int n,m,a[32],b[32];
signed main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,n-1)a[i]=0,b[i]=i;
	while(m--){
		int op;scanf("%lld",&op);
		if(op==1){
			int x;scanf("%lld",&x);
			int now=b[0],cur=a[0];
			rep(i,0,n-1)b[i]=b[i+1],a[i]=a[i+1];
			b[n-1]=now;a[n-1]=cur^x;
		}
		else{
			int ans=0,x;
			scanf("%lld",&x);
			rep(i,0,n-1)ans+=(((x>>b[i])&1)^a[i])<<i;
			printf("%lld\n",ans);
		}
		putchar('\n');
	cout<<"ss"<<" ";rep(i,0,n-1)printf("%lld ",a[i]);putchar('\n');
	cout<<"ss"<<" ";rep(i,0,n-1)printf("%lld ",b[i]);putchar('\n');
		putchar('\n');
	}
	return 0;
}
