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
#define re register
using namespace std;
const int L=10,B=3,mo=pow(10,B);
int n;
long long a[L],b[L];
long long sum[2*L];
int main()
{
	cin>>n;
    string sa,sb;
    cin>>sa>>sb;
    int wei=0;
    for(unsigned int i=sa.size();i>=0;i-=B)
    {
    	int res=0;
    	for(unsigned int j=0;j<B&&i-j>=0;j++)
    		res=(res<<1)+(res<<3)+sa[i-j]-'0';
    	a[wei++]=res;
	}
    for(unsigned int i=0;i<sb.size();i+=B)
    {
    	int res=0;
    	for(unsigned int j=0;j<B&&j+i<sb.size();j++)
    		res=(res<<1)+(res<<3)+sb[i+j]-'0';
    	b[i/B]=res;
	}
	int e=1;
	while(a[e]&&e<L*B) e++;
	for(int i=0;i<e;i++)
	for(int j=0;j<e;j++)
	{
		sum[i+j]+=a[i]*b[j];
		sum[i+j+1]+=sum[i+j]/mo;
		sum[i+j]%=mo;
	}
	bool flag=0,first=1;
	for(int i=2*(e+1);i>=0;i--)
	{
		if(sum[i]) flag=1;
		if(flag)
		{
			if(first) cout<<sum[i],first=0;
			else printf("%03lld",sum[i]);
		}
	}
    return 0;
}


