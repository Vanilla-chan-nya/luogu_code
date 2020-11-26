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
#define re register
#define debug printf("Now is %d\n",__LINE__);
using namespace std;

template<class T>inline void read(T&x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    int g=0;
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
string a,b;
set<string>had;
int nxt[1000010];
LL t,ans;
bool h[500000];
LL p=491461;
int hsh(string t)
{
	LL ans=0;
	for(int i=0;i<t.size();i++)
	{
		ans*=p;
		ans+=t[i]-'a';
	}
	return ans%p;
}

void judge(LL pos)
{
//	debug cout<<"pos="<<pos<<endl;
//	string c=a.substr(0,pos);
//	cout<<"c="<<c<<endl;
	for(re LL i=0;i<pos;i++)
	{
//		cout<<c.substr(i,pos)<<endl;
		if(h[hsh(a.substr(i,pos-i))]==0) h[hsh(a.substr(i,pos-i))]=1,ans++;
	}
}
void kmp()
{
	re LL j=-1;
	nxt[0]=-1;
	for(re LL i=1;i<b.size();i++)
	{
		while(j>-1&&b[i]!=b[j+1]) j=nxt[j];
		if(b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
	j=-1;
	for(re LL i=0;i<a.size();i++)
	{
		while(j>-1&&a[i]!=b[j+1]) j=nxt[j];
		if(a[i]==b[j+1]) j++;
		if(j==b.size()-1){
//			cout<<i-b.size()+2<<endl;
			judge(i+2-b.size());
			j=nxt[j];
		}
	}
}
int main()
{
	cin>>a;
	t=read();
	while(t--)
	{
		ans=0;
		cin>>b;
		had.clear();
		memset(h,0,sizeof(h));
		memset(nxt,0,sizeof(nxt));
		kmp();
		cout<<ans<<endl;
	}
	
	return 0;
}

