#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxN = 1e4+4;
const int maxn = maxN*100;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int N,V;//1,N,V,5e3
ll w[maxn],c[maxn],f[maxn]={0};
int iter;
void addItem(int _w,int _v){
    w[++iter]=_w;
    c[iter]=_v;
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>N>>V;
    int weight,value,count;
    iter=0;
    while(N--){
        cin>>weight>>value>>count;
        for(int i=1;i<=count;i*=2){
            addItem(weight*i,value*i);
            count-=i;
        }
        if(count>0){
            addItem(weight*count,value*count);
        }
    }
    for(int i=1;i<=iter;++i){
        for(int j=V;j>=1;--j){
            if(j-w[i]>=0){
                f[j]=max(f[j],f[j-w[i]]+c[i]);
            }
        }
    }
    /*
    for(int i=1;i<=iter;++i){
        for(int j=V;j>=w[i];--j){
            f[j]=max(f[j],f[j-w[i]]+c[i]);
        }
    }
    */
    cout<<f[V];
    return 0;
}