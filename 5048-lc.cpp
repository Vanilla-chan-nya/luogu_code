#include<bits/stdc++.h>
#define re register 
#define mod 998244353
#define N 500050
#define eps (1e-10)
//#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n,ans,S,s,m,q,lstans;
int bl[750],br[750],sum[750][750]; 
int p[N],a[N],b[N],tot[N];
vector <int> v[N];
template <class T> inline void read(T &x)
{
	x=0;int g=1;char ss=getchar();
	for (;ss>'9'||ss<'0';ss=getchar()) if (ss=='-') g=-1;
	for (;ss<='9'&&ss>='0';ss=getchar()) x=(x<<1)+(x<<3)+(ss^48);	
	x*=g;
} 
void blo()
{
	re int i,k=0;
	sort(b,b+n);
	m=unique(b,b+n)-b;
	for (i=0;i<n;i++)
	{int tt=lower_bound(b,b+m,a[i])-b;a[i]=tt;}	
	for (i=0;i<n;i++)
	if (i%S==0) br[k]=i-1,bl[++k]=i;
	br[k]=n-1;bl[k+1]=br[k+1]=n;s=k;
}
void init()
{
	re int i,j,k;
	for (i=1;i<=s;i++)
	{
		memset(tot,0,sizeof(tot));
		for (j=i;j<=s;j++)
		{
			sum[i][j]=sum[i][j-1];
			for (k=bl[j];k<=br[j];k++) 
			sum[i][j]=max(sum[i][j],++tot[a[k]]);
		}
	}
	for (i=0;i<n;i++)
	{
		v[a[i]].push_back(i);
		p[i]=v[a[i]].size()-1;
	}
}
int query(int l,int r)
{
	re int i,j;
	re int x=l/S+1,y=r/S+1;
	if (x==y)
	{
		ans=0;
		for(i=l;i<=r;i++) ans=max(ans,++tot[a[i]]);
		for(i=l;i<=r;i++) tot[a[i]]=0;
		return ans;
	}
	ans=sum[x+1][y-1];
	for (i=l;i<=br[x];i++)
	{
		while(p[a[i]]+ans<v[a[i]].size()&&v[a[i]][p[a[i]]+ans]<=r) ++ans;
	}
	for (i=bl[y];i<=r;i++)
	{
		while(p[a[i]]-ans>=0&&v[a[i]][p[a[i]]-ans]>=l) ++ans;
	}
	return ans;
}
int main()
{
	freopen("5048.in","r",stdin);
	freopen("5048-lc.out","w",stdout);
	re int i,j,l,r;
	read(n);read(q);
	for (i=0;i<n;i++)
	{read(a[i]);b[i]=a[i];}
	S=(int)sqrt(n);
	blo();init();
	memset(tot,0,sizeof(tot)); 
	while(q--)
	{
		read(l);read(r);
		l=l^lstans;r=r^lstans;
		if (l>r) swap(l,r);
		ans=0;
		l--;r--; 
		lstans=query(l,r);
		printf("%d\n",lstans);
	}
	/*
	printf("%d\n",s);
	for (i=0;i<n;i++) printf("%d ",p[i]);
	printf("\n");
	for (i=0;i<m;i++,printf("\n"))
	for (j=0;j<v[i].size();j++) 
	printf("%d ",v[i][j]);
	*/
	return 0;
}
