#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define IL inline
#define re register
#define LL long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
using namespace std;
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
#define db double
const db Pi=acos(-1.0);
struct complex
{
	db x,y;
	complex(db xx=0,db yy=0){x=xx,y=yy;};
	complex operator+(complex z){return complex(x+z.x,y+z.y);}
	complex operator-(complex z){return complex(x-z.x,y-z.y);}
	complex operator*(complex z){return complex(x*z.x-y*z.y,y*z.x+x*z.y);}
};
vector<complex> fft(vector<complex>a,int type)
{
	if(a.size()==1) return a;
	vector<complex>a1,a2;
	for(re unsigned int i=0;i<a.size();i+=2) a1.push_back(a[i]),a2.push_back(a[i+1]);
	a1=fft(a1,type);
	a2=fft(a2,type);
	complex Wn=complex(cos(2*Pi/a.size()),type*sin(2*Pi/a.size())),w=complex(1,0);
	for(re unsigned int i=0;i<a.size()/2;i++,w=w*Wn)
	{
		a[i]=a1[i]+w*a2[i];
		a[i+a.size()/2]=a1[i]-w*a2[i];
	}
	return a;
}
vector<complex>a,b;
unsigned int n,m,i,limit;
int main()
{
	n=read();
	m=read();
	limit=1;while(limit<=n+m) limit<<=1;
	while(a.size()<limit) a.push_back(complex(0,0));
	while(b.size()<limit) b.push_back(complex(0,0));
	for(i=0;i<=n;i++) a[i]=complex(read(),0);
	for(i=0;i<=m;i++) a[i]=complex(a[i].x,read());
	
	a=fft(a,1);
	b=fft(b,1);
	for(i=0;i<a.size();i++)
		a[i]=a[i]*b[i];
	a=fft(a,-1);
	for(i=0;i<=n+m;i++) printf("%d ",(int)(a[i].x/limit+0.5));
	return 0;
}


