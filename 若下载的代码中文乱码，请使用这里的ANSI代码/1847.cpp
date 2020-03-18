#include<bits/stdc++.h>
using namespace std;
struct square{
	int x1;
	int y1;
	int x2;
	int y2;
} boom[2001];
int m,n;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>boom[i].x1>>boom[i].y1>>boom[i].x2>>boom[i].y2;
	}
	int tx,ty;
	for(int i=1;i<=n;i++)
	{
		cin>>tx>>ty;
		int time=0,last=0;
		for(int j=1;j<=m;j++)
		if(boom[j].x1<=tx&&boom[j].x2>=tx&&boom[j].y1<=ty&&boom[j].y2>=ty)
		{
			time++;
			last=j;
		}
		if(!time) cout<<"NO\n";
		else cout<<"YES "<<time<<" "<<last<<endl;
	}
	return 0;
}
