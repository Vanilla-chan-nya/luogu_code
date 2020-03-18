#include<iostream>
using namespace std;
int n,m,a[10001];
int getf(int i){//查询i的祖先 
	if(a[i]==i) return i;//要是祖先就是他自己，直接返回 
	return a[i]=getf(a[i]);//若不是，就再找。同时把a[i]的祖先也变成即将找的祖先 
}//路径压缩 
void merge(int x,int y){//合并 
	//分别找出他们的祖先 
	if(getf(x)!=getf(y)) //这一行可有可无（有更好）。可以在合并前先判断他们是不是在同一个集合里面 
		a[getf(x)]=getf(y);
	return;
}
bool inquire(int x,int y){//查询是否在一个集合中 
	return getf(x)==getf(y);
}
int main()
{
	cin>>n>>m;
	//初始化 
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
