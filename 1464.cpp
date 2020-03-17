#include<iostream>
#include<cstring>
using namespace std;
int a,b,c,ra,rb,rc;
int memory[21][21][21]={};
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
		return memory[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	return memory[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
	memset(memory,-1,sizeof(memory));
	cin>>a>>b>>c;
	while(a!=-1||b!=-1||c!=-1){
		int ans=w(a,b,c);
		printf("w(%d, %d, %d) = %d\n",a,b,c,ans);
//		memory[a][b][c]=ans;
		cin>>a>>b>>c;
	} 
	return 0;
}
