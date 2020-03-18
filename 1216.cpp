//洛谷p1216 
#include<iostream>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main(){
int r;
cin>>r;
int triangle[r][r];
for(int i=0;i<r;i++)//行 
for(int j=0;j<i+1;j++)//列 
cin>>triangle[i][j];

for(int i=r-2;i>=0;i--)
for(int j=r-2;j>=0;j--)
triangle[i][j]+=max(triangle[i+1][j],triangle[i+1][j+1]); 
cout<<triangle[0][0];
return 0;
}
/*观察下面的数字金字塔。
写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。
7 
3 8 
8 1 0 
2 7 4 4 
4 5 2 6 5 
在上面的样例中,从7到 3到 8到 7到 5的路径产生了最大和 
输入输出格式
输入格式：
第一个行包含 R(1<= R<=1000) ,表示行的数目。
后面每行为这个数字金字塔特定行包含的整数。
所有的被供应的整数是非负的且不大于100。
输出格式：
单独的一行,包含那个可能得到的最大的和
输入输出样例
输入样例#1： 
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 
输出样例#1： 30
说明
题目翻译来自NOCOW。
USACO Training Section 1.5
IOI1994 Day1T1
*/
