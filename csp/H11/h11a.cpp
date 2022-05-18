#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const ll mod=998244353;
int n,m,k;
ll f[maxn];
set<int> ct;
ll solve(){
    f[0]=1;
    ll sum=0;
    for(int i=1;i<=n;++i){
        sum+=f[i-1];
        if(i-k-1>=0) sum-=f[i-k-1];
        sum=(mod+sum%mod)%mod;
        if(ct.find(i)!=ct.end()) continue;
        f[i]=sum;
    }
    return f[n];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    int tmp;
    for(int i=0;i<m;++i){
        cin>>tmp;
        ct.emplace(tmp);
    }
    cout<<solve()<<endl;
    return 0;
}
/*
//AC
#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const ll mod=998244353;
int n,m,k;//1,n,m,k,1e6
ll pf[maxn];
ll f[maxn];
ll solve(){
    pf[0]=1;
    for(int j=1;j<=k;++j){
        if(f[j]) f[j]=pf[j-1]%mod;
        pf[j]=(pf[j-1]+f[j])%mod;
    }
    for(int j=k+1;j<=n;++j){
        if(f[j]) f[j]=(mod+pf[j-1]-pf[j-k-1])%mod;//!!!!!!
        pf[j]=(pf[j-1]+f[j])%mod;
    }
    return f[n]%mod;
}
int main(){
    //ios::sync_with_stdio(false);
    scanf("%d%d%d",&n,&m,&k);
    //cin>>n>>m>>k;
    for(int i=1;i<=n;++i) f[i]=-1;
    //mem(pf,1);
    int tmp;
    for(int i=0;i<m;++i){
        scanf("%d",&tmp);
        //cin>>tmp;
        f[tmp]=0;
    }
    printf("%lld",solve()%mod);
    //cout<<solve(n)%mod<<'\n';
    return 0;
}
*/