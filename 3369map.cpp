#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#define re register
using namespace std;

template<class T>inline void read(T&x)

{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
}
inline int read()
{
	int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    x=ch-'0';ch=getchar();
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int G[55];
template<class T>inline void write(T x)
{
    int g=0;
    do{G[++g]=x%10;x/=10;}while(x);
    for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
map<int,int>tree;
int t;
int main()
{
	freopen("P3369_6.in","r",stdin);
	freopen("3369.out","w",stdout);
	cin>>t;
	int a,b;
	int cnt=1;
	while(t--)
	{
		cin>>a>>b;
		if(a==1) tree[b]++;
		if(a==2){
			if(tree.find(b)!=tree.end()){
				if(tree[b]==1) tree.erase(b); 
				else tree[b]--;
			} 
		}
		if(a==3){
			int tot=1;
			for(map<int,int>::iterator iter=tree.begin();iter!=tree.end();iter++,tot++)
			{
				if(iter==tree.find(b)) break;
			}
			cout<<tot<<endl;
		}
		if(a==4){
			map<int,int>::iterator iter=tree.begin();
			for(int i=0;i<b;)
			{
				i+=(iter->second);
				iter++;
			}
			iter--;
			cout<<iter->first<<endl;
		}
		if(a==5){
			tree[b]++;
			map<int,int>::iterator iter=tree.find(b);
			iter--;
			cout<<iter->first<<endl;
			tree[b]--;
			if(tree[b]==0) tree.erase(b);
		}
		if(a==6){
			tree[b]++;
			map<int,int>::iterator iter=tree.find(b);
			iter++;
			cout<<iter->first<<endl;
			tree[b]--;
			if(tree[b]==0) tree.erase(b);
		}
	}
	return 0;
}

