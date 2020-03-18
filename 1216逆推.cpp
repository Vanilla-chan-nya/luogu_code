//逆推 100
#include<iostream>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main(){
	int r;
	cin>>r;
	int triangle[r][r];
	for(int i=0;i<r;i++)//行 
	for(int j=0;j<i+1;j++)//列 
	cin>>triangle[i][j];
	
	for(int i=r-2;i>=0;i--)
	for(int j=r-2;j>=0;j--)
		triangle[i][j]+=max(triangle[i+1][j],triangle[i+1][j+1]); 
	cout<<triangle[0][0];
	return 0;
}
