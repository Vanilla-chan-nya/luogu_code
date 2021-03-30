/**************************************************************
 * Problem: 4940
 * Author: Vanilla_chan
 * Date: 20210326
 * E-Mail: Vanilla_chan@outlook.com
**************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
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

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
	inline ULL read()
	{
		ULL x=0;
		char ch=getchar();
		while(!isdigit(ch)&&ch!='-') ch=getchar();
		x=ch-'0';ch=getchar();
		while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
		return x;
	}
	int G[55];
	template<class T>inline void write(T x)
	{
		int g=0;
		if(x<0) x=-x,putchar('-');
		do { G[++g]=x%10;x/=10; } while(x);
		for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
	}
};
using namespace oi;


deque<ULL>q[2];
string str;
int ys[2]={0,1};
bool res[2]={0,0};
ULL x,y,z;
void push(ULL x,ULL y)
{
	x=ys[x];
	if(res[x]) q[x].push_front(y);
	else q[x].push_back(y);
}
ULL pop(ULL x)
{
	ULL int y;
	x=ys[x];
	if(q[x].size()==0) return -1;
	if(res[x])
	{
		y=q[x].front();
		q[x].pop_front();
		return y;
	}
	else
	{
		y=q[x].back();
		q[x].pop_back();
		return y;
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	while(1)
	{
		oi::cin>>str;
		if(str=="PUSH")
		{
			oi::cin>>x;
			push(x,read());
			cout<<"SUCCESS"<<endl;
		}
		else if(str=="POP")
		{
			oi::cin>>x;
			if(pop(x)+1==0) cout<<"UNSUCCESS"<<endl;
			else cout<<"SUCCESS"<<endl;
		}
		else if(str=="ADD")
		{
			oi::cin>>x;
			if(q[1].size()==0||q[0].size()==0)
			{
				cout<<"UNSUCCESS"<<endl;
			}
			else
			{
				y=pop(0);
				z=pop(1);
				push(x,y+z);
				cout<<"SUCCESS"<<endl;
			}
		}
		else if(str=="SUB")
		{
			oi::cin>>x;
			if(q[1].size()==0||q[0].size()==0)
			{
				cout<<"UNSUCCESS"<<endl;
			}
			else
			{
				y=pop(0);
				z=pop(1);
				push(x,y>z?y-z:z-y);
				cout<<"SUCCESS"<<endl;
			}
		}
		else if(str=="DEL")
		{
			oi::cin>>x;
			while(pop(x)+1);
			cout<<"SUCCESS"<<endl;
		}
		else if(str=="MOVE")
		{
			oi::cin>>x>>y;
			if(q[ys[x]].size()>=q[ys[y]].size())
			{
				while(1)
				{
					z=pop(y);
					if(z+1==0) break;
					push(x,z);
				}
			}
			else
			{
				while(1)
				{
					z=pop(x);
					if(z+1==0) break;
					push(y,z);
				}
				res[ys[y]]^=1;
				swap(ys[0],ys[1]);
			}
			cout<<"SUCCESS"<<endl;
		}
		else if(str=="SWAP")
		{
			swap(ys[0],ys[1]);
			cout<<"SUCCESS"<<endl;
		}
		else if(str=="END")
		{
			cout<<"SUCCESS"<<endl;
			if(q[ys[0]].size()==0) cout<<"NONE";
			else while(1)
			{
				z=pop(0);
				if(z+1==0) break;
				cout<<z<<" ";
			}
			cout<<endl;
			if(q[ys[1]].size()==0) cout<<"NONE"<<endl;
			else while(1)
			{
				z=pop(1);
				if(z+1==0) break;
				cout<<z<<" ";
			}
			cout<<endl;
			break;
		}
	}
	return 0;
}


