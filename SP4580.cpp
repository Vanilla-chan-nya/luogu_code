#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#define IL inline
using namespace std;
const int p=9999991;
int hsh(const int & x)
{
	return (x+900000000)%p;
}
int h[9999991];
int s[100],ans,n;
int main()//WA...... 
{
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",s+i);
	for(int a=0;a<n;a++)
	for(int b=0;b<n;b++)
	for(int c=0;c<n;c++)
		h[hsh(s[a]*s[b]+s[c])]++;
	for(int d=0;d<n;d++)
	for(int e=0;e<n;e++)
	for(int f=0;f<n;f++)
		if(h[hsh(s[d]*s[e]+s[d]*s[f])]) ans+=h[hsh(s[d]*s[e]+s[d]*s[f])];
	cout<<ans;
	return 0;
}
//(ab+c)/d-e=f
//ab+c=d(e+f)
