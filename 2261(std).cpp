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
using namespace std;

LL n,k,ans; 

int main()
{
	cin>>n>>k;
	if(n>k) ans+=(n-k)*k,n=k-1;
	for(LL i=2;i<=n;i++){
		if(k%i>k%(i-1)&&k/i*i+1<n){
			ans+=k%i*(k/i*i-i+1)-(k/i*i-i)*(k/i*i-i+1)*(k/i)/2;
			cout<<"ÌøÔ¾"<<i<<"->"<<k/i*i+1<<endl; 
			i=k/i*i;
		}
		else ans+=k%i;
	}
	cout<<ans;
	return 0;
}
/*
sum=(f+e)*n/2
e=f-(n-1)*d
sum=(f+f-(n-1)*d)*n/2
sum=fn-(n-1)nd/2
sum=f

f=k%i
n=k/i*i-i+1
*/

