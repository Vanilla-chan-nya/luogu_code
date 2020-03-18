#include<bits/stdc++.h>
using namespace std;
int n,k;
const int unknow = 0x3f3f3f3f;

/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/

struct animal{
	int self;
	int eat;
	int enemy;
} ani[50001];

//找祖先 
int getf(int a)
{
	
}
//合并 返回是否合法 
bool merge(int a,int b)
{
	
	animal i=getf(a);
	animal j=getf(b);
	if(i.eat==j.self||j.self==i.eat||i.enemy==j.self||i.self==j.enemy)
		return 0;
	if(i.eat!=j.eat){
		ani[i.eat].eat=ani[j.eat].eat;
	}
	if(i.self!=j.self){
		ani[i.self].self=ani[j.self].self;
	}
	if(i.enemy!=j.enemy){
		ani[i.enemy].enemy=ani[j.enemy].enemy;
	}
	return 1;
}
int main()
{
//	freopen("eat.in","r",stdin);
//	freopen("eat.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		ani[i].self=i;
		ani[i].eat=unknow;
		ani[i].enemy=unknow;
	}
	int t,tx,ty,err=0;
	while(k--)
	{
		cin>>t>>tx>>ty;
		if(tx>n||ty>n){
			err++;
			continue;
		}
		animal x1=getf(tx);
		animal y1=getf(ty);
		if(t==1)
		{
			if(tx==ty) continue;
			if(x1.self==y1.self) continue;
			if(x1.eat==y1.self||x1.self==y1.eat||x1.enemy==y1.self||x1.self==y1.enemy){
				err++;
				continue;
			}
			merge(tx,ty);
			/*
			if(!merge(tx,ty)){
				err++;
				continue;
			}
			*/
		}
		if(t==2)
		{
			if(tx==ty){
				err++;
				continue;
			}
			if(x1.eat==y1.eat||x1.enemy==y1.enemy||x1.self==y1.self){
				err++;
				continue;
			}
			x1.eat=y1.self;
			x1.self=y1.enemy;
			x1.enemy=y1.eat;
		}
	}
	cout<<err;
	return 0;
}
