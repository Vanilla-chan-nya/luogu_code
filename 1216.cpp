//���p1216 
#include<iostream>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main(){
int r;
cin>>r;
int triangle[r][r];
for(int i=0;i<r;i++)//�� 
for(int j=0;j<i+1;j++)//�� 
cin>>triangle[i][j];

for(int i=r-2;i>=0;i--)
for(int j=r-2;j>=0;j--)
triangle[i][j]+=max(triangle[i+1][j],triangle[i+1][j+1]); 
cout<<triangle[0][0];
return 0;
}
/*�۲���������ֽ�������
дһ�����������Ҵ���ߵ㵽�ײ����⴦������·����ʹ·���������ֵĺ����ÿһ�������ߵ����·��ĵ�Ҳ���Ե������·��ĵ㡣
7 
3 8 
8 1 0 
2 7 4 4 
4 5 2 6 5 
�������������,��7�� 3�� 8�� 7�� 5��·������������ 
���������ʽ
�����ʽ��
��һ���а��� R(1<= R<=1000) ,��ʾ�е���Ŀ��
����ÿ��Ϊ������ֽ������ض��а�����������
���еı���Ӧ�������ǷǸ����Ҳ�����100��
�����ʽ��
������һ��,�����Ǹ����ܵõ������ĺ�
�����������
��������#1�� 
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 
�������#1�� 30
˵��
��Ŀ��������NOCOW��
USACO Training Section 1.5
IOI1994 Day1T1
*/