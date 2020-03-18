#include<iostream>//不想OI一场空，千万别用万能头
#include<map>
#include<cstdio>//能不用cin就不用
#include<cmath>
#define IL inline
using namespace std;
int n,m;
map<int,bool> pr;
int main()
{
	cin>>n>>m;
	pr[2]=1;
	bool flag=1;
	for(int i=3;i<=m;i++)
	{
		flag=1;
		for(int j=2;j<=sqrt(i);j++)
		if(i%j==0){
			flag=0;
			break;
		}
		if(flag) pr[i]=1;
	}
	
	int l,r,ans;
	while(n--)
	{
		ans=0;
		cin>>l>>r;
		if(l<0) l=0;
		if(r<0||r>m){
			cout<<"Crossing the line\n";
			continue;
		};
		for(int i=l;i<=r;i++)
		if(pr[i]) ans++;
		cout<<ans;
	}
	return 0;
}

