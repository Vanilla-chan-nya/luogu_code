//P1616 疯狂的采药WA!!!!!!
#include<bits/stdc++.h>

using namespace std;

double T,M,V=0;

struct object{
	double vable;
	double time;
	double vbt;
}thing[100001];

//vector<object> a;

//bool operator <(const object &a,const object &b) {return a.vbt>b.vbt;}

int main(){
	freopen("testdata2.in","r",stdin);
	cin>>T>>M;
	for(int i=0;i<M;i++)
	{
		cin>>thing[i].time>>thing[i].vable;
		thing[i].vbt=thing[i].time*1.0/(thing[i].vable*1.0);
		if(thing[i].time>T) thing[i].vbt=-1.0;
	}
	
//	sort(a.begin(),a.end());
/*
	for(int i=0;i<M;i++)
	for(dint j=0;j<i-1;j++)
		if(thing[j].vbt<thing[j+1].vbt)
		{
			swap(thing[j].time,thing[j+1].time);
			swap(thing[j].vable,thing[j+1].vable);
			swap(thing[j].vbt,thing[j+1].vbt);
		}
*/
	for(int i=0;i<M;i++)
	{
		if(thing[i].time>T) continue;
		if(T==0) break;
		while(T>=thing[i].time)
		{
			T-=thing[i].time;
			V+=thing[i].vable;
		}	
	}
	cout<<V;
	return 0;
}
