#include <bits/stdc++.h>
using namespace std;
short n;
short lie[15];
short xy[14][14]={0};//������״̬ 
int jiefa=0;

void queen(int i)//i������ 
{
	
		if(i==n+1) //output
		{	if(jiefa<=3)
			{	for(int y=1;y<=n;y++)
					cout<<lie[y]<<" ";
			cout<<endl;
			}
		++jiefa;
	return;}
	
	
	for(int j=1;j<=n;j++)//j������ 
	if(  (!xy[0][j])&& (!xy[1][i+j]) &&(!xy[2][i-j+n])  ){ 
      lie[i]=j;
      xy[0][j] = 1;
      xy[1][i+j] = 1;
      xy[2][i-j+n] = 1;
      //����һ����� 
      queen(i+1);
      //�˳�һ����� 
      lie[i]=0;
      xy[0][j] = 0;
      xy[1][i+j] = 0;
      xy[2][i-j+n] = 0;
    }
    /*if(  (!xy[0][j])&& (!xy[1][i+j]) &&(!xy[2][i-j+n])  ){ // �жϹؼ�
      lie[i]=j;
      xy[0][j] = 1;
      xy[1][i+j] = 1;
      xy[2][i-j+n] = 1;
      queen(i+1);
      lie[i]=0;
      xy[0][j] = 0;
      xy[1][i+j] = 0;
      xy[2][i-j+n] = 0;
    }*/ 
	
}
int main()
{
	cin>>n;
	queen(1);
	cout<<jiefa;
	return 0;
} 
