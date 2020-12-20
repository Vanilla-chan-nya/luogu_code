//this is zzh810's code
//just for test
//just for test
//just for test
//just for test
//just for test








#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+10;
int t,n,a[MAXN],q1[MAXN][2],q2[MAXN][2],l1,l2,r1,r2,ans;//ans=被吃了几条蛇
//q1[i][0]=q2[i][0]=值,q1[i][1]=q2[i][1]=编号
struct node
{
	int flag,sum,id;
};

int read()
{
	int sum=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return sum;
}

node Get_Max()//取出最大值
{
	int sum=0,flag=1,id=0;
	if(l2<=r2)
	{
		if(q2[r2][0]>=sum) {sum=q2[r2][0];id=q2[r2][1];flag=2;}
	}
	if(l1<=r1)
	{
		if(q1[r1][0]>sum) {sum=q1[r1][0];id=q1[r1][1];flag=1;}
		else if(q1[r1][0]==sum&&q1[r1][1]>id) {sum=q1[r1][0];id=q1[r1][1];flag=1;}
	}
	if(flag==1) r1--;
	else r2--;
	return (node){flag,sum,id};
}

node Get_Min()//取出最小值
{
	int sum=0x7f7f7f7f,flag=1,id=0;
	if(l2<=r2)
	{
		if(q2[l2][0]<=sum) {sum=q2[l2][0];id=q2[l2][1];flag=2;}
	}
	if(l1<=r1)
	{
		if(q1[l1][0]<sum) {sum=q1[l1][0];id=q1[l1][1];flag=1;}
		else if(q1[l1][0]==sum&&q1[l1][1]<id) {sum=q1[l1][0];id=q1[l1][1];flag=1;}
	}
	if(flag==1) l1++;
	else l2++;
	return (node){flag,sum,id};
}

void Solve1()//结论 1
{
	while(1)
	{
		if(n-ans==1) return ;//注意边界条件
		node x=Get_Max(),y=Get_Min();
		node z=Get_Min();
		if(x.sum-y.sum>z.sum||(x.sum-y.sum==z.sum&&x.id>z.id))//能吃
		{
			ans++;
			q2[--l2][0]=x.sum-y.sum;q2[l2][1]=x.id;
			if(l1<=r1&&(z.sum<q1[l1][0]||(z.sum==q1[l1][0]&&z.id<q1[l1][1]))) {q1[--l1][0]=z.sum;q1[l1][1]=z.id;}
			else {q2[--l2][0]=z.sum;q2[l2][1]=z.id;}
			continue;
		}
		else//不能吃 
		{
			if(x.flag==1) {q1[++r1][0]=x.sum;q1[r1][1]=x.id;}else {q2[++r2][0]=x.sum;q2[r2][1]=x.id;}
			if(z.flag==1) {q1[--l1][0]=z.sum;q1[l1][1]=z.id;}else {q2[--l2][0]=z.sum;q2[l2][1]=z.id;}
			if(y.flag==1) {q1[--l1][0]=y.sum;q1[l1][1]=y.id;}else {q2[--l2][0]=y.sum;q2[l2][1]=y.id;}//塞回队列里面 
			return ;
		}
	}
}

bool Slove2(int last)//结论 2
{
	if(last==0) return 0;
	if(last==1) return 0;
	if(last==2) return 1;//注意边界条件
	node x=Get_Max();node y=Get_Min();node z=Get_Min();
	if(x.sum-y.sum>z.sum||(x.sum-y.sum==z.sum&&x.id>z.id)) return 1;//结论 1
	else
	{ 
		if(l1<=r1&&(z.sum<q1[l1][0]||(z.sum==q1[l1][1]&&q1[l1][1]>z.id))) {q1[--l1][0]=z.sum;q1[l1][1]=z.id;}
		else {q2[--l2][0]=z.sum;q2[l2][1]=z.id;}
		if(l1<=r1&&(x.sum-y.sum<q1[l1][0]||(x.sum-y.sum==q1[l1][0]&&q1[l1][1]>x.id))) {q1[--l1][0]=x.sum-y.sum;q1[l1][1]=x.id;}
		else {q2[--l2][0]=x.sum-y.sum;q2[l2][1]=x.id;}
		return !Slove2(last-1);//递归实现 
	}
}

int main()
{
	t=read();
	bool flag=0;
	while(t--)
	{
		ans=0;//多测不清空，爆零两行泪
		memset(q1,0,sizeof(q1));
		memset(q2,0,sizeof(q2));
		if(!flag)
		{
			n=read();flag=1;
			for(int i=1;i<=n;i++) a[i]=read();
		}
		else
		{
			int k=read();
			for(int i=1;i<=k;i++)
			{
				int x,y;x=read();y=read();a[x]=y;
			}
		}
		l1=1;r1=0;l2=n+1;r2=n;
		for(int i=1;i<=n;i++) q1[++r1][0]=a[i];
		for(int i=1;i<=n;i++) q1[i][1]=i;
		Solve1();
		if(Slove2(n-ans)) ans++;//根据结论 2 看看能不能再吃一条 
		cout<<n-ans<<"\n";//输出存活蛇
	}
	return 0;
}
