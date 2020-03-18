//make table program
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
const int inf = 0x3f3f3f3f;
int memory[21][21][21]={


};
long long w(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	if(a>20||b>20||c>20){
		return w(20,20,20);
	}
	if(memory[a][b][c]!=-1) return memory[a][b][c];
	if(a<b&&b<c){
		return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
	freopen("1464table(2).txt","w",stdout);
	memset(memory,-1,sizeof(memory));
	for(int i=0;i<=20;i++)
	for(int j=0;j<=20;j++)
	for(int k=0;k<=20;k++)
	{
//		cin>>a>>b>>c;
//		cout<<"a="<<i<<" b="<<j<<" c="<<k<<endl;
//		printf("w(%d,%d,%d)=%lld\n",i,j,k,w(i,j,k));
		int ans=w(i,j,k);
		printf("%d,",ans); 
		if(k==20) {
			printf("\n");
			if(j==20) {
				printf("\n");
			}
			
		}
		memory[i][j][k]=ans;
	} 
	return 0;
}
