#include<bits/stdc++.h>
using namespace std;
int num[3],js[3],ans=0;
int arr[9]={1,2,3,4,5,6,7,8,9};
int gcdbin(int t_a,int t_b)
{
	if(t_b==0) return t_a;
	if(t_a%2==0&&t_b%2==1) return gcdbin(t_a/2,t_b);
	if(t_a%2==1&&t_b%2==0) return gcdbin(t_a,t_b/2);
	if(t_a%2==0&&t_b%2==0) return 2*gcdbin(t_a/2,t_b/2);
	return gcdbin(t_b,t_b-t_a);
}
void calculate()
{
	for(int i=0;i<3;i++)
		js[i]=100*arr[3*i]+10*arr[3*i+1]+arr[3*i+2];
	return;
}
int main()
{
	for(int i=0;i<3;i++)
	cin>>num[i];
	int gcd=gcdbin(num[0],gcdbin(num[1],num[2]));
	num[0]/=gcd;
	num[1]/=gcd;
	num[2]/=gcd;
	do
	{
		if(arr[0]==0||arr[3]==0||arr[6]==0) continue;
		calculate();
		bool flag=0;
		int m[3];
		for(int i=0;i<3;i++)
		{
			if(js[i]%num[i]!=0){
				flag=1;
				break;
			}
			m[i]=js[i]/num[i];
		}
		if(flag) continue;
		if(m[0]==m[1]&&m[1]==m[2])
		{
			for(int i=0;i<9;i++){
				cout<<arr[i]; 
				if(i%3==2) cout<<" ";
			}
			cout<<endl;
			ans=1;
		}
		
//		for(int i=0;i<9;i++)
//				cout<<arr[i]<<" "; 
//			cout<<endl;
	}while(next_permutation(arr,arr+9));
	if(!ans) cout<<"No!!!";
	return 0;
}
