#include<iostream>
using namespace std;
int n,m,a[10001];
int getf(int i){//��ѯi������ 
	if(a[i]==i) return i;//Ҫ�����Ⱦ������Լ���ֱ�ӷ��� 
	return a[i]=getf(a[i]);//�����ǣ������ҡ�ͬʱ��a[i]������Ҳ��ɼ����ҵ����� 
}//·��ѹ�� 
void merge(int x,int y){//�ϲ� 
	//�ֱ��ҳ����ǵ����� 
	if(getf(x)!=getf(y)) //��һ�п��п��ޣ��и��ã��������ںϲ�ǰ���ж������ǲ�����ͬһ���������� 
		a[getf(x)]=getf(y);
	return;
}
bool inquire(int x,int y){//��ѯ�Ƿ���һ�������� 
	return getf(x)==getf(y);
}
int main()
{
	cin>>n>>m;
	//��ʼ�� 
	for(int i=1;i<=n;i++)
		a[i]=i;
	int z,x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z==1)
			merge(x,y);
		else
			cout<<(inquire(x,y)?"Y":"N")<<endl;
	}
	return 0;
}
