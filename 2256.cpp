#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,int>name;
int n,m,k,f[5001],size[5001],ans,yet;
int getf(int a)
{
	if(f[a]==a) return a;
	return f[a]=getf(f[a]);//Â·¾¶Ñ¹Ëõ 
}
void merge(int a,int b)
{
	int i=getf(a);
	int j=getf(b);
	if(size[i]>size[j]) swap(i,j);
	f[j]=i;
	size[i]+=size[j];
}
int main()
{
	cin>>n>>m;
	string str,str1,str2;
	for(int i=1;i<=n;i++)
	{
		size[i]=1;
		f[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		name[str]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>str1>>str2;
		merge(name[str1],name[str2]);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>str1>>str2;
		if(getf(name[str1])==getf(name[str2])) cout<<"Yes.\n";
		else cout<<"No.\n";
	}
	return 0;
}
