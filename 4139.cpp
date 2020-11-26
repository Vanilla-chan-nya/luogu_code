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
#define debug printf("Now is %d\n",__LINE__);
using namespace std;
LL phi[10000010];
LL maxn=10000000;
LL t;
void pre()
{
//	debug
	phi[1]=1;
	for(int i=2;i<=maxn;i++)
	{	
		if(!phi[i])
		for(int j=i;j<=maxn;j+=i)
		{
			if(!phi[j]) phi[j]=j;
			phi[j]=phi[j]*(i-1)/i;
		}
//		debug cout<<"i="<<i<<" phi="<<phi[i]<<endl;
	}
}
LL qpow(LL a,LL b,LL p)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1; 
	}
	return ans;
}
LL rec(LL p)
{
	if(p==1) return 0;
//	cout<<"p="<<p<<endl;
	return qpow(2,rec(phi[p])+phi[p],p);
}
int main()
{
	cin>>t;
	pre();
	while(t--)
	{
		LL p;
		cin>>p;
		cout<<rec(p)<<endl;
	}
	
	return 0;
}

