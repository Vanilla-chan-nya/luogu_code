#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	getchar();
	char ch[50]; gets(ch);
//	string ch; getline(cin,ch);
	for(int i=0;i<50;i++)
	{
		if(ch[i]<'a'||ch[i]>'z') break;
		else {
			ch[i]+=n;
//			while((ch[i]-'a')>=0)
//			ch[i]-=26;
			if(ch[i]>'z') ch[i]-=26;
			cout<<ch[i];
		}
		
	}
//	puts(ch);
	return 0;
} 
