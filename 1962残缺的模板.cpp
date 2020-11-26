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
#define UI unsigned int
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
template <class T>
struct VEC
{
	vector<T>V;
	T empty;
	T operator[](UI a)
	{
		while(V.size()<=a) V.push_back(empty);
		return & V[a];
	}
};


template <class T>
struct matrix
{
	VEC< VEC<T> >A;
	VEC< T > empty;
	UI i,j;
	vector<T>operator[](UI x)
	{
		while(A.size()<=x) A.push_back(empty),i++;
		return A[x];
	}
	matrix()
	{
		i=j=0;
	}
	matrix(UI a,UI b)
	{
		i=a;j=b;
		A.clear();
		
	}
	void clear()
	{
		A.clear();
		i=j=0;
	}
	
	
};


int main()
{
	
	
	return 0;
}

