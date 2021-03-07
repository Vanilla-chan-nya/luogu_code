#include<bits/stdc++.h>
#define get_block(u) (u-1)/block+1	
using namespace std;
int block;
int a[500005],b[500005],s[725][500005],f[725][725],t[500005];
int main(){
	freopen("5048.in","r",stdin);
	freopen("5048-fhx.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	block=sqrt(n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int num=unique(b+1,b+1+n)-b-1,cnt=(n-1)/block+1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+1+num,a[i])-b;
	}
	for(int i=1;i<=cnt;++i){
		for(int j=(i-1)*block+1;j<=min(i*block,n);++j){
			++s[i][a[j]];
		}
		for(int j=1;j<=num;++j){
			s[i][j]+=s[i-1][j];
		}
	}
	for(int i=1;i<=cnt;++i){
		for(int j=i;j<=cnt;++j){
			int maxn=f[i][j-1];
			for(int k=(j-1)*block+1;k<=min(j*block,n);++k){
				int now=s[j][a[k]]-s[i-1][a[k]];
				int pre=s[j][maxn]-s[i-1][maxn];
				if(now>pre){
					maxn=a[k];
				}
			}
			f[i][j]=maxn;
		}
	}
	int x=0;
	for(int i=1;i<=m;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		l=l^x;r=r^x;
		if(l>r)	swap(l,r);
		int bl=get_block(l),br=get_block(r);
		int maxn=0,QwQ;
		if(br-bl<=1){
			for(int i=l;i<=r;++i)	++t[a[i]];
			for(int i=l;i<=r;++i){
				if(t[a[i]]>t[maxn]){
					maxn=a[i];
				}
			}
			QwQ=t[maxn];
			for(int i=l;i<=r;++i)	t[a[i]]=0;
		}
		else{
			for(int i=l;i<=min(bl*block,n);++i)	++t[a[i]];
			for(int i=(br-1)*block+1;i<=r;++i)	++t[a[i]];
			maxn=f[bl+1][br-1];
			for(int i=l;i<=min(bl*block,n);++i){
				int now=t[a[i]]+s[br-1][a[i]]-s[bl][a[i]];
				int pre=t[maxn]+s[br-1][maxn]-s[bl][maxn];
				if(now>pre){
					maxn=a[i];
				}
			}
			for(int i=(br-1)*block+1;i<=r;++i){
				int now=t[a[i]]+s[br-1][a[i]]-s[bl][a[i]];
				int pre=t[maxn]+s[br-1][maxn]-s[bl][maxn];
				if(now>pre){
					maxn=a[i];
				}
			}
			QwQ=t[maxn]+s[br-1][maxn]-s[bl][maxn]; 
			for(int i=l;i<=min(bl*block,n);++i)	t[a[i]]=0;
			for(int i=(br-1)*block+1;i<=r;++i)	t[a[i]]=0;
		}
		printf("%d\n",x=QwQ);
	}
	return 0;
}

