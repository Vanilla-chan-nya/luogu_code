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
int n,m;
struct node
{
	int prv,nxt;
	int l,r;
	char ch;
	node()
	{
		prv=nxt=0;
		l=r=ch=0;
	}
	node(int pp,int nn)
	{
		prv=pp;
		nxt=nn;
	}
	node(int ll,int rr,char cc)
	{
		l=ll;
		r=rr;
		ch=cc;
	}
	node(int pp,int nn,int ll,int rr,char cc)
	{
		prv=pp;
		nxt=nn;
		l=ll;
		r=rr;
		ch=cc;
	}
}b[500010];
int cnt;
#define head b[0].nxt
void del(int x)
{
	int l=b[x].prv,r=b[x].nxt;
	b[l].nxt=r;
	b[r].prv=l;
}
int insert(int l,int r,char ch)
{
	int pos;
	for(pos=head;pos;pos=b[pos].nxt)
	{
		if(b[pos].r==l-1) break;
	}
	int nxt=b[pos].nxt;
	++cnt;
	b[cnt]=node(pos,nxt,l,r,ch);
	b[pos].nxt=b[nxt].prv=cnt;
	return cnt;
}
int split(int x)
{
	int pos;
	for(pos=head;pos;pos=b[pos].nxt)
	{
		if(b[pos].l>=x) break;
	}
	if(!pos) return -1;
	if(b[pos].l==x) return pos;
	int l=b[pos].l,r=b[pos].r;
	char ch=b[pos].ch;
	del(pos);
	insert(l,b[pos].l-1,ch);
	insert(b[pos].l+1,r,ch);
	return cnt;
}
vector<int>dell;
int assign(int l,int r,char ch)
{
	int y=split(r+1);
	int x=split(l);
	dell.clear();
	for(int pos=x,l,r;pos!=y;pos=b[pos].nxt)
	{
//		l=max()
		dell.push_back(pos);
	}
	for(int i=0;i<dell.size();i++) del(dell[i]);
	return insert(l,r,ch);
}
int s[30];
int main()
{
	n=read();
	m=read();
	char k;
	head=1;
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k<='z'&&k>='a') k+='A'-'a';
		b[i].l=b[i].r=i;
		b[i].ch=k;
		b[i].prv=i-1;
		b[i].nxt=i+1;
		cout<<k<<endl;
	}
	b[n].nxt=0;
	int t,x,y,ans;
	while(m--)
	{
		t=read();
		ans=0;
		if(t==1)
		{
//			debug
			cin>>x>>y>>k;
			if(k<='z'&&k>='a') k+='A'-'a';
			for(int pos=head,l,r;pos;pos=b[pos].nxt)
			{
				if(b[pos].ch==k)
				{
					if(b[pos].r<x) continue;
					if(b[pos].l>y) continue;
					l=max(x,b[pos].l);
					r=min(y,b[pos].r);
//					if(l>r) cout<<"l>r!!!"<<endl;
					ans+=r-l+1;
				}
			}
			cout<<ans<<endl;
		}
		else if(t==2)
		{
			cin>>x>>y>>k;
			if(k<='z'&&k>='a') k+='A'-'a';
			assign(x,y,k);
		}
		else
		{
			memset(s,0,sizeof(s));
			cin>>x>>y;
			dell.clear();
			for(int pos=head,l,r;pos;pos=b[pos].nxt)
			{
				debug cout<<"now="<<pos<<endl;
				l=max(b[pos].l,x);
				r=min(b[pos].r,y);
				k=b[pos].ch;
				if(k<='Z'&&k>='A') k-='A';
				else k-='a';
				if(l<=r)
				{
					s[k]+=r-l+1;
					if(l==b[pos].l&&r==b[pos].r) dell.push_back(pos);
					else
					{
						if(r!=b[pos].r) split(r+1);
						if(l!=b[pos].l) pos=split(l);
						dell.push_back(pos);
					}
				}
			}
			for(int i=0;i<dell.size();i++) del(dell[i]);
			for(int i=0;i<26;i++)
			{
				if(s[i]) insert(x,x+s[i]-1,char(i+'A'));
				x+=s[i];
				for(int j=0;j<s[i];j++)
					cout<<char(i+'A');
			}
			cout<<endl;
		}
		for(int pos=head;pos;pos=b[pos].nxt)
		{
			cout<<"pos="<<pos<<" "<<b[pos].l<<" "<<b[pos].r<<" "<<b[pos].ch<<" prv="<<b[pos].prv<<" nxt="<<b[pos].nxt<<endl;
		}
//		system("pause");
	}
	return 0;
}


