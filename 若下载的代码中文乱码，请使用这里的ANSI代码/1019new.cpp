#include<iostream>
#include<cstring>
using namespace std;
int use[20],n,ans,maxans;
string word[20];
char f;
int iqr(int a,int b){//inquire
	int ccdn=0;//coincidence
	int flag=0,lena=word[a].size(),lenb=word[b].size();
	for(int i=1;i<min(lena,lenb);i++)//i是a，b的重合部分 
	{
		//i!=min(lena,lenb)，因为两者不能包含，所以就不管这种情况了 
		for(int j=0;j<i;j++)//对重合部分逐个的检查 
		{
			if(word[a][lena-i+j]!=word[b][j])
			break;  
			flag=1;
		}
		if(flag) return i;
	}
	return 0;
}
void sreach(int num,int len){//dfs
	for(int i=0;i<n;i++)
	{
		if(use[i]>=2) continue;
		int newlen=iqr(num,i);
		if(newlen>0)
		{
			use[i]++;
			sreach(i,len+word[i].size()-newlen);
			use[i]--;
		}
	}
	maxans=max(maxans,len);
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>word[i];
	cin>>f;
	for(int i=0;i<n;i++)
		if(word[i][0]==f)
		{
			ans=0;
			memset(use,0,sizeof(use));
			use[i]++;
			sreach(i,word[i].size());
		}
	cout<<maxans;
	return 0;
}
