/**************************************************************
 * Problem: 5071
 * Author: Vanilla_chan
 * Date: 20210317
**************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#include<cctype>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
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
#define int long long
template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define N 200010
#define mod 19260817
int n,m;
LL a[N],inv[N<<2],cnt[N],tot[N<<1];
LL now=1;
LL ans[N];
LL p[N][3];
int block=500;
struct Ask
{
	int l,r,id;
	IL bool operator<(const Ask& z)const
	{
		if(l/block==r/block) return r<z.r;
		return l<z.l;
	}

}q[N];
void insert(int x)
{
	//cout<<x<<endl;
	for(re int i=1;i<=cnt[x];i++)
	{
		now=now*inv[tot[p[x][i]]]%mod*(tot[p[x][i]]+1)%mod;
		++tot[p[x][i]];
	}
}
void del(int x)
{
	for(re int i=1;i<=cnt[x];i++)
	{
		now=now*inv[tot[p[x][i]]]%mod*(tot[p[x][i]]-1)%mod;
		--tot[p[x][i]];
	}
}
LL prime[2000],pcnt,sum[N][200],book[10010];
void init()
{
	now=1; 
	inv[1]=1;
	for(re int i=2;i<=3*n;++i) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(re int i=2;i<=1000;i++) book[i]=1;
	for(re int i=2;i<=1000;i++)
	{
		if(book[i])
		{
			prime[book[i]=++pcnt]=i;
			for(re int j=i*2;j<=1000;j+=i) book[j]=0;
		}
	}
}
vector<LL>tt;
const int pr[10000]={2,3,5,7,11,13,17};

LL gcd(LL a,LL b)
{
	if(!a||!b) return a|b;
	if(b) return gcd(b,a%b);
	return a;
}

inline LL qpow(int a,int b,const int&md){
    LL ans=1;
    for(;b;b>>=1){
        if(b&1)ans=(LL)ans*a%md;
        a=(LL)a*a%md;
    }
    return ans;
}
LL miller(LL p)
{
	if(p==2) return 1;
	LL b=p-1;
	LL t=0;
	while((b&1)==0) b>>=1,t++;
	for(int e=0;e<7;e++)
	{
		int i=pr[e];
		LL r=qpow(i%(p-2)+2,b,p);
		if(r==1||r==p-1) continue;
		int flag=1;
		for(re int j=1;j<=t&&flag;j++)
		{
			r=r*r%p;
			if(r==p-1) flag=0;
		}
		if(flag) return 0;
	}
	return 1;
}
void pollard(LL &n,LL c)
{
	re LL k=2,x=rand()%(n-1)+1,y=x,q=1,t=1;
	for(;;k<<=1,y=x,q=1)
	{
		for(re LL i=1;i<=k;++i)
		{
			x=(x*x%n+c)%n;
			q=q*abs(x-y)%n;
			if((i&63)==0)
			{
				t=gcd(n,q);
				if(t>1) break;
			}
		}
		if(t>1||(t=gcd(n,q))>1) break;
	}
	n=t;
}
void find(LL n,LL c)
{
	if(n==1) return;
	if(miller(n)) 
	{ 
		tt.push_back(n);
		return;
	}
	LL p=n;
	while(p>=n) pollard(p,c),c--;
	n/=p;
	tt.push_back(n),tt.push_back(p);
}
vector<LL>lr;
signed main()
{
	srand(20050228);
	freopen("5071.in","r",stdin);
	freopen("5071.out","w",stdout);
	n=read();
	m=read();
	init();
	for(re int i=1;i<=n;i++)
	{
		a[i]=read();
		memcpy(sum[i],sum[i-1],sizeof*sum);
		for(re int j=1;j<=pcnt&&prime[j]*prime[j]<=a[i];j++)
		{
			while(a[i]%prime[j]==0)
			{
				sum[i][j]++;
				a[i]/=prime[j];
			}
		}
		if(a[i]>1)
		{
			if(a[i]<=prime[pcnt])
			{
				sum[i][book[a[i]]]++;
//				debug
				continue;
			}
			tt.clear();
			find(a[i],777777);
			for(int e=0;e<tt.size();e++)
			{
				++cnt[i];
				p[i][cnt[i]]=tt[e];
				lr.push_back(tt[e]);
			}
		}
	}
	//cout<<"len="<<lr.size()<<endl;
	sort(lr.begin(),lr.end());
	lr.erase(unique(lr.begin(),lr.end()),lr.end());
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=cnt[i];j++)
		{
			p[i][j]=lower_bound(lr.begin(),lr.end(),p[i][j])-lr.begin();
		}
	}
	debug 
	for(re int i=1;i<=m;i++) q[i].id=i,q[i].l=read(),q[i].r=read();
	sort(q+1,q+m+1);
	for(re int i=0;i<n*2;i++) tot[i]=1;
	re int l=1,r=0;
	for(re int i=1;i<=m;i++)
	{
		while(r<q[i].r) insert(++r);
		while(r>q[i].r) del(r--);
		while(l>q[i].l) insert(--l);
		while(l<q[i].l) del(l++);
		ans[q[i].id]=now;
		for(re int j=1;j<=pcnt;j++)
		{
			ans[q[i].id]=ans[q[i].id]*(sum[r][j]-sum[l-1][j]+1)%mod;
			//cout<<ans[q[i].id]<<endl;
		}
	}
	debug
	for(re int i=1;i<=m;i++)
		write(ans[i]);
	return 0;
}


