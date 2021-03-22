#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#define LL long long
#define int long long
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
int pri[170],cct=0,sum[100005][169],num[1005];
void sieve(){
    for(int i=2;i<=1000;++i)num[i]=1;
    for(int i=2;i<=1000;++i)
    if(num[i]){
        pri[num[i]=++cct]=i;
        for(int j=i<<1;j<=1000;j+=i)num[j]=0;
    }
}
vector<int>tj;
const int pr[]={2,3,5,7,11,13,17};
LL gcd(LL a,LL b)
{
	if(!a||!b) return a|b;
	if(b) return gcd(b,a%b);
	return a;
}
inline LL power(int a,int b,const int&md){
    LL ans=1;
    for(;b;b>>=1){
        if(b&1)ans=(LL)ans*a%md;
        a=(LL)a*a%md;
    }
    return ans;
}
inline LL qpow(int a,int b,const int&md){
    LL ans=1;
    for(;b;b>>=1){
        if(b&1)ans=(LL)ans*a%md;
        a=(LL)a*a%md;
    }
    return ans;
}
int miller_rabin(int p){
    if(p==2)return 1;
    int b=p-1;
    int t=0;
    while(!(b&1))b>>=1,++t;
    for(int e=0;e<7;e++)
	{
		int i=pr[e];
		LL r=qpow(i%(p-2)+2,b,p);
		if(r==1||r==p-1) continue;
		int flag=1;
		for(int j=1;j<=t&&flag;j++)
		{
			r=r*r%p;
			if(r==p-1) flag=0;
		}
		if(flag) return 0;
	}
    return 1;
}
void pollard_rho(int&n,int c){
    int k=2,x=rand()%(n-1)+1,y=x,q=1,t=1;
    for(;;k<<=1,y=x,q=1){
        for(int i=1;i<=k;++i){
            x=((LL)x*x%n+c)%n;
            q=(LL)q*abs(x-y)%n;
            if(!(i&63)){
                t=gcd(q,n);
                if(t>1)break;
            }
        }
        if(t>1||(t=gcd(q,n))>1)break;
    }
    n=t;
}
void find(int n,int c){
    if(n==1)return;
    if(miller_rabin(n)){tj.push_back(n);return;}
    int p=n;
    while(p>=n)pollard_rho(p,c),c--;
    n/=p;
    tj.push_back(n),tj.push_back(p);
}
#define N 100005
#define md 19260817
int n,m,a[N],inv[N*3],cnt[N],tot[N*2],now=1,ans[N];
int p[N][3];
vector<int>lr;
struct que{
    static const int siz=500;
    int l,r,id;
    inline bool operator<(const que&rhs)const{
        return((l/siz!=rhs.l/siz)?(l<rhs.l):r<rhs.r);
    }
}q[N];
inline void add(int id){
    for(register int i=1;i<=cnt[id];++i)
    now=(LL)now*inv[tot[p[id][i]]]%md*(tot[p[id][i]]+1)%md,++tot[p[id][i]];
}
inline void del(int id){
    for(register int i=1;i<=cnt[id];++i)
    now=(LL)now*inv[tot[p[id][i]]]%md*(tot[p[id][i]]-1)%md,--tot[p[id][i]];
}
signed main(){
	freopen("5071.in","r",stdin);
	freopen("5071.ans","w",stdout);
    sieve();
    cin>>n>>m;
    inv[0]=inv[1]=1;
    for(int i=2;i<=3*n;++i)inv[i]=(md-md/i)*inv[md%i]%md;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        memcpy(sum[i],sum[i-1],sizeof*sum);
        for(int j=1;j<=cct&&pri[j]*pri[j]<=a[i];++j)
        while(!(a[i]%pri[j])){
            ++sum[i][j];
            a[i]/=pri[j];
        }
        if(a[i]>1){
            if(a[i]<=pri[cct]){
                ++sum[i][num[a[i]]];
//                debug
                continue;
            }
            tj.clear();
            find(a[i],777777);
            for(int e=0;e<tj.size();e++)
			{
				++cnt[i];
				p[i][cnt[i]]=tj[e];
				lr.push_back(tj[e]);
			}
        }
    }
    sort(lr.begin(),lr.end());
    lr.erase(unique(lr.begin(),lr.end()),lr.end());
    for(int i=1;i<=n;++i)
    for(int j=1;j<=cnt[i];++j)p[i][j]=lower_bound(lr.begin(),lr.end(),p[i][j])-lr.begin();
    for(int i=1;i<=m;++i)cin>>q[q[i].id=i].l>>q[i].r;
    sort(q+1,q+m+1);
    for(int i=0;i<n<<1;++i)tot[i]=1;
    for(int i=1,l=1,r=0;i<=m;++i){
        while(r<q[i].r)add(++r);
        while(r>q[i].r)del(r--);
        while(l>q[i].l)add(--l);
        while(l<q[i].l)del(l++);
        ans[q[i].id]=now;
		for(int j=1;j<=cct;j++)
		{
			ans[q[i].id]=ans[q[i].id]*(sum[r][j]-sum[l-1][j]+1)%md;
			//cout<<ans[q[i].id]<<endl;
		}
    }
    for(int i=1;i<=m;++i)
    cout<<ans[i]<<endl;
    return 0;
}
