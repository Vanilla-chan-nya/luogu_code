#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
#include<cstring>
#include<windows.h>
#define IL inline
using namespace std;
IL void fin(){freopen(".in","r",stdin);}
IL void fout(){freopen(".out","w",stdout);}
IL void fio()
{
	fin();
	fout();
}
int all,t,err;
int main()
{
//	fio();
	cin>>all;
	t=all;
	a:
	cout<<"making rand����\n";
	system("2525rand.exe");
	cout<<"run STL\n";
	system("2525.exe");
	cout<<"run 2525unSTL.exe\n";
	system("2525unSTL.exe");
	if(system("fc 2525.out 2525unSTL.out")) 
	{
//		system("pause");
		err++;
	}
	if(t--)
		goto a;
	cout<<(double)err/all;
	return 0;
}

