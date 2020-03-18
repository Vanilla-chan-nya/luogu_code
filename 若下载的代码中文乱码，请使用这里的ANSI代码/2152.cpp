#include<iostream>
#include<cmath>
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
bool judge()
{
	for(int i=0;i<e;i++)
		if(a[i]) return false;
	return true;
}
void swap_array()
{
	for(int i=0;i<e;i++) swap(a[i],b[i]);
}
void gcd()
{
	if(!cmp1()) swap_array();
	update();
	for(int i=0;i<e;i++)
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
	for(int i=0;i<str1.size();i++) a[str1.size()-i-1]=str1[i]-'0';
	for(int i=0;i<str2.size();i++) b[str2.size()-i-1]=str2[i]-'0';
	gcd();
	bool s=0;
	for(int i=e-1;i>=0;i--)
	{
		if(b[i]) s=1;
		if(s==1) cout<<b[i];
	}
	return 0;
}
