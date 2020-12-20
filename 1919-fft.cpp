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
const double Pi = acos(-1.0);
string str1,str2;
struct complex
{
	double x,y;
	complex(double xx=0,double yy=0){x=xx,y=yy;}
	complex operator+(complex z){return complex(x+z.x,y+z.y);}
	complex operator-(complex z){return complex(x-z.x,y-z.y);}
	complex operator*(complex z){return complex(x*z.x-y*z.y,y*z.x+x*z.y);}
	void pow2(){*this=complex((x+y)*(x-y),2*x*y);}
};
unsigned int i;
vector<complex>fft(vector<complex>a,int type)
{
	if(a.size()==1) return a;
	vector<complex>a1,a2;
	for(unsigned int i=0;i<a.size();i+=2) a1.push_back(a[i]),a2.push_back(a[i+1]);
	a1=fft(a1,type);
	a2=fft(a2,type);
	complex w=complex(1,0),Wn=complex(cos(2*Pi/a.size()),type*sin(2*Pi/a.size())),t;
	for(i=0;i<a.size()>>1;i++,w=w*Wn)
	{
		t=w*a2[i];
		a[i]=a1[i]+t;
		a[i+(a.size()>>1)]=a1[i]-t;
	}
	return a;
}
vector<complex>a;
LL ans[2097152];/*(2<<21)+1*/
void res(string & str)
{
	for(i=0;i<str.size()/2;i++) swap(str[i],str[str.size()-i-1]);
}
unsigned int limit;
int main()
{
	cin>>str1>>str2;
	res(str1);
	res(str2);
//	cout<<str1<<endl;
	limit=1;while(limit<=str1.size()+str2.size()-1) limit<<=1;
	a.reserve(limit);
//	cout<<limit<<endl;
	for(i=0;i<limit;i++) 
	a.push_back(complex(i<str1.size()?(str1[i]>='0'&&str1[i]<='9'?str1[i]-'0':0):0,
				 i<str2.size()?(str2[i]>='0'&&str2[i]<='9'?str2[i]-'0':0):0));
	//(i<str.size())xxx:0
	a=fft(a,1);
//	debug for(int i=0;i<limit;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
	for(i=0;i<limit;i++) a[i].pow2();
//	debug for(int i=0;i<limit;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
	a=fft(a,-1);
//	debug for(int i=0;i<limit;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
	for(i=0;i<limit;i++) ans[i]=a[i].y/limit/2+0.5;
//	debug for(int i=0;i<limit;i++) cout<<ans[i]<<" ";cout<<endl;
	for(i=0;i<limit-1;i++) ans[i+1]+=ans[i]/10,ans[i]%=10;
	bool flag=0;
	for(i=limit-1;i>0;i--)
	{
		if(ans[i]) flag=1;
		if(flag) putchar(ans[i]+'0');
	}
	putchar(ans[0]+'0');
	return 0;
}


