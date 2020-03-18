//顺推 66
#include<iostream>
#include<cstring>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main(){
	int r;
	cin>>r;
	int triangle[r][r];
	memset(triangle,0,sizeof(triangle));
	for(int i=0;i<r;i++)//行 
	for(int j=0;j<i+1;j++)//列 
	cin>>triangle[i][j];
	int ans=0; 
	for(int i=1;i<r;i++)
	for(int j=1;j<r;j++)
	{
//		triangle[i+1][j]=max(triangle[i+1][j],triangle[i][j]+a[i+1][j]);
//		triangle[i+1][j+1]=max(triangle[i+1][j+1],triangle[i][j]+a[i+1][j+1]);
		
		
		triangle[i][j]+=max(triangle[i-1][j],triangle[i-1][j-1]);
		
	}
	for(int j=0;j<r;j++)
	{
		ans=max(ans,triangle[r-1][j]);
	}
	cout<<ans;
	return 0;
}
