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
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif
using namespace std;

template<class T>inline void read(T&x)
{
	char ch=getchar();
	int fu;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=fu;
}
inline int read()
{
	int x=0,fu=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') fu=-1,ch=getchar();
	x=ch-'0';ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
int G[55];
template<class T>inline void write(T x)
{
	int g=0;
	if(x<0) x=-x,putchar('-');
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
#define maxn 100010
#define alpha 0.7
struct scapegoat
{
	int son[2];
	int val;
	int valid,total;
	//valid:没有被删除的子树的点数
	//total:子树总点数 
	bool exist;//==!lazy_delete
}e[maxn];
int memory[maxn];//pre memory 
int cur[maxn];//拍扁时用的内存
int root,pool,poi,cnt,to_rebuild;
/*
root根
pool指向memory的指针 
poi指向cur的指针
*/
IL bool isbad(int x)
{
	if(e[x].valid*alpha<=max(e[e[x].son[0]].valid,e[e[x].son[1]].valid)) return true;
	return false;
}
void dfs(int x)
{
	if(!x) return;
	//严格按照左中右的顺序 
	if(e[x].son[0]) dfs(e[x].son[0]);
	if(e[x].exist) cur[++poi]=x;
	else memory[++pool]=x;
	if(e[x].son[1]) dfs(e[x].son[1]);
}
void build(int l,int r,int& x)//建树很像线段树的建树。但是要注意mid是当前的节点。 
{
	int mid=l+r>>1;
	x=cur[mid];
	if(l==r)
	{
		e[x].son[0]=e[x].son[1]=0;
		e[x].total=e[x].valid=1;
		return;
	}
	if(l<mid) build(l,mid-1,e[x].son[0]);
	else e[x].son[0]=0;
	build(mid+1,r,e[x].son[1]);
	e[x].total=e[e[x].son[0]].total+e[e[x].son[1]].total;
	e[x].valid=e[e[x].son[0]].valid+e[e[x].son[1]].valid;
}
void rebuild(int &x)
{
	poi=0;
	dfs(x);
	if(poi) build(1,poi,x);
}
void insert(int &x,int val)
{
	if(!x)
	{
		x=memory[pool--];
		e[x].val=val;
		e[x].valid=1;
		e[x].exist=1;
		e[x].total=1;
		e[x].son[0]=e[x].son[1]=0;
		return;
	}
	e[x].total++;
	e[x].valid++;
	if(e[x].val>=val) insert(e[x].son[0],val);
	else insert(e[x].son[1],val);
	if(!isbad(x))
	{
		//当前节点不需要重建，则观察其左/右儿子是否需要 
		if(to_rebuild)
		{
			if(e[x].son[0]==to_rebuild) rebuild(e[x].son[0]);
			else rebuild(e[x].son[1]);
			to_rebuild=0;
		}
	}
	else to_rebuild=x;
}
int find_kth(int k)
{
	int x=root;
	while(x)
	{
		if(e[x].exist&&e[e[x].son[0]].valid+1==k) return x;
		if(e[e[x].son[0]].valid+e[x].exist>=k) x=e[x].son[0];
		else k-=e[e[x].son[0]].valid+e[x].exist,x=e[x].son[1];
	}
}
void find_rank(int k)
{
	int x=root;
	int ans=1;
	while(x)
	{
		if(k>e[x].val) ans+=
	}
}
void delete_pos(int& x,int tar)//删除排名为tar的数 
{
	if(e[x].exist&&e[e[x].son[0]].valid+1==tar)
	{
		e[x].exist=0;
		e[x].valid--;
		return;
	}
	e[x].valid--;
	if(e[e[x].son[0]].valid+e[x].exist>=tar) delete_pos(e[x].son[0],tar);
	else delete_pos(e[x].son[1],tar-e[e[x].son[0]].valid-e[x].exist);
}
void delete_val(int val)
{
	delete_pos(root,find_rank(val));
	if(isbad(root)) rebuild(root);
}
int main()
{
	
	
	return 0;
}


