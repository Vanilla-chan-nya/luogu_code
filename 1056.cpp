#include<bits/stdc++.h>
using namespace std;
struct aisle{
	int hs;
	int num;
}hen[10001],shu[10001],ansa[10001],ansb[10001];
bool cmp(aisle ta,aisle tb){return ta.num>tb.num;}
bool cmp2(aisle ta,aisle tb){return ta.hs<tb.hs;}
int m,n,k,l,d,h,s;
int main()
{
//	freopen("1056text.txt","r",stdin);
	cin>>m>>n>>k>>l>>d;
	int x1,y1,x2,y2;
	for(int i=1;i<=n;i++) hen[i].hs=i;
	for(int i=1;i<=m;i++) shu[i].hs=i;
	for(int i=1;i<=d;i++) 
	{
		cin>>x1>>y1>>x2>>y2;
		//hen
		if(x1==x2)
		{
			hen[min(y1,y2)].num++;
		}
		if(y1==y2)
		{
			shu[min(x1,x2)].num++;
		}
	}
	sort(shu+1,shu+m+1,cmp);
	sort(hen+1,hen+n+1,cmp);
	sort(shu+1,shu+k+1,cmp2);
	sort(hen+1,hen+l+1,cmp2);
	for(int i=1;i<=k;i++)
	{
		cout<<shu[i].hs;
		if(i!=k) cout<<" ";
	}
	cout<<endl;
	for(int i=1;i<=l;i++)
	{
		cout<<hen[i].hs;
		if(i!=l) cout<<" ";
	}
	return 0;
}
