#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#define ctz __builtin_ctz
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug 
#endif
using namespace std;
#ifdef ONLINE_JUDGE
struct istream{
    char buf[23333333],*s;
    inline istream(){
        buf[fread(s=buf,1,23333330,stdin)]='\n';
        fclose(stdin);
    }
    inline istream&operator>>(int&d){
        d=0;
        for(;!isdigit(*s);++s);
        while(isdigit(*s))
        d=(d<<3)+(d<<1)+(*s++^'0');
        return*this;
    }
}cin;
struct ostream{
    char buf[8000005],*s;
    inline ostream(){s=buf;}
    inline ostream&operator<<(int d){
        if(!d){
            *s++='0';
        }else{
            static int w;
            for(w=1;w<=d;w*=10);
            for(;w/=10;d%=w)*s++=d/w^'0';
        }
        return*this;
    }
    inline ostream&operator<<(const char&c){*s++=c;return*this;}
    inline void flush(){
        fwrite(buf,1,s-buf,stdout);
        s=buf;
    }
    inline~ostream(){flush();}
}cout;
#else
#include<iostream>
#endif
int pri[170],cct=0,sum[100005][169],num[1005];
void sieve(){
    for(int i=2;i<=1000;++i)num[i]=1;
    for(int i=2;i<=1000;++i)
    if(num[i]){
        pri[num[i]=++cct]=i;
        for(int j=i<<1;j<=1000;j+=i)num[j]=0;
    }
}
using LoveLive=long long;
vector<int>tj;
const int pr[]={2,3,5,7,11,13,17};
int gcd(int a,int b){
    if(!a||!b)return a|b;
    int t=ctz(a|b);
    a>>=ctz(a);
    do{
        b>>=ctz(b);
        if(a>b)swap(a,b);
        b-=a;
    }while(b);
    return a<<t;
}
inline int power(int a,int b,const int&md){
    int ans=1;
    for(;b;b>>=1){
        if(b&1)ans=(LoveLive)ans*a%md;
        a=(LoveLive)a*a%md;
    }
    return ans;
}
int miller_rabin(int p){
    if(p==2)return 1;
    int b=p-1;
    int t=0;
    while(!(b&1))b>>=1,++t;
    for(int i:pr){
        int r=power(i%(p-2)+2,b,p);
        if(r==1||r==p-1)continue;
        int ok=1;
        for(int j=1;j<=t&&ok;++j){
            r=(LoveLive)r*r%p;
            if(r==p-1)ok=0;
        }
        if(ok)return 0;
    }
    return 1;
}
void pollard_rho(int&n,int c){
    int k=2,x=rand()%(n-1)+1,y=x,q=1,t=1;
    for(;;k<<=1,y=x,q=1){
        for(int i=1;i<=k;++i){
            x=((LoveLive)x*x%n+c)%n;
            q=(LoveLive)q*abs(x-y)%n;
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
    while(p>=n)pollard_rho(p,c--);
    n/=p;
    tj.push_back(n),tj.push_back(p);
}
#define N 100005
const int md=19260817;
int n,m,a[N],inv[N*3],cnt[N],tot[N*2],now=1,ans[N];
int p[N][3];
vector<int>lr;
struct que{
    static const int siz=317;
    int l,r,id;
    inline bool operator<(const que&rhs)const{
        return((l/siz!=rhs.l/siz)?(l<rhs.l):r<rhs.r);
    }
}q[N];
inline void add(int id){
	cout<<id<<endl;
    for(register int i=1;i<=cnt[id];++i)
    now=(LoveLive)now*inv[tot[p[id][i]]]%md*(tot[p[id][i]]+1)%md,++tot[p[id][i]];
}
inline void del(int id){
    for(register int i=1;i<=cnt[id];++i)
    now=(LoveLive)now*inv[tot[p[id][i]]]%md*(tot[p[id][i]]-1)%md,--tot[p[id][i]];
}
int main(){
    srand(19260817);
    sieve();
    cin>>n>>m;
    inv[1]=1;
    for(int i=2;i<=3*n;++i)inv[i]=(md-md/i)*1LL*inv[md%i]%md;
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
                debug
                continue;
            }
            tj.clear();
            find(a[i],23333);
            for(int it:tj)
            p[i][++cnt[i]]=it,lr.push_back(it);
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
        int&out=ans[q[i].id];out=now;
//        debug cout<<now<<endl;
        for(int j=1;j<=cct;++j)
        out=(LoveLive)out*(sum[r][j]-sum[l-1][j]+1)%md;
//        debug cout<<q[i].id<<" "<<ans[q[i].id]<<endl;
    }
    for(int i=1;i<=m;++i)
    cout<<ans[i]<<'\n';
    return 0;
}
