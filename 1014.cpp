#include<bits/stdc++.h> 
using namespace std;
int main(){
int n;
cin>>n;
int hang=1,lie,tn1=n,tn2=n;
while(tn1>4*hang-3){ 
	tn1-=4*hang-3; 
	hang++;
}
lie=tn1;
if(lie<=(4*hang-3)/2+1) cout<<lie;
else cout<<4*hang-3-lie+1;
hang=1; 
while(tn2>4*hang-1){ 
	tn2-=4*hang-1; 
	hang++;
}
cout<<"/";
lie=tn2;
if(lie<=(4*hang-1)/2+1) cout<<lie;
else cout<<4*hang-1-lie+1;




return 0;
}

