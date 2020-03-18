#include<bits/stdc++.h>
using namespace std;
int q,n,_unknow=0x3f3f3f;
int heap[1000001];

void heap_up(int _heap[],int _n,int _num)
{
	if(_heap[_num]<_heap[_num>>1]) {
		swap(_heap[_num],_heap[_num>>1]);
		heap_up(_heap+1,_n,_num>>1);
	}
	return;
}
void heap_down(int _heap[],int _n,int _num)
{
	int _l=_num*2,_r=_num*2+1;
	if(_l>_n) return;
	if(_l>=_n) 
		if(heap[_l]<heap[_num]) {
			swap(heap[_l],heap[_num]);
			heap_down(_heap+1,_n,_num*2);
		}
	if(_l<heap[_num]&&_l<heap[_r]){
		swap(heap[_l],heap[_num]);
		heap_down(_heap+1,_n,_num*2);
	}
	if(_r<heap[_num]&&_r<heap[_l]){
		swap(heap[_r],heap[_num]);
		heap_down(_heap+1,_n,_num*2+1);
	}
	return;
} 

void heap_pop_top(int _heap[],int _n)
{
	swap(_heap[1],_heap[_n]);
	heap_down(_heap,_n-1,1);
}
//创建 整理堆 
void heap_make(int _heap[],int _n)
{
	for(int i=_n;i>0;i--)
	{
		heap_up(_heap,_n,i);
		heap_down(_heap,_n,i);
	}
	return;
}  
void heap_push(int _heap[],int _n,int _num)
{
	_heap[_n+1]=_num;
//	heap_up(_heap+1,_n+1,_n);
//	haep_down(_heap+1,_n+1,_n);
	heap_make(_heap+1,_n);
} 
int main()
{
	cin>>q;
	int t;
	while(q--)
	{
		cin>>t;
		if(t==1){
			int tn;
			cin>>tn;
			heap_push(heap,n++,tn);
		}
		if(t==2){
			cout<<heap[1]<<endl;
		}
		if(t==3){
			heap_pop_top(heap,n);
			n--;
		}
	}
	return 0;
}
