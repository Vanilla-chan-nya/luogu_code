#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 30
int a[maxn],b[maxn],c[maxn];
int num[maxn],Next[maxn],n,cnt;
char s1[maxn],s2[maxn],s3[maxn];
bool book[maxn];
bool Judge() {
    for(int i=n-1,x=0;i>=0;i--) {
        int A=num[a[i]],B=num[b[i]],C=num[c[i]];
        if((A+B+x)%n!=C) return false;
        x=(A+B+x)/n;
    }
    return true;
}
bool judge() {
    if(num[a[0]]+num[b[0]]>=n)
        return true;
    for(int i=n-1;i>=0;i--) {
        int A=num[a[i]],B=num[b[i]],C=num[c[i]];
        if(A==-1||B==-1||C==-1) continue;
        if((A+B)%n!=C&&(A+B+1)%n!=C)
            return true;
    }
    return false;
}
void Print() {
    for(int i=0;i<n;i++)
        printf("%d ",num[i]);
    exit(0);
}
void dfs(int x) {
    if(judge()==true) return;
    if(x==n) {
        if(Judge()==true) Print();
        return;
    }
    for(int i=n-1;i>=0;i--)
        if(book[i]==false) {
            num[Next[x]]=i;
            book[i]=true;
            dfs(x+1);
            num[Next[x]]=-1;
            book[i]=false;
        }
    return;
}
inline int id(char c) {
    return c-'A';
}
void GetNext(int x) {
    if(book[x]==false) {
        book[x]=true;
        Next[cnt++]=x;
    }
    return;
}
int main() {
    scanf("%d",&n);
    scanf("%s%s%s",s1,s2,s3);
    for(int i=0;i<n;i++) {
        a[i]=id(s1[i]);
        b[i]=id(s2[i]);
        c[i]=id(s3[i]);
        num[i]=-1;
    }
    for(int i=n-1;i>=0;i--) {
        GetNext(a[i]);
        GetNext(b[i]);
        GetNext(c[i]);
    }
    for(int i=0;i<n;i++) book[i]=false;
    dfs(0);
    return 0;
}
