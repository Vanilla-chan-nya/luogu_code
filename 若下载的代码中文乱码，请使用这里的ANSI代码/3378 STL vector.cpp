#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int t_x,int t_y){return t_x>t_y;}

int q,num;

vector<int> heap;

int main()
{
//	make_heap(heap.begin(),heap.end(),cmp);
	cin>>q;
	int t;
	while(q--)
	{
		cin>>t;
		if(t==1){
			int tn;
			cin>>tn;
			heap.push_back(tn);
			make_heap(heap.begin(),heap.end(),cmp);
		}
		if(t==2){
			cout<<heap[0]<<endl;
		}
		if(t==3){
			pop_heap(heap.begin(),heap.end(),cmp);
			heap.pop_back();
			make_heap(heap.begin(),heap.end(),cmp);
		}
	}
	return 0;
}
