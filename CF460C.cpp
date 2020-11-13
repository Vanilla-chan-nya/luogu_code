#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int x=0,f=1;
	re char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') f*=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}


#define maxn 100010
int n,m,w;
int need[maxn];
int f[maxn];
bool judge(int s){
	int a=0,b=m;
	for(re int i=1;i<=n;i++){
		if(i>=w)
			a-=need[i-w];
		need[i]=max((int)0,s-a-f[i]);
		a+=need[i];
		b-=need[i];
		if(b<0)
			return false;
	}
	return true;
}
int main(){
	n=read();
	m=read();
	w=read();
	re int l=(1<<30);
	for(re int i=1;i<=n;i++){
		f[i]=read();
		l=min(f[i],l);
	}
	re int r=l+m;
	re int mid=(l+r>>1)+1;
	while(l<r){
		if(judge(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
		mid=(l+r>>1)+1;
	}
	cout<<l<<endl;
}

