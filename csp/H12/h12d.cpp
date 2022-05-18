#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxN = 1e3+3;
const int maxn = maxN*100;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int N,V;//1,N,V,5e3
ll w[maxn],c[maxn],f[maxn]={0},k;
vector<vector<int> > group(maxn);
int iter;
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>N>>V;
    int weight,value,numGroup=0;
    iter=0;
    for(int i=1;i<=N;++i){
        cin>>w[i]>>c[i]>>k;
        group[k].push_back(i);
        numGroup=numGroup>k?numGroup:k;
    }
    for(int i=1;i<=numGroup;++i){
        for(int j=V;j>=1;--j){
            for(int k:group[i]){
                if(j-w[k]>=0){
                    f[j]=max(f[j],f[j-w[k]]+c[k]);
                }
            }
        }
    }
    cout<<f[V];
    return 0;
}