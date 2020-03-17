#include<iostream>
#define IL inline
#define re register
using namespace std;
int n,ans,jf;
int queen[20];
IL void dfs(int depth,int ld,int rd,int row)
{
	int now=ld|rd|row;
	if(depth>=n){
		if(++jf<=3){ 
			for(int i=0;i<n;i++)cout<<queen[i]+1<<" ";
			cout<<endl;
		} 
		ans++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if((now>>i)&1) continue;
		queen[depth]=i;
		ld^=1<<i;rd^=1<<i;row^=1<<i;
		dfs(depth+1,ld<<1,rd>>1,row);
		ld^=1<<i;rd^=1<<i;row^=1<<i;
		queen[depth]=0;
	}
}
int main()
{
	cin>>n;
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}


