#include<bits/stdc++.h>
using namespace std;
int ch[100010][2],cnt[100010],key[100010],size[100010],fa[100010];
int n,rt,tot;
void update(int x) {
	size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];
}
bool chk(int x){ return (ch[fa[x]][1]==x);}
void rotate(int x) {
	int k=chk(x),y=fa[x],z=fa[y];
	ch[z][chk(y)]=x,fa[x]=z;
	ch[y][k]=ch[x][k^1],fa[ch[x][k^1]]=y;
	ch[x][k^1]=y,fa[y]=x;
	update(x),update(y);
}
void splay(int x,int goal=0) {
	while(fa[x]!=goal) {
		if(fa[fa[x]]!=goal)
			if(chk(fa[x])==chk(x)) rotate(fa[x]);
			else rotate(x);
		rotate(x);
	}
	if(!goal) rt=x;
}
int find(int val)
{
	int x=rt;
	while(ch[x][val>key[x]]&&val!=key[x]) x=ch[x][val>key[x]];
	splay(x);
	return x;
}
void add(int val)
{
	int x=rt,fat=0;
	while(x&&val!=key[x])
	{
		fat=x;
		x=ch[x][val>key[x]];
	}
	if(x) cnt[x]++,size[x]++;
	else {
		x=++tot;
		if(fat) ch[fat][val>key[fat]]=x;
		fa[x]=fat;
		ch[x][0]=ch[x][1]=0;
		key[x]=val;
		cnt[x]=size[x]=1;
	}
	splay(x);
}
int pre(int val)
{
	int x=find(val);
	if(key[x]<val) return x;
	x=ch[x][0];
	while(ch[x][1]) x=ch[x][1];
	return x;
}
int next(int val)
{
	int x=find(val);
	if(key[x]>val) return x;
	x=ch[x][1];
	while(ch[x][0]) x=ch[x][0];
	return x;
}
void del(int val)
{
	int x=pre(val);int y=next(val);splay(x);
	splay(y,x);
	int p=ch[y][0];
	if(cnt[p]>=2){
		cnt[p]--,size[p]--; splay(p);
		return;
	}
	ch[y][0]=0;
	splay(y);
}
void query1(int val)
{
	int x=find(val);
	printf("%d\n",size[ch[x][0]]);
}
void query2(int val)
{
	int x=rt;
	while(1)
	{
		if(size[ch[x][0]]>=val) x=ch[x][0];
		else if(size[ch[x][0]]+cnt[x]<val) val-=size[ch[x][0]]+cnt[x],x=ch[x][1];
		else break;
	}
	printf("%d\n",key[x]);
	splay(x);
}
int main()
{
	scanf("%d",&n);
	add(-INT_MAX),add(INT_MAX);
	for(int i=1,opt,x;i<=n;i++) {
		scanf("%d%d",&opt,&x);
		if(opt==1) add(x);
		else if(opt==2) del(x);
		else if(opt==3) query1(x);
		else if(opt==4) x++,query2(x);
		else if(opt==5) printf("%d\n",key[pre(x)]);
		else if(opt==6) printf("%d\n",key[next(x)]);
	}
	return 0;
}

