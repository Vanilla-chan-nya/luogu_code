#include<bits/stdc++.h>
#define N 100010
#define mid ((L+R)>>1)
using namespace std;
int n,m,k,Ans,rt[N*10];//颜色有1e6要开大一点 
int ls[N*32],rs[N*32],lv[N*32],rv[N*32],sum[N*32];//最左边位置,右边位置,区间颜色段 
void update(int t)
{
	lv[t] = lv[ls[t]]?lv[ls[t]]:lv[rs[t]];//因为是动态开点所以左右儿子可能为0要判一下 
	rv[t] = rv[rs[t]]?rv[rs[t]]:rv[ls[t]];
	sum[t] = sum[ls[t]]+sum[rs[t]]-(rv[ls[t]]+1 == lv[rs[t]]);//如果左右儿子位置相邻减1 
}
void Change(int &t,int L,int R,int x)
{
	if(!t) t = ++k;	
	if(L == R) {lv[t] = rv[t] = x,sum[t] = 1; return;}
	if(x <= mid) Change(ls[t],L,mid,x);
	else Change(rs[t],mid+1,R,x);
	update(t);
}
void Merge(int &x,int &y,int L,int R)//线段树合并板子 
{
	if(!x || !y) {x += y; return ;}
	if(L == R) {lv[x] = rv[x] = L,sum[x] = 1; return;}
	Merge(ls[x],ls[y],L,mid);
	Merge(rs[x],rs[y],mid+1,R);
	update(x);
}
int main()
{
	freopen("P3201.in","r",stdin);
	freopen("P3201.ans","w",stdout);
	int op,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		Ans -= sum[rt[x]];
		Change(rt[x],1,n,i);
		Ans += sum[rt[x]];	
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if(op == 1)
		{
			scanf("%d%d",&x,&y);
			if(x == y) continue;
			Ans -= (sum[rt[x]]+sum[rt[y]]);
			Merge(rt[y],rt[x],1,n);
			rt[x] = 0;  //注意清空颜色为x的线段树 
			Ans += sum[rt[y]];	
		}else printf("%d\n",Ans);
	}
	return 0;
}
