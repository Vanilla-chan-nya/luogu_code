#include <bits/stdc++.h>
using namespace std;
short n;
short lie[15];
bool xy[15][4]={0}; //ֻ��14�У�����[1~14][0~3]�洢:0����������1����������2��\�Խ���������3��/�Խ��������� 
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
	//�б�[i][j] 
	if(!()){ 
    	lie[i]=j;
    	
   		//����һ����� 
    	queen(i+1);
    	//�˳�һ����� 
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
