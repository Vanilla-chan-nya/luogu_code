#include<iostream>
#include<cstdio>
using namespace std;
int rec()
{
	int a=0;
	char t;
	while(scanf("%c",&t)!=EOF)
	{
		if(t=='a') a++;
		if(t=='|') return max(a,rec());
		if(t=='(') a+=rec();//不能写成 return a+rec() !
		if(t==')') return a;
	}
	return a;
}
int main()
{
	cout<<rec();
	return 0;
}
