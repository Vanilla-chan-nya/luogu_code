#include <bits/stdc++.h>
using namespace std;
short n;
short lie[15];
bool xy[15][4]={0}; //只有14行，其中[1~14][0~3]存储:0、行有了吗1、列有了吗2、\对角线有了吗3、/对角线有了吗 
int jiefa=0;
void queen(int i)//i是行数 
{
	
		if(i==n+1) //output
		{	if(jiefa<=3)
			{	for(int y=1;y<=n;y++)
					cout<<lie[y]<<" ";
			cout<<endl;
			}
		++jiefa;
	return;}
	
	
	for(int j=1;j<=n;j++)//j是列数 
	//判别[i][j] 
	if(!()){ 
    	lie[i]=j;
    	
   		//进入一层回溯 
    	queen(i+1);
    	//退出一层回溯 
    	lie[i]=0;
    	
		}
}
int main()
{
	cin>>n;
	queen(1);
	cout<<jiefa;
	return 0;
} 
