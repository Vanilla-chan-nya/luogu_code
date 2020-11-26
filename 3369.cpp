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
const int MAXL=100005;
const int INF=2147480000;
struct Splay{
	#define root e[0].ch[1]
	
//	private:
		
		struct node{
			int v;
			int father;
			int ch[2];
			int sum;
			int recy;
		}e[100010];
		void update(int x)//更新当前节点sum 
		{
			e[x].sum=e[e[x].ch[0]].sum+e[e[x].ch[1]].sum+e[x].recy;
		}
		int identify(int x)//确定当前节点到底是父亲的左孩子（0）还是右孩子（1）。
		{
			return e[e[x].father].ch[0]==x?0:1;
		}
		void connect(int x,int f,int son)//connect(son,father,0/1)
		{
			e[x].father=f;
			e[f].ch[son]=x;
		}
		void rotate(int x)//转x，相当于抬高x的高度 
		{
			int y=e[x].father;
			int mroot=e[y].father;//R
			int mrootson=identify(y);//y->x 's identify
			int yson=identify(x);//x->y 's identify 
			int B=e[x].ch[yson^1];
			connect(x,mroot,mrootson);connect(B,y,yson);connect(y,x,(yson^1));
			update(y);update(x);
			/*
			R
			 \
			  y
			 / \
			x   c
		   / \
		  A  B
		  
			^
			|
			V
			
			R
			 \
			  x
			 / \
			A   y
			   / \
			  B   c
			
			
			*/
		}
		void splay(int x,int goal=0)//将x节点旋转到goal节点所在的位置。
		{
			while(e[x].father!=goal) {
				int y=e[x].father;
				if(e[y].father) {
					if(identify(x)==identify(y)) rotate(y);
					else rotate(x);
				}
				rotate(x);
			}
			if(!goal) root=x;
		}
		int crepoint(int v,int father)//创造一个指定father，v为v的点 
		{
			n++;
			e[n].v=v;
			e[n].father=father;
			e[n].sum=e[n].recy=1;
			return n;
		}
//	public:
		
		int find(int v)
		{
			int now=root;
			while(1)
			{
				if(e[now].v==v)
				{
					splay(now,0);//查找结束后，将被查找的节点旋转到根，以保证树的结构随机性。
					return now;
				}
				int nxt=(v<e[now].v)?0:1;
				if(!e[now].ch[nxt]) return 0;
				now=e[now].ch[nxt];
			}
		}
		void push(int v)//将新加入的节点旋转到根，以保证树的结构随机性。
		{
			int x=root,fat=0;
			while(e[x].v&&e[x].v!=v) fat=x,x=e[x].ch[v>e[x].v];
			if(x) e[x].recy++;
			else {
				x=++n;
				e[x].father=fat;
				e[x].recy=e[x].sum=1;
				e[x].v=v;
			}
			splay(x);
		}
		void pop(int v)
		{
			int pre=lower(v),nxt=upper(v);
			splay(pre),splay(nxt,pre);
			int p=e[nxt].ch[0];
			if(e[p].recy>=2) e[p].recy--,splay(p);
			else e[nxt].ch[0]=0,splay(nxt);
		}
		int rank(int v)
		{
			int ans=0,now=root;
			while(true)
			{
				if(e[now].v==v) return ans+e[e[now].ch[0]].sum+1;
				if(now==0) return 0;//找不到 
				if(v<e[now].v) now=e[now].ch[0];//向左找，rank(ans)不变 
				else
				{
					ans+=e[e[now].ch[0]].sum+e[now].recy;
					now=e[now].ch[1];
				} 
			}
			if(now) splay(now,0);//理论上这句话最好要执行，等一会修改 
			return 0;
		}
		int artrank(int val)
		{
			int x=root;
			while(1)
			{
				if(e[x].sum-e[e[x].ch[1]].sum>=val) {
					if(val>e[e[x].ch[0]].sum) break;
					x=e[x].ch[0];
				}
				else val-=e[x].sum-e[e[x].ch[1]].sum,x=e[x].ch[1];
			}
			splay(x);
			return e[x].v;
		}
		int lower(int v)
		{
			v=find(v);
			splay(v);
			v=e[v].ch[0];
			while(e[v].ch[1]) v=e[v].ch[1];
			return v;
		}
		int upper(int v)
		{
			v=find(v);
			splay(v);
			v=e[v].ch[1];
			while(e[v].ch[0]) v=e[v].ch[0];
			return v;
		}
		int n,points;
//	#undef root
};

Splay tree;
int t;
int main()
{
	t=read();
	tree.push(INT_MAX),tree.push(-INT_MAX);
	int a,b;
	while(t--)
	{
		a=read();
		b=read();
		switch(a)
		{
			case 1:{
				tree.push(b);
				break;
			}
			case 2:{
				tree.pop(b);
				break;
			}
			case 3:{
				cout<<tree.rank(b)<<endl;
				break;
			}
			case 4:{
				b++,cout<<tree.artrank(b)<<endl;
				break;
			}
			case 5:{
				cout<<tree.lower(b)<<endl;
				break;
			}
			case 6:{
				cout<<tree.upper(b)<<endl;
				break;
			}
		}
	}
	return 0;
}

