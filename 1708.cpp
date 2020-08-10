#include<iostream> 
#include<cmath>
using namespace std;
const int inf = 0x3f3f3f;
struct point{
	int x;
	int y;
};
//天然气管道必须从某个天然气井开始，向南(y--)或者向东(x++)建设 
//向东走则x坐标增加，向北走则y坐标增加 
int main(){
	int n; cin>>n;
	point jing[n+1],zhan[n+1];
	//输入坐标 
	long sam_x,sam_y;
	for(int i=1;i<=n;i++){
		cin>>jing[i].x>>jing[i].y;
		sam_x+=jing[i].x;
		sam_y+=jing[i].y;
	}
	
	for(int j=1;j<=n;j++){ 
		cin>>zhan[j].x>>zhan[j].y;
		sam_x-=zhan[j].x;
		sam_y-=zhan[j].y;
	} 
	cout<<abs(sam_x)+abs(sam_y);
}
