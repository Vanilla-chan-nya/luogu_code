#include<iostream>//不想OI一场空，千万别用万能头
#include<algorithm>//快排sort()
#include<cstdio>//能不用cin就不用
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define IL inline
using namespace std;
int a[100000];
string str;
bool zf,qd;
int main(){
    getline(cin,str);
    if(str[0]=='-') zf=1,cout<<"-";
    for(int i=str.size()-1;i>=(int)zf;i--)
    {
    	if(str[i]!='0') qd=1;
    	if(qd) cout<<str[i];
	}
	return 0;
}
