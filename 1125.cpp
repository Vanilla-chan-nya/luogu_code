#include<iostream>//不想OI一场空，千万别用万能头
#include<algorithm>//快排sort()
#include<cstdio>//能不用cin就不用
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#define IL inline
using namespace std;
int maxn,minn=0x3f3f3f3f;
string word;
map<char,int>table;
bool prime(int num)
{
	if(num<=1) return 0;
	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0) return 0;
	return 1;
}
int main()
{
	cin>>word;
	for(unsigned int i=0;i<word.size();i++)
		table[word[i]]++;
	for(char ch='a';ch<='z';ch++)
	{
		if(table[ch]==0) continue;
		maxn=max(table[ch],maxn);
		minn=min(table[ch],minn);
	}
	if(prime(maxn-minn))
		cout<<"Lucky Word\n"<<maxn-minn;
	else
	cout<<"No Answer\n0"; 
	return 0;
}


