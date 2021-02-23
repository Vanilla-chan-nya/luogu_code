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
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
string str,t;
LL r[300010],pre[300010],suf[300010],sum[300010],ans;
void init()
{
	memset(r,0,sizeof(r));
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	memset(sum,0,sizeof(sum));
	t.clear();
	t="$#";
	for(int i=0;i<str.size();i++)
	{
		t+=str[i];
		t+='#';
	}
	t+='@';
	str=t;
}
void manacher()
{
	int mx=1,p=1;
	for(int i=1;i<str.size()-1;i++)
	{
		if(i<mx) r[i]=min((LL)mx-i,r[2*p-i]);
		else r[i]=1;
		while(str[i-r[i]]==str[i+r[i]]) r[i]++;
		if(mx<i+r[i])
		{
			p=i;
			mx=i+r[i];
		}
	}
}
int main()
{
	cin>>str;
	{
		int len=str.size();
		init();
//		cout<<str<<endl;
		manacher();
		for(int i=2;i<=len*2;i++)
		{
			int x=(i+1)/2;
			suf[x]++;
			suf[x+r[i]/2]--;
		}
		for(int i=len*2;i>=2;i--)
		{
			int x=i/2;
			pre[x]++;
			pre[x-r[i]/2]--;
		}
		for(int i=len;i>=1;i--)
		{
			pre[i]+=pre[i+1];
		}
		for(int i=1;i<=len;i++)
		{
			suf[i]+=suf[i-1];
			sum[i]=sum[i-1]+suf[i];
		}
		ans=0;
		for(int i=1;i<=len;i++)
		{
			ans+=pre[i]*sum[i-1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
