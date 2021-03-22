/**************************************************************
 * Problem:
 * Author: Vanilla_chan
 * Date:
**************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
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

template<class T>inline void read(T& x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do { G[++g]=x%10;x/=10; } while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}

#include<fstream>
int main()
{
	cout<<"making"<<endl;
	system("5071-rand.exe");
	cout<<"run self"<<endl;
	system("5071-self.exe");
	cout<<"run std"<<endl;
	system("5071-2.exe");
	cout<<"comp"<<endl;
	if(system("comp \"E:\\Olympic of Information\\code\\luogu_code\\5071.ans\" \"E:\\Olympic of Information\\code\\luogu_code\\5071.out\"  /A /L /M")!=0)
	{
		cout<<"diff:"<<endl;
		int line=0;
		ifstream f1("5071.ans"),f2("5071.out");
		while(f1.peek()&&!f1.eof())
		{
			line++;
			int x,y;
			f1>>x;
			f2>>y;
			if(x!=y)
			{
				cout<<"line="<<line<<endl;
			}
		}
		system("pause");
	}
	cout<<endl<<endl;
	main();
	return 0;
}



