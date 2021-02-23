#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<fstream>
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
vector<int>ans,out;
int cnt;
int main()
{
	system("3201-rand.exe");
	system("3201-ans.exe");
	system("3201.exe");
	ans.clear();
	out.clear();
	
	ifstream finout("P3201.out");
	while(finout.peek()&&!finout.eof())
	{
		int t;
		finout>>t;
		out.push_back(t);
	}
	ifstream finans("P3201.ans");
	while(finans.peek()&&!finans.eof())
	{
		int t;
		finans>>t;
		ans.push_back(t);
	}
	for(int i=0;i<ans.size();i++) if(ans[i]!=out[i])
	{
		cout<<"DIFF!"<<endl;
		system("pause");
		system("pause");
	}
	write(cnt++);
	main();
	
	return 0;
}


