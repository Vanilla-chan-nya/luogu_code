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
#define ULL unsigned long long
#define re register
#define debug printf("Now is %d\n",__LINE__);
using namespace std;
string str;
LL n;
bool fu;

void read()
{
	char ch=getchar();
//	cout<<"第一个字符是"<<ch; 
	while(ch=='\n') ch=getchar();
	while(ch!='\n') str+=ch,ch=getchar();
}

bool isnum(char ch)
{
	return ch<='9'&&ch>='0';
}

bool judge()
{
	for(int i=0;i<str.size();i++)
	{
		if(isnum(str[i])) return 1;
	}
	exit(0);
}

void calc()
{
	bool fu=1;
	for(unsigned int i=0;i<str.size();i++)
	{
		if(str[i]=='-') fu=-1;
		if(isnum[str[i]]) n=n*10+str[i]-'0';
		if(fu==1&&n>40000000) 
		{
			n*=fu;
			return;
		}
	}
	n*=fu;
}

bool prime()
{
	if(n<2) return 0;
	if(n==2||n==3) return 1;
	LL sq=sqrt(n);
	for(int i=2;i<=sq;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

void split()
{
	cout<<n<<"=";
	bool first=1;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			if(!first) cout<<"*";
			else first=0;
			cout<<i;
			n/=i;
			if(n%i==0) cout<<'^';
			int cnt=1;
			while(n%i==1)
			{
				cnt++;
				n/=i;
			}
			cout<<cnt;
		}
	}
}

int main()
{
	cout<<"Enter the number=";
	do{
		
		read();
		cout<<"\n";
		if(!judge()) return 0;
		cout<<"Prime? ";
		calc();
		if(n>40000000) 
		{
			cout<<"No!\n";
			cout<<"The number is too large!"<<endl;
		}
		else
		{
			if(n<=0)
			{
				cout<<"No!\n";
			}
			else 
			if(prime()) cout<<"Yes!\n";
			else cout<<"No!\n",split();
		}
		str.clear();
		fu=0;
		cout<<"Enter the number=";
		read();
	}while(judge());
	
	return 0;
}

