#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,c,k;
bool b[64],d[1000001],tb[64];
int f[64];
void ird(int &x)
{
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return ;
}
void urd(unsigned long long &x)
{
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return ;
}
char p[101];
int pt;
void PutULL(unsigned long long x)
{
	if(x==0)
	{
		printf("0\n");
		return ;
	}
	pt=0;
	while(x)
	{
		p[++pt]='0'+(x%10);
		x/=10;
	}
	for(int i=pt;i>=1;i--)
		printf("%c",p[i]);
	printf("\n");
	return ;
}
int gt(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=gt(f[x]);
}
struct Query
{
	int p,q;
}g[1000001];
bool operator <(const Query &as,const Query &bs)
{
	return as.q<bs.q;
}
vector<int> vc[1000001];
int main()
{
	//freopen("zoo.in","r",stdin);
	//freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	unsigned long long x=0;
	for(int i=0;i<64;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		urd(x);
		for(int j=0;j<k;j++)
		{
			b[j]|=(x&1);
			x>>=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		ird(g[i].p);
		ird(g[i].q);
	}
	sort(g+1,g+m+1);
	int lst=0,qcn=0,cnt=k;
	for(int i=1;i<=m;i++)
	{
		if(g[i].q!=lst)
		{
			lst=g[i].q;
			g[i].q=++qcn;
			continue;
		}
		g[i].q=qcn;
	}
	for(int i=1;i<=m;i++)
	{
		vc[g[i].q].push_back(g[i].p);
		if(b[g[i].p]) d[g[i].q]=true;
	}
	for(int i=1;i<=m;i++)
		if(d[i]==false)
		{
			for(int j=0;j<vc[i].size();j++)
			{
				if(tb[vc[i][j]]==false)
				{
					tb[vc[i][j]]=true;
					cnt--;
				}
			}
		}
	unsigned long long ns=0;
	if(cnt==64&&!n)
	{
		puts("18446744073709551616");
		return 0;
	}
	if(cnt!=64)
		ns=((unsigned long long)1<<(unsigned long long)cnt);
	ns-=(unsigned long long)n;
	PutULL(ns);
	return 0;
}
