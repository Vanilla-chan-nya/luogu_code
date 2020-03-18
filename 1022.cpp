#include<bits/stdc++.h>
using namespace std;
string sentence;
int dl1,dl2,ta;//系数&常数项 
int xs(int n,int t)
{
	if(sentence[n]>='0'&&sentence[n]<='9')
		return xs(n+1,t*10+sentence[n]-'0');
	ta=n;
	return t;
}
int main()
{

	getline(cin,sentence);
	char x;
	int zf=1,w=0,t=-1,fh;
	while(sentence[++t]!='\0')
	{
		fh=1;
		if(sentence[t]=='=') 
		{
			zf=-1;
			continue;
		}
		if(sentence[t]=='-')
		{
			fh=-1;
			t++;
		}
		if(sentence[t]>='a'&&sentence[t]<='z')
		{
			x=sentence[t];
			dl1+=zf*fh;
			continue;
		}
		if(sentence[t]<='9'&&sentence[t]>='0')
		{
			int n=xs(t,0);
			t=ta;
			if(sentence[t]>='a'&&sentence[t]<='z')
			{
				dl1+=n*zf*fh;
				x=sentence[t];
			}			
			else
			{
				dl2+=n*zf*fh;
				t--; 
			} 
		}
		
	}
	cout<<x<<"=";
	//double会出现-0的情况！
	double ans= -dl2/(dl1*1.0);
	if(ans==-0.000) ans=0.000;
	printf("%.3lf",ans); 
	return 0;
}
