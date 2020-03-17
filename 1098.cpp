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
using namespace std;

string a;

int p1,p2,p3;

int main()
{
	cin>>p1>>p2>>p3>>a;
	for(unsigned int i=0;i<a.size();i++){
		if(a[i]!='-'||a[i-1]>=a[i+1]) cout<<a[i];
		else{
			if(a[i-1]+1==a[i+1]){
				continue;
			}
			char s,e;
			s=a[i-1],e=a[i+1];
			if(p1==2) s+='A'-'a',e+='A'-'a'; 
			{
				
				if(p3==1){
					for(char i=s+1;i<e;i++)
					for(int j=0;j<p2;j++)
					if(p1==3) cout<<"*";
					else cout<<i; 
				}
				else{
					for(char i=e-1;i>s;i--)
					for(int j=0;j<p2;j++)
					if(p1==3) cout<<"*";
					else cout<<i; 
				}
			}
		}
	} 
	
	return 0;
}

