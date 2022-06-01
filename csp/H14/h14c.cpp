#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i, s, t) for(int i=s;i<=t;i++)
#define ite(it,s,e) for(auto it=s,it!=e,++it)

const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const int maxn = 1e6+6;
ll max(ll a,ll b){return a>b?a:b;}
int n,m;//1e6
vector<ll> a(maxn),sum(maxn);
deque<ll> dq;
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n>>m;
    sum[0]=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=0;
    dq.push_back(0);
    for(ll i=1;i<=n;i++){
        while(!dq.empty()&&sum[dq.back()]>sum[i]) dq.pop_back();//维护递增
        dq.push_back(i);
        while(!dq.empty()&&i-m>dq.front()) dq.pop_front();
        ans=max(ans,sum[i]-sum[dq.front()]);
    }
    cout<<ans;
    return 0;
}