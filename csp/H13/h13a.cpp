#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const int maxn = 1e2+2;
const int maxnl=maxn<<1;
int n;//1,n,1e2
ll sum0[maxnl];
vector<vector<ll>>  smin(maxnl,vector<ll>(maxnl,linf)),
                    smax(maxnl,vector<ll>(maxnl,0));
ll sum(int i,int j){return sum0[j]-sum0[i-1];}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    int tmp;
    sum0[0]=0;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        sum0[i]=sum0[i-1]+tmp;
    }
    for(int i=n+1;i<=2*n;++i){
        sum0[i]=sum0[n]+sum0[i-n];
    }
    for(int i=1;i<=2*n;++i){
        smin[i][i]=0;
        smax[i][i]=0;
    }
    for(int len=2;len<=n;++len){
        for(int l=1;l<=2*n-len+1;++l){
            int r=l+len-1;
            for(int k=l;k<r;++k){
                smin[l][r]=min(smin[l][r],smin[l][k]+smin[k+1][r]+sum(l,r));
                smax[l][r]=max(smax[l][r],smax[l][k]+smax[k+1][r]+sum(l,r));
            }
        }
    }
    ll resmin=linf;
    ll resmax=0;
    for(int i=1;i<=n;++i){
        resmin=min(resmin,smin[i][i+n-1]);
        resmax=max(resmax,smax[i][i+n-1]);
        //resmin=resmin<smin[i][i+n]?resmin:smin[i][i+n-1];
        //resmax=resmax>smax[i][i+n]?resmax:smax[i][i+n-1];
    }
    cout<<resmin<<"\n"<<resmax<<"\n";
    return 0;
}