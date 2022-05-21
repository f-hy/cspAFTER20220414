#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const int maxn = 1e1+1;
const int maxne=1<<maxn;
int h,w;//1,h,w,1e1+1
vector<vector<ll>> f(maxne,vector<ll>(maxne,0));
bool check(int s){
    int cnt=0;
    for(int i=0;i<w;++i){
        if(s&(1<<i)){
            if(cnt%2) return false;
            cnt=0;
        }else{
            ++cnt;
        }
    }
    if(cnt%2) return false;
    else return true;
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>h>>w;
    f[0][0]=1;
    
    for(int i=1;i<=h;++i){
        for(int s=0;s<(1<<w);++s){
            for(int ss=0;ss<(1<<w);++ss){
                if((s&ss)!=0) continue;//邻行同列不同时为1
                if(!check(s|ss)) continue;//
                f[i][s]+=f[i-1][ss];
            }
        }
    }
    cout<<f[h][0];//(1<<w)-1
    return 0;
}