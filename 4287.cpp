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
int n;
int len;
char ch[1000010];
string t;
int r[1000010];
int p=0,mx=0,ans;
int main()
{
	n=read();
	cin>>t;
	ch[len++]='$';
	ch[len++]='#';
	for(int i=0;i<t.size();i++)
	{
		ch[len++]=t[i];
		ch[len++]='#';
	}
	ch[len]='\0';
//	for(int i=0;i<=len;i++) cout<<ch[i];
	for(int i=1;i<=len;i++)
	{
		r[i]=i<mx?min(mx-i,r[2*p-i]):1;
		while(ch[i-r[i]]==ch[i+r[i]]) r[i]++;
		if(i+r[i]>mx)
		{
			if(i&1)
			{
				for(int j=max(mx,i+4);j<i+r[i];j++)
				{
					if((j-i)%4==0&&r[(i-(j-i)/2)]-1>=(j-i)/2) ans=max(ans,j-i);
				}
			}
			mx=i+r[i];
			p=i;
		}
	}
	write(ans);
	return 0;
}
