#include<iostream>
using namespace std;
int n,k,jh,a[50004];
int getf(int i){ 
    if(a[i]==i) return i;
    return a[i]=getf(a[i]);
}

void merge(int x,int y){
    if(getf(x)!=getf(y))
	{
		if(getf(y)>50000)
			a[getf(x)]=getf(y);
		else
			a[getf(y)]=getf(x);
	} 
    return;
}

bool inquire(int x,int y){ 
    return getf(x)==getf(y);
}

int main()
{
//	freopen("eat.in","r",stdin);
//	freopen("eat.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        a[i]=i;
    a[1]=50001;
    a[50001]=50001; a[50002]=50002; a[50003]=50003; 
    int z,x,y;
    for(int i=1;i<=k;i++)
    {
        cin>>z>>x>>y;
        if(x==y||x>n||y>n) {
        	jh++;
        	continue;
		}
		
        if(z==1){
        	if(inquire(x,y)) continue;
        	if(getf(x)>50000)
        	{
        		if(getf(y)>50000)
        		{
        			jh++;
        			break;
				}
			}
        	merge(x,y);	
		}
            
        if(z==2)
        {
        	if(inquire(x,y)) {
        		jh++; 
        		continue;
			}
			if(getf(x)<=50000&&getf(y)<=50000) {
				continue;
			}
			if(getf(x)>50000&&getf(y)>50000)
			{
				if((getf(x)==50003&&getf(y)==50001)||(getf(x)==50001&&getf(y)==50002)||(getf(x)==50002&&getf(y)==50003))
				continue;
			}
			if(getf(x)>50000)
				if(getf(x)==50001||getf(x)==50002) a[getf(y)]=getf(x)+1;
				else a[getf(y)]=getf(x)-2;
			if(getf(y)>50000)
				if(getf(y)==50001||getf(y)==50002) a[getf(x)]=getf(y)+1;
				else a[getf(x)]=getf(y)-2;
		}   
    }
    cout<<jh;
    return 0;
}
