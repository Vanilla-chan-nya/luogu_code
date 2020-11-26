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
#define debug printf("Now is %d\n",__LINE__);
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
    if(x<0) x=-x,putchar('-');
    do{G[++g]=x%10;x/=10;}while(x);
    for(re int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}
const double eps=1e-5;

double sx,sy;
bool book[20];
struct node
{
	double x,y;
	void input()
	{
		cin>>x>>y;
	}
}b[20];
int cnt;
vector<int>his;
bool judge(int c,int d,int e,int f)
{
	if(c==d||d==e||e==f||c==f||c==e||d==f) return 0;
	double x1=b[c].x,y1=b[c].y,x2=b[d].x,y2=b[d].y,x3=b[e].x,y3=b[e].y,x4=b[f].x,y4=b[f].y;
	if(x1>x2) swap(x1,x2),swap(y1,y2);
	if(x3>x4) swap(x3,x4),swap(y3,y4);
	double k1=(y1-y2)/(x1-x2),b1=y1-x1*k1,k2=(y3-y4)/(x3-x4),b2=y3-x3*k2;
	if(fabs(k1-k2)<eps) return false;
	double x=(b2-b1)/(k1-k2);
	return x>x1&&x>x3&&x<x2&&x<x4;
}
int ans;
bool can[20][20][20][20];
void dfs(int depth,int last)
{
//	debug cout<<"depth="<<depth<<" last="<<last<<endl;
	if(depth==cnt+1)
	{
		ans++;
		return;
	}
	if(depth==cnt) book[1]=0;
	for(int i=1;i<=cnt;i++)
	{
//		debug cout<<"\ti="<<i<<endl;
		if(book[i]) continue;
		bool flag=0;
		for(int j=0;j+2<his.size();j++) if(can[i][last][his[j]][his[j+1]]==0) {flag=1;break;}
		if(flag) continue;
		his.push_back(i);
		book[i]=1;
		dfs(depth+1,i);
		book[i]=0;
		his.pop_back(); 
	}
	book[1]=1;
}
int main()
{
	do{
		b[++cnt].input();
	}while(b[cnt].x!=0||b[cnt].y!=0);
	for(int i=1;i<=cnt;i++)
	for(int j=1;j<=cnt;j++)
	for(int k=1;k<=cnt;k++)
	for(int l=1;l<=cnt;l++)
	{
		can[i][j][k][l]=!judge(i,j,k,l);
//		cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<judge(i,j,k,l)<<endl;
	}
	book[1]=1;
	his.push_back(1);
	dfs(1,1);
	cout<<ans/2;
	return 0;
}

