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
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
using namespace std;

template<class T>inline void read(T&x)
{
	char ch=getchar();
	int fu=1;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
char ch;
int fu,x;
const int inf = 0x7f7f7f7f;
inline int read()
{
	x=0,fu=1;
	ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55],g;
template<class T>inline void write(T x)
{
	g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}

LL t,n,a[2000010],queue1[2000010][2],queue2[2000010][2],l1,l2,r1,r2,ans;
class edge
{
	public:
	LL flag,sum,id;
	edge(re LL ff=0,re LL ss=0,re LL i=0){flag=ff,sum=ss,id=i;}
};
edge get_max()
{
	re LL sum=0,flag=1,id=0;
	if(l2<=r2)
	{
		if(queue2[r2][0]>=sum)
		{
			sum=queue2[r2][0];
			id=queue2[r2][1];
			flag=2;
		}
	}
	if(l1<=r1)
	{
		if(queue1[r1][0]>sum)
		{
			sum=queue1[r1][0];
			id=queue1[r1][1];
			flag=1;
		}
		else if(queue1[r1][0]==sum&&queue1[r1][1]>id)
		{
			sum=queue1[r1][0];
			id=queue1[r1][1];
			flag=1;
		}
	}
	if(flag==1) r1--;
	else r2--;
	return edge(flag,sum,id);
}

edge get_min()
{
	re int sum=inf,flag=1,id=0;
	if(l2<=r2)
	{
		if(queue2[l2][0]<=sum)
		{
			sum=queue2[l2][0];
			id=queue2[l2][1];
			flag=2;
		}
	}
	if(l1<=r1)
	{
		if(queue1[l1][0]<sum)
		{
			sum=queue1[l1][0];
			id=queue1[l1][1];
			flag=1;
		}
		else if(queue1[l1][0]==sum&&queue1[l1][1]<id)
		{
			sum=queue1[l1][0];
			id=queue1[l1][1];
			flag=1;
		}
	}
	if(flag==1) l1++;
	else l2++;
	return edge(flag,sum,id);
}

void sol1()
{
	while(n-ans!=1)
	{
		if(n-ans==1) return ;
		edge x=get_max(),y=get_min();//node!!!!!!!!!!!!
		edge z=get_min();
		if((x.sum-y.sum==z.sum&&x.id>z.id)||x.sum-y.sum>z.sum)
		{
			ans++;
			queue2[--l2][0]=x.sum-y.sum;queue2[l2][1]=x.id;
			if(l1<=r1&&(z.sum<queue1[l1][0]||(z.sum==queue1[l1][0]&&z.id<queue1[l1][1])))
			{
				queue1[--l1][0]=z.sum;
				queue1[l1][1]=z.id;
			}
			else
			{
				queue2[--l2][0]=z.sum;
				queue2[l2][1]=z.id;
			}
			continue;
		}
		else
		{
			if(x.flag==1)
			{
				queue1[++r1][0]=x.sum;
				queue1[r1][1]=x.id;
			}
			else
			{
				queue2[++r2][0]=x.sum;
				queue2[r2][1]=x.id;
			}
			if(y.flag==1)
			{
				queue1[--l1][0]=y.sum;
				queue1[l1][1]=y.id;
			}
			else
			{
				queue2[--l2][0]=y.sum;
				queue2[l2][1]=y.id;
			}
			if(z.flag==1)
			{
				queue1[--l1][0]=z.sum;
				queue1[l1][1]=z.id;
			}
			else
			{
				queue2[--l2][0]=z.sum;
				queue2[l2][1]=z.id;
			}
			return;
		}
	}
}

bool sol2(re int last)
{
	if(last==0) return 0;
	if(last==1) return 0;
	if(last==2) return 1;
	edge x=get_max(),y=get_min(),z=get_min();
	if((x.sum-y.sum==z.sum&&x.id>z.id)||x.sum-y.sum>z.sum) return 1;
	else
	{ 
		if(l1<=r1&&(z.sum<queue1[l1][0]||(z.sum==queue1[l1][1]&&queue1[l1][1]>z.id)))
		{
			queue1[--l1][0]=z.sum;
			queue1[l1][1]=z.id;
		}
		else
		{
			queue2[--l2][0]=z.sum;
			queue2[l2][1]=z.id;
		}
		if(l1<=r1&&(x.sum-y.sum<queue1[l1][0]||(x.sum-y.sum==queue1[l1][0]&&queue1[l1][1]>x.id)))
		{
			queue1[--l1][0]=x.sum-y.sum;
			queue1[l1][1]=x.id;
		}
		else
		{
			queue2[--l2][0]=x.sum-y.sum;
			queue2[l2][1]=x.id;
		}
		return !sol2(last-1);
	}
}
void init()
{
	ans=0;
	memset(queue1,0,sizeof(queue1));
	memset(queue2,0,sizeof(queue2));
}
bool flag;
int main()
{
	t=read();
	flag=0;
	while(t--)
	{
		init();
		if(!flag)
		{
			n=read();flag=1;
			for(re int i=1;i<=n;i++)
				a[i]=read();
		}
		else
		{
			for(re int i=1,k=read();i<=k;i++)
			{
				int x,y;x=read();y=read();a[x]=y;
			}
		}
		l1=1;r1=0;l2=n+1;r2=n;
		for(re int i=1;i<=n;i++)
		{
			queue1[++r1][0]=a[i];
		}
		for(re int i=1;i<=n;i++)
		{
			queue1[i][1]=i;
		}
		sol1();
		if(sol2(n-ans)) ans++;
		write(n-ans);
	}
	return 0;
}
