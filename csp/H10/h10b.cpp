#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e7+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
ll n;
vector<ll> vec(maxn);
int main(){
    //ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    ll tmp;
    for(ll i=0;i<n;++i){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.begin()+n);
    printf("%d ",vec[n-1]);
    //cout<<<<' ';
    if(n&1){//奇数个
        cout<<vec[n/2]<<' ';
    }else{
        tmp=vec[n/2]-vec[n/2-1];
        if(tmp&1){//<<setprecision(2)
            double f=vec[n/2-1]+tmp/2.0;
            printf("%.1f ",f);
            //cout<<f<<" ";
        }else{
            cout<<vec[n/2-1]+tmp/2<<' ';
        }
    }
    printf("%d\n",vec[0]);
    //cout<<vec[0]<<'\n';
    return 0;
}