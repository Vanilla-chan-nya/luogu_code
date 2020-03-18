#include<iostream>
#include<cmath>
using namespace std;
int k[102];
int main(){
	int n,flag=1;
	cin>>n;
	for(int i=n;i>=0;--i){
		cin>>k[i];
		if(k[i]==0) continue;
		if(i==0) {
			if(k[i]>0) cout<<"+"<<k[i];
			if(k[i]<0) cout<<k[i];
			continue;
		} 
		if(flag){//最高次 
			flag=0;
			if(k[i]==1||k[i]==-1) {
				if(k[i]==1) cout<<"";
				if(k[i]==-1) cout<<"-";
			}
			else{
				cout<<k[i];
			}			
		}
		else{//不是最高次 
			if(k[i]==1||k[i]==-1) {
				if(k[i]==1) cout<<"+";
				if(k[i]==-1) cout<<"-";
			}
			else{
				if(k[i]>0) cout<<"+"<<abs(k[i]);
				if(k[i]<0) cout<<"-"<<abs(k[i]);
			}		
		}
		
		if(i==1) cout<<"x";
		if(i>1) cout<<"x^"<<i;
	}
	
	
	
	
	return 0;
}
