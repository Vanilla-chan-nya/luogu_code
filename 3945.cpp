#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
const long double G = 6.67408e-11;
const long double dt = 1e-2;
int n;
long double T;
struct vector
{
	long double x,y,z;
	vector(long double xx=0,long double yy=0,long double zz=0)
	{
		x=xx,y=yy,z=zz;
	}
	void clear()
	{
		x=y=z=0;
	}
	void in()
	{
		cin>>x>>y>>z;
	}
	void out()
	{
		printf("%Lf %Lf %Lf",x,y,z);
	}
	vector operator+(const vector& b)const
	{
		return vector(x+b.x,y+b.y,z+b.z);
	}
	vector operator+=(const vector& b)
	{
		x+=b.x;
		y+=b.y;
		z+=b.z;
		return *this;
	}
	vector operator*(const long double& b)
	{
		return vector(x*b,y*b,z*b);
	}
	vector operator*=(const long double& b)
	{
		x*=b;
		y*=b;
		z*=b;
		return *this;
	}
	vector operator/(const long double& b)const
	{
		return vector(x/b,y/b,z/b);
	}
}F[100];
struct Star
{
	vector pos,v;
	long double m;
	IL void in()
	{
		pos.in();
		cin>>m;
		v.in();
	}
	IL void out()
	{
		pos.out();
	}
	
}star[100];
int main()
{
	cin>>n>>T;
	for(int i=1;i<=n;i++) star[i].in();
	long double f,r;
	for(;T>0;T-=dt)
	{
		for(int i=1;i<=n;i++) F[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				r=(star[i].pos.x-star[j].pos.x)*(star[i].pos.x-star[j].pos.x)+(star[i].pos.y-star[j].pos.y)*(star[i].pos.y-star[j].pos.y)+(star[i].pos.z-star[j].pos.z)*(star[i].pos.z-star[j].pos.z);
				f=G*star[j].m/r;
				F[i]+=vector(f*(star[j].pos.x-star[i].pos.x)/sqrt(r),f*(star[j].pos.y-star[i].pos.y)/sqrt(r),f*(star[j].pos.z-star[i].pos.z)/sqrt(r));
			}
		}
		for(int i=1;i<=n;i++)
		{
			star[i].v+=F[i]*dt;
			star[i].pos+=(star[i].v)*dt;
		}
	}
	for(int i=1;i<=n;i++)
	{
		star[i].out();
		cout<<endl;
	}
	return 0;
}

