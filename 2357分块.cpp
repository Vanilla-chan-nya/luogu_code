//°¢¹ÅÂ·ÓÐ£¬´øÞú£¡ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
using namespace std;

template<class T>inline void read(T&x)

{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
int G[55];
template<class T>inline void write(T x)

{
    int g=0;
    do{G[++g]=x%10;x/=10;}while(x);
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
int n,f; 
int geo[200010];
int size;
int add[500],sum[500],p[200010];
/*
n=26
size=5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
26
*/
int main()
{
	cin>>n>>f;
	size=sqrt(n);
	for(int i=1;i<=n;i++) read(geo[i]),p[i]=(i-1)/size,sum[p[i]]+=geo[i]; 
	while(f--)
	{
		int t,l,r,k;read(t);
		if(t==1){
			read(l),read(r),read(k);
			if(p[l]==p[r]){
				for(int i=l;i<=r;i++) geo[i]+=k;
				sum[l]+=k*(r-l+1);
			}
			else{
				for(int i=l;i<(p[l]+1)*size;i++) sum[i]+=k,geo[i]+=k;
				sum[l]+=k*(p[l]+1)*size
				for(int i=p[r]*size;i<=r;i++) sum[i]+=k,geo[i]+=k;
				for(int i=p[l]+1;i<p[r];i++) add[i]+=k;
			}
		}
		if(t==2){
			read(k);
			geo[1]+=k;
			sum[0]+=k;
		}
		if(t==3){
			read(k);
			geo[1]-=k;
			sum[0]-=k;
		}
		if(t==4){
			read(l),read(r);
			LL ans=0;
			if(p[l]==p[r]) for(int i=l;i<=r;i++) ans+=geo[i];
			else{
				for(int i=l;i<p[l]*size+size;i++) ans+=geo[i]+add[p[i]];
				for(int i=p[r]*size;i<=r;i++) ans+=geo[i]+add[p[i]];
				for(int i=p[l]+1;i<p[r];i++) ans+=sum[i]+add[i]*size;
			}
			cout<<ans;
		}
		if(t==5) write(geo[1]+add[0]),puts("\n");
	}
	return 0;
}



