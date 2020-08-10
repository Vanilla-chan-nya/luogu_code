#include<iostream>
#include<cmath>
using namespace std;
int f[30001];
int getf(int a)
{
	if(f[a]==a) return a;
	return /*f[a]=*/getf(f[a]);
}
int dis(int b,int now)
{
	if(f[b]==b) return now;
	return dis(f[b],now+1);
}
void merge(int x,int y)
{
	f[getf(x)]=getf(y);	
}
bool inquire(int x,int y)
{
	return getf(x)==getf(y);
}
int main(){
	for(int i=1;i<=30001;i++){
		f[i]=i;
		
		
	}
		
	int t; cin>> t;
	int ta,tb; char tc;
	for(int i=1;i<=t;i++)
	{
		cin>>tc>>ta>>tb;
		if(tc=='M')
			merge(ta,tb);
		else
		{
			cout<<(inquire(ta,tb)?abs(dis(ta,0)-dis(tb,0)):-1)<<endl;
		}
					
	}
	return 0;
}
/*
�����������ط�����ѯ��ָ�
��ĳ���Ҫ���һ�У�
������һ��������
��ʾ��ͬһ���ϣ�
��i��ս�����j��ս��֮�䲼�õ�ս����Ŀ��
�����i��ս�����j��ս����ǰ����ͬһ���ϣ�
�����-1��
*/
