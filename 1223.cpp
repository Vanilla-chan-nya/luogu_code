#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
#include<iomanip>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define IL inline
using namespace std;
struct people{
	int rank;
	int time;
}person[1001];
int n;
long long sum;
bool cmp(people a,people b){return a.time<b.time;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	 	cin>>person[i].time,person[i].rank=i;
	sort(person+1,person+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<person[i].rank<<" ";
		sum+=person[i].time*(n-i);
	}
	cout<<endl<<fixed<<setprecision(2)<<sum/(1.0*n);
	return 0;
}


