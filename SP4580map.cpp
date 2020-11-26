#include<iostream>
#include<map>
#include<tr1/unordered_map>
#include<cstdio>
#include<cstring>
using namespace std;
tr1::unordered_map<int,int>table;
int s[101],ans,n;
#define R register
inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread (buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
#define nc() getchar()
inline int rd() {
    char ch = nc();int sum=0;
    int tf = 0;

    while((ch < '0' || ch > '9') && (ch != '-')) ch = nc();
    tf = ((ch == '-') && (ch = nc()));
    while(ch >= '0' && ch <= '9') sum = sum * 10+ (ch ^ 48), ch = nc();
    (tf) && (sum =- sum);
    return sum;
}
int main()
{
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=rd();
	for(R int i=0;i<n;i++)
		s[i]=rd();
	for(R int a=0;a<n;a++)
	for(R int b=0;b<n;b++)
	for(R int c=0;c<n;c++)
		table[s[a]*s[b]+s[c]]++;
	for(R int d=0;d<n;d++)
	{
		if(s[d])
		for(R int e=0;e<n;e++)
		for(R int f=0;f<n;f++)
		if(table[s[d]*s[e]+s[d]*s[f]]>0) ans+=table[s[d]*s[e]+s[d]*s[f]];
	}
	
	cout<<ans;
	return 0;
}
//(ab+c)/d-e=f
//ab+c=d(e+f)
