#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
#include<cstring>
#define IL inline
using namespace std;
IL void fin(){freopen("3375test.in","r",stdin);}
IL void fout(){freopen(".out","w",stdout);}
IL void fio()
{
//	fin();
//	fout();
}
string t,p;
int f[10000];
int nxt[10000];
int main()
{
	fio();
	getline(cin,t);
	getline(cin,p);
	for(int i=2,j=nxt[1]=0;i<t.size();i++)
	{
		while(j>0&&t[i]!=t[j+1]) j=nxt[j];
		if(t[i]==t[j+1]) j++;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<p.size();i++)
	{
		while(j>0&&(p[i]!=t[j+1]||j==t.size())) j=nxt[j];
		if(p[i]==t[j+1]) j++;
		f[i]=j;
		if(f[i]==t.size()) cout<<i<<endl;
	}
	cout<<f[p.size()]<<endl;
	for(int i=0;i<p.size();i++) cout<<nxt[i]<<" ";
	return 0;
}

