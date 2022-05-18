#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int n;
int a[3][maxn];
ll dp[3][maxn];
ll min(ll a,ll b){return a<b?a:b;}
ll min(ll a,ll b,ll c){return min(a,min(b,c));}
void fun(){
    dp[0][0]=0,dp[1][0]=0,dp[2][0]=0;
    for(int i=1;i<n;++i){
        for(int j=0;j<3;++j){
            dp[j][i]=min(
                dp[0][i-1]+abs(a[j][i]-a[0][i-1]),
                dp[1][i-1]+abs(a[j][i]-a[1][i-1]),
                dp[2][i-1]+abs(a[j][i]-a[2][i-1])
            );
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    memset(dp,inf,sizeof(dp));
    for(int i=0;i<3;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    fun();
    cout<<min(dp[0][n-1],dp[1][n-1],dp[2][n-1])<<'\n';
    return 0;
}