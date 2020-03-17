#include<iostream>//不想OI一场空，千万别用万能头
#include<map>
#include<cstdio>//能不用cin就不用
#include<cstring>
#define IL inline
using namespace std;
map<int,int>table;
int s[100],ans,n;
int main()
{
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",s+i);
	for(int a=0;a<n;a++)
	for(int b=0;b<n;b++)
	for(int c=0;c<n;c++)
		table[s[a]*s[b]+s[c]]++;
	for(int d=0;d<n;d++)
	for(int e=0;e<n;e++)
	for(int f=0;f<n;f++)
		if(table[s[d]*s[e]+s[d]*s[f]]) ans+=table[s[d]*s[e]+s[d]*s[f]];
	cout<<ans;
	return 0;
}
//(ab+c)/d-e=f
//ab+c=d(e+f)
