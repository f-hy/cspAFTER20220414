#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int n;
int maxa;
int num[maxn];
ll sum[maxn];
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    int a;
    while(n--){
        cin>>a;
        maxa=max(maxa,a);
        ++num[a];
    }
    sum[0]=0;
    sum[1]=num[1];
    for(int i=2;i<=maxa;++i){
        sum[i]=max(sum[i-1],sum[i-2]+num[i]*i);
    }
    cout<<sum[maxa]<<endl;
    return 0;
}