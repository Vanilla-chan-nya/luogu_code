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
如果是莱因哈特发布的询问指令，
你的程序要输出一行，
仅包含一个整数，
表示在同一列上，
第i号战舰与第j号战舰之间布置的战舰数目。
如果第i号战舰与第j号战舰当前不在同一列上，
则输出-1。
*/
