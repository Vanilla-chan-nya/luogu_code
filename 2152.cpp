#include<iostream>
#include<cmath>
#define IL inline
using namespace std;
string str1,str2;
const int maxn=10001;
const int B=8;
int e=maxn;
int a[maxn],b[maxn],c[maxn];
void update()
{
	for(int i=e+1;i>=0;i--) if(a[i]) {e=i+1;return;}
}
bool cmp1()
{
	for(int i=e;i>=0;i--)
	{
		if(a[i]>b[i]) return true;
		if(a[i]<b[i]) return false;
	}
	return true;
}
int i;
IL bool judge()
{
	for(i=0;i<e;i++)
		if(a[i]) return false;
	return true;
}
IL void swap_array()
{
	for(i=0;i<e;i++) swap(a[i],b[i]);
}
void gcd()
{
	if((a[0]&1)==0)
	{
		for(i=e-1;i>0;i--)
		{
			if(a[i]&1) a[i-1]+=10;
			a[i]>>=1;
		}
		a[0]>>=1;
		gcd();
		return;
	}
	if(!cmp1()) swap_array();
	update();
	for(i=0;i<e;i++)
	{
		a[i]-=b[i];
		if(a[i]<0)
		{
			a[i+1]-=1;
			a[i]+=10;
		}
	}
	if(!judge()) gcd();
	return;
}
int main()
{
	cin>>str1>>str2;
	for(i=0;i<str1.size();i++) a[str1.size()-i-1]=str1[i]-'0';
	for(i=0;i<str2.size();i++) b[str2.size()-i-1]=str2[i]-'0';
	gcd();
	bool s=0;
	for(i=e-1;i>=0;i--)
	{
		if(b[i]) s=1;
		if(s) putchar(b[i]+'0');
	}
	return 0;
}
