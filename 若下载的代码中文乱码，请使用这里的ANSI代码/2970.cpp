#include<bits/stdc++.h>
using namespace std;

struct cow{
	int s;
	int e;
} land[50001];

bool cmpe(cow tx,cow ty){
	return tx.e<ty.e;
}

int n;
int main()
{
	cin>>n;
	int maxland=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>land[i].s>>land[i].e;
		maxland=max(maxland,land[i].e);
	}
	sort(land,land+n,cmpe);
	int nowtime=0;
	for(int i=0;i<n;i++){
		if(land[i].s>=nowtime){
			nowtime=land[i].e;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
