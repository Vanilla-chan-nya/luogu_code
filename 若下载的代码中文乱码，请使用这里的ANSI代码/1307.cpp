#include<iostream>//����OIһ���գ�ǧ���������ͷ
#include<algorithm>//����sort()
#include<cstdio>//�ܲ���cin�Ͳ���
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
