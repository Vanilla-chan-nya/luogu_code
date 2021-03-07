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
#include<fstream>
vector<int>ans;
int main()
{
	ans.clear();
	system("5048-rand.exe");
	system("5048-lc.exe");
	ifstream f1("5048-fhx.out");
	while(f1.peek()&&!f1.eof())
	{
		int t;
		f1>>t;
		ans.push_back(t);
	}
	system("5048.exe");
	ifstream f2("5048-hsh.out");
	int a=0;
	debug
	while(f2.peek()&&!f2.eof())
	{
		int t;
		f2>>t;
		if(a>=ans.size()||ans[a]!=t) 
		{
			cout<<"diff on line "<<a<<endl;
			system("pause");
			break;
		}
		a++;
	}
	
//	system("pause");
	main();
	return 0;
}


