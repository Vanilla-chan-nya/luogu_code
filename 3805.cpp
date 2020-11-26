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
using namespace std;

IL int read()
{
	int ans=0;
	bool fu=0;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') fu=1,ch=getchar();
	while(ch<='9'&&ch>='0') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	if(fu) ans*=-1;
	return ans;
}
const int maxn=3e7+10;
int p[maxn];
char str[maxn],t[maxn]="$#";
int len,size;
int Manacher()
{
   size=2;
   len=strlen(str);
   for(int i=0;i<len;i++)
   {
		t[size++]=str[i];
		t[size++]='#';
   }
   int mx=0,id=0,resLen=0;
   for(int i=1;i<size;i++)
   {
       p[i]=mx>i?min(p[2*id-i],mx-i):1;
       while(t[i+p[i]]==t[i-p[i]]) p[i]++;
       if(i+p[i]>mx)
       {
           mx=i+p[i];
           id=i;
       }
       if(p[i]>resLen)
       {
           resLen=p[i];
       }
   }
	return resLen-1;
}
int main()
{
	cin>>str;
 	cout<<Manacher() << endl;
	return 0;
}


