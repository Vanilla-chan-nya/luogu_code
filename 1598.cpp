#include<bits/stdc++.h>
using namespace std;
int zm[27];
int main(){
	memset(zm,0,sizeof(zm));
	char tz;
	while(scanf("%c",&tz)!=EOF)	
		if(tz>='A'&&tz<='Z') zm[tz-'A'+1]++;
	//找最高的 
	int maxn=-1; 
	for(int i=1;i<=26;i++)
		if(maxn<zm[i])
			maxn=zm[i];
	//循环打印行 
	int maxl;
	for(int h=maxn;h>=1;h--)
	{
		//找每行最后一个
		for(int j=26;j>=1;j--)
			if(zm[j]>=h) 
			{
				maxl=j;
				break;
			}
		for(int l=1;l<=maxl;l++)
		{
			if(zm[l]>=h) cout<<"*";
			else cout<<" ";
			if(l!=maxl) cout<<" ";
		}
		cout<<endl;
	} 
	for(int i=1;i<=26;i++){
		cout<<char(i+'A'-1);
		if(i!=26)
		cout<<" ";	
	}
	return 0;
}
