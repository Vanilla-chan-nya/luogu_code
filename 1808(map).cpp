#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstring>
#include<cstdio>
#include<map> 
using namespace std;
map<string,bool>word;
int n,ans;
string t;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>t;
		sort(t.begin(),t.end());
		if(!word[t])
		{
			ans++;
			word[t]=1;
		}
	}
	cout<<ans;
	return 0;
}

