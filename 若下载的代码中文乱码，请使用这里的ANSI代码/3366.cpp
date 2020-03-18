#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
	int x;
	int y;
	int z;
}v[5001];
bool cmp(edge a,edge b){return a.z<b.z;}
int n,m,f[5001],size[5001],ans,yet;
int getf(int a)
{
	if(f[a]==a) return a;
	return f[a]=getf(f[a]);//Â·¾¶Ñ¹Ëõ 
}
void merge(int a,int b)
{
	int i=getf(a);
	int j=getf(b);
	if(size[i]>size[j]) swap(i,j);
	f[j]=i;
	size[i]+=size[j];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		size[i]=1;
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
		cin>>v[i].x>>v[i].y>>v[i].z;
	sort(v+1,v+m+1,cmp);
	for(int i=1;i<=m&&yet!=n-1;i++)
	{
		if(getf(v[i].x)!=getf(v[i].y))
		{
			merge(v[i].x,v[i].y);
			ans+=v[i].z;
			yet++;
		}
	}
	cout<<ans;
	return 0;
}
