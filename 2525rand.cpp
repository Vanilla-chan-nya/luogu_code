#include<iostream>//不想OI一场空，千万别用万能头
#include<algorithm>//快排sort()
#include<cstdio>//能不用cin就不用
#include<cstring>
#include<ctime>
#define IL inline
using namespace std;
IL void fin(){freopen(".in","r",stdin);}
IL void fout(){freopen("test2525.in","w",stdout);}
IL void fio()
{
//	fin();
	fout();
}
int arr[10]={1,2,3,4,5,6,6,8,9,10};
int main()
{
	fio();
	srand(time(NULL));
	int n=rand()%9+1;
	cout<<n<<endl;
	random_shuffle(arr,arr+n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

