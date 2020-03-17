#include<iostream>
using namespace std;
int n,m,p,a[10001];
int getf(int i){
	if(a[i]==i) return i;
	return a[i]=getf(a[i]);
}
void merge(int x,int y){ 
	a[getf(x)]=getf(y);
	return;
}
bool inquire(int x,int y){ 
	return getf(x)==getf(y);
}
int main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		a[i]=i;
	int x,y,pi,pj;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		merge(x,y);
	}
	for(int i=1;i<=p;i++){
		cin>>pi>>pj; 
		cout<<(inquire(pi,pj)?"Yes":"No")<<endl;
	}
	return 0;
}
