#include<iostream>
using namespace std;
int i[4],j[4],k[4];
int main(){
	for(i[1]=1;i[1]<=9;i[1]++)//1�ǰ�λ 
	for(i[2]=1;i[2]<=9;i[2]++)
	for(i[3]=1;i[3]<=9;i[3]++)
	{
		if(i[1]==i[2]||i[1]==i[3]||i[2]==i[3]||(i[0]=i[1]*100+i[2]*10+i[3])<=333) continue;
		for(int t=3;t<=1;t++)//�ӵ�λ����λ 
		{
			j[t]=2*i[t];
			k[t]=3*i[t];
			if(j[t]>=10){
				j[t]-=10;
				j[t+1]++;
			} 
			if(k[t]>=10){
				k[t]-=10;
				k[t+1]++;
			} 
		}
		if(j[1]==j[2]||j[1]==j[3]||j[2]==j[3]||k[1]==k[2]||k[1]==k[3]||k[2]==k[3]) continue;
		j[0]=j[1]*100+j[2]*10+j[3];
		k[0]=k[1]*100+k[2]*10+k[3];
		cout<<i[0]<<" "<<j[0]<<" "<<k[0]<<endl;
	}
		
		
	
	
	
	
	
	return 0;
}


/*
192 384 576
219 438 657
273 546 819
327 654 981
*/