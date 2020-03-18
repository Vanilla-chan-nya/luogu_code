#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m; cin>>n>>m;
	char a;
	bool pm[n][m];
	int jl[n][m];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		a=getchar();
		pm[i][j]=a=='0'?0:1;
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cout<<pm[i][j]<<" ";
}
