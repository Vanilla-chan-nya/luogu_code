#include<bits/stdc++.h>
using namespace std;
int t,m,v[101],w[101];
//��dp[i][j]��ʾ��jΪʣ��������ѡ���Եķ���ǰi����Ʒ������ֵ��
int dp[101][1001]; 
int main()
{
	cin>>t>>m;
	for(int i=0;i<m;i++)
		cin>>v[i]>>w[i];
	for(int i=1;i<m;i++)
	for(int j=t;j>=0;j--)
	if() dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
	cout<<dp[m][t];
	return 0;
	
	
	
	
	
	
	
}