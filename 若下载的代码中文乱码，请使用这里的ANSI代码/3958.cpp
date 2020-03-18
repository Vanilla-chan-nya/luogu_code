#include<iostream>
using namespace std;

int t;
int f[1001];
struct point{
	long long x,y,z;
};

long long getf(long long a)
{
	if(f[a]==a) return a;
	return getf(f[a]);
}

void merge(long long a,long long b)
{
	long long i=getf(a),j=getf(b);
	if(i!=j) f[i]=j;
}

bool inquire(long long x,long long y){
	return getf(x)==getf(y);
}

int main()
{
	cin>>t;
	while(t--)
	{
		long long n,h,r;
		cin>>n>>h>>r;
		point cent[n+1];
		long long up[n+1],down[n+1];
		long long u=0,d=0;
		for(long long i=1;i<=n;i++) f[i]=i;
		for(long long i=1;i<=n;i++)
		{
			cin>>cent[i].x>>cent[i].y>>cent[i].z;	
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<i;j++)
			{
				if((cent[i].x-cent[j].x)*(cent[i].x-cent[j].x)+(cent[i].y-cent[j].y)*(cent[i].y-cent[j].y)+(cent[i].z-cent[j].z)*(cent[i].z-cent[j].z)<=4*r*r)
				{
					merge(i,j);
				}
			}
		}
		bool succ=0;
		for(long long i=1;i<=n;i++)
		{
			if(cent[i].z<=r){
				down[d++]=getf(i);
			}
		}
		for(long long j=1;j<=n&&!succ;j++)
			if(cent[j].z+r>=h)
				for(long long i=0;i<d;i++) if(getf(j)==getf(down[i])){succ=1;break;}
		if(succ) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
