#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e4+4;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int n,m;//1,n,m,5e3
int a[maxn],b[maxn];
int f[maxn][maxn];
void solve(){
    f[0][0]=0,f[0][1]=0,f[1][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j]){
                f[i][j]=f[i-1][j-1]+1;
            }else{
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n>>m;
    for(int i=1;i<=n;++i){cin>>a[i];}
    for(int i=1;i<=m;++i){cin>>b[i];}
    solve();
    cout<<f[n][m]<<'\n';
    return 0;
}