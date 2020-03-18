//luogu1036
#include<bits/stdc++.h>
using namespace std;
int n,num[51],nnn[100001],ans=0,ge,k; 
bool cmp(int a,int b){return a>b;} 
bool zs(int a)
{
	if(a==0||a==1) return false;
	for(int j=2;j<=sqrt(a);j++)
	{
		if(a%j==0)
			return false;
	}
	return true;
}
void func(int depth,int sam,bool change,int tk)//now:现在正在选择的数字的下标 
{
	if(depth>n) return;
	if(tk==k&&change&&zs(sam)) ans++;
	if(depth)
//	选下一个数 
	func(depth+1,sam+num[depth],true,tk+1);
//	不选下一个数 
	func(depth+1,sam,false,tk);
	return;
}
int main()
{
	cin>>n>>k;
	int t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		nnn[t]++;
	}
	for(int i=0;i<n;i++)
	{
		if(nnn[i]>0)
		{
			num[ge++]=i;
		}
		if(nnn[i]>1)
		{
			for(int j=2;j<=nnn[i];j++)
				if(zs(i*j)) ans++;
		}
	}
	func(0,0,false,0); 
	cout<<ans; 
	return 0;
}
