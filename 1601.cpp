#include<iostream>//不想OI一场空，千万别用万能头
#include<algorithm>//快排sort()
#include<cstdio>//能不用cin就不用
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define IL inline
using namespace std;
bool flag;
int a[501],b[501];
string stra,strb;
int main()
{
	cin>>stra;
	cin>>strb;
	for(unsigned int i=0;i<stra.size();i++)
		a[i]=stra[stra.size()-i-1]-'0';
	for(unsigned int i=0;i<strb.size();i++)
		b[i]=strb[strb.size()-i-1]-'0';
	for(unsigned int i=0;i<max(stra.size(),strb.size());i++)
	{
		a[i]+=b[i];
		if(a[i]>9) a[i+1]++,a[i]-=10;
	}
	for(int i=max(stra.size(),strb.size());i>=0;i--)
	{
		if(a[i]==0&&flag==0&&i>0) continue;
		flag=1;
		if(flag)
			cout<<a[i];
	}
	return 0;
}

