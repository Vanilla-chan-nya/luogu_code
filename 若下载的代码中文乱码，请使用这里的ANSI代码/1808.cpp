#include<bits/stdc++.h>
using namespace std;

bool cmp(unsigned long long ta,unsigned long long tb){
	return ta<tb;
}

bool cmpstr(string ta,string tb){
	return ta<tb;
}
const unsigned long long mo=10e7-7;

string word[10001];

long long val[mo+1];

unsigned long long n;


int main()
{
	freopen("1808_2.in","r",stdin);
	cin>>n;
	long long ans=0,t;
	for(unsigned long long i=0;i<n;i++){
		t=0;
		cin>>word[i];
		sort(word[i].begin(),word[i].end());
//		for(unsigned long long j=0;j<word[i].size();j++){
//			val[i]+=pow(4,word[i][j]-'A');
//		}
		for(int j=0;j<word[i].size();j++){
			t+=(long long)pow(27,j)*(word[i][j]-'A'+1);
//			while(t>=mo) t-=mo;
			t%=mo;
		}
		val[t]++;
	}
//	sort(val,val+n,cmp);
//	sort(&word[0],&word[n-1],cmpstr);
	for(unsigned long long i=0;i<mo;i++)
	{
//		if(val[i]!=val[i+1])
//			ans++;
//		if(word[i].size()!=word[i+1].size()&&word[i]!=word[i+1])
//			ans++;
		if(val[i]) ans++;
	}
	cout<<ans;
	
	return 0;
}
