#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 5e3+3;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int N,V;//1,N,V,5e3
int w[maxn],c[maxn],f[maxn]={0};
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>N>>V;
    for(int i=0;i<N;++i){
        cin>>w[i]>>c[i];
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=V;++j){
            if(j-w[i]>=0){
                f[j]=max(f[j],f[j-w[i]]+c[i]);
            }
        }
    }
    cout<<f[V];
    return 0;
}