#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#define re register
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
    do{G[++g]=x%10;x/=10;}while(x);
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
vector<double>a,b;
vector<bool>gen;
int T,n;
//struct Float{
//	string x,y;
//	IL void read()
//	{
//		char ch;
//		do{
//			ch=getchar();
//		}while(!isdigit(ch));
//		
//	}
//};
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		a.clear();b.clear();gen.clear();
		for(int i=0;i<n;i++) gen.push_back(read());
		double t;
		for(int i=0;i<n;i++){
			cin>>t;
			if(!gen[i]) a.push_back(t); else b.push_back(t);
		}
		sort(a.begin(),a.end());
		for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
		cout<<endl;
		sort(b.begin(),b.end());
		for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
		cout<<endl;
		
	}
	
	//setiosflags(ios::fixed)<<setprecision(10)
	return 0;
}

