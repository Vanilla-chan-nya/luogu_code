//���P1003 �̵�̺ noip2011�����day1T1 
#include<iostream>
using namespace std;
int dm[10000][10000],ta,tb,tg,tk;
int main(){
	int n,x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ta>>tb>>tg>>tk;
		for(int j=ta;j<ta+tg;j++)
		for(int m=tb;m<tb+tk;m++)
				dm[j][m]=i;
	}
	cin>>x>>y;
	if(dm[x][y]) cout<<dm[x][y];
	else cout<<"-1";
	return 0;
}
/*
��Ŀ����
Ϊ��׼��һ�����صİ佱������֯���ڻ᳡��һƬ�������򣨿ɿ�����ƽ��ֱ������ϵ�ĵ�һ���ޣ�����һЩ���ε�̺��һ���� n �ŵ�̺����Ŵ� 1 ��n�����ڽ���Щ��̺���ձ�Ŵ�С�����˳��ƽ�����������Ⱥ����裬���̵ĵ�̺������ǰ���Ѿ��̺õĵ�̺֮�ϡ�

��̺������ɺ���֯����֪�����ǵ���ĳ���������������ŵ�̺�ı�š�ע�⣺�ھ��ε�̺�߽���ĸ������ϵĵ�Ҳ�㱻��̺���ǡ�

���������ʽ

�����ʽ��
���빲n+2��

��һ�У�һ������n����ʾ�ܹ���n�ŵ�̺

��������n���У��� i+1 ��ʾ���i�ĵ�̺����Ϣ�������ĸ�������a,b,g,k.ÿ��������֮����һ���ո�������ֱ��ʾ�����̺�����½ǵ�����(a,b)�Լ���̺��x���y�᷽��ĳ���

��n+2�а�������������x��y����ʾ����ĵ���ĵ������(x,y)
�����ʽ��
�����1�У�һ����������ʾ����ĵ�̺�ı�ţ����˴�û�б���̺���������-1

�����������

��������#1��
1 0 2 3
0 2 3 3
2 1 3 3
2 2
�������#1��
3

��������#2�� 
3
1 0 2 3
0 2 3 3
2 1 3 3
4 5
�������#2��
-1
*/ 