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
const int maxn = 5e3+3;
const int mod = 1e9+7;
int n,a,b,k;
vector<ll> pre(maxn);//前缀和
vector<vector<ll>> arr(2,vector<ll>(maxn));//滚动数组

int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n>>a>>b>>k;
    if(k==0){
        cout<<"0\n";
        return 0;
    }
    arr[k&1][a]=1;
    for(int i=a;i<=n;++i){pre[i]=1;}
    while(k--){
        for(int i=1;i<=n;++i){
            if(i>b){//在b楼之上
                arr[k&1][i]=pre[n]-pre[(i+b)/2];
            }else if(i<b){//在b楼之下
                arr[k&1][i]=pre[(i+b-1)/2]-pre[0];
            }
            arr[k&1][i]-=arr[(k+1)&1][i];
            arr[k&1][i]=(arr[k&1][i]+mod)%mod;
        }
        for(int i=0;i<=n;++i){//刷新前缀和
            pre[i]=(arr[k&1][i]+pre[i-1])%mod;
        }
    }
    ll res=0;
    for(int i=1;i<=n;++i){res=(res+arr[0][i])%mod;}//获取结果
    cout<<res<<'\n';
    return 0;
}