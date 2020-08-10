#include<iostream>//不想OI一场空，千万别用万能头
#include<algorithm>//快排sort()
#include<cstdio>//能不用cin就不用
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
	cout<<"making rand……\n";
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

