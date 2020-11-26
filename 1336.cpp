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
using namespace std;

IL int read()
{
	int ans=0;
	bool fu=0;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') fu=1,ch=getchar();
	while(ch<='9'&&ch>='0') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	if(fu) ans*=-1;
	return ans;
}
inline long long qpow(long long x,int y)
{
	long long res = 1;
	for( ; y ; y >>= 1,x = x * x)
		if(y & 1) res = x * res;
	return res;
}
int n,m;
LL a[300],b[300];
LL f[300][300];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
	memset(f,0x37,sizeof(f));
	for(int i=0;i<=m;i++) f[i][0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=j;k++)
			{
				f[i][j]=min(f[i][j],f[i-1][k]+a[i]*qpow(j-k,b[i]));
			}
		}
	}
	cout<<f[m][n];
	return 0;
}


