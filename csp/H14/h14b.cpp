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
const int maxn = 5e4+4;
ll min(ll a,ll b){return a<b?a:b;}
int n,m,k;//n<=5e4,m<=1e4,k<=1e2
struct Edge{
    int v,next;
    ll w;
}Edges[maxn<<1];
int tot;
int head[maxn];
void init(int n){
    tot=0;
    for(int i=1;i<=n;++i) head[i]=-1;
}
void addEdge(int u,int v,int w){
    Edges[tot].v=v;
    Edges[tot].w=w;
    Edges[tot].next=head[u];
    head[u]=tot++;
}
vector<bool> vital(maxn,false);
int cnt[maxn];
vector<vector<ll>> f(maxn,vector<ll>(1e2+2,inf));
void dfs(int u,int far){
    f[u][0]=0;
    int i,j,l;
    if(vital[u]){
        f[u][1]=0;
        cnt[u]=1;
    }
    for(int i=head[u];i!=-1;i=Edges[i].next){
        int v=Edges[i].v;
        if(v==far){continue;}
        dfs(v,u);
        cnt[u]+=cnt[v];
        for(j=min(k,cnt[u]);j>=1;--j){//
            for(l=1;l<=j&&l<=min(k,cnt[v]);++l){//
                f[u][j]=min(f[u][j],f[v][l]+f[u][j-l]+1ll*l*(k-l)*Edges[i].w);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n>>m>>k;
    init(n);
    int u,v,w;
    for(int i=0;i<m;++i){cin>>u;vital[u]=true;}
    for(int i=1;i<n;++i){
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    dfs(1,-1);
    cout<<f[1][k];
    return 0;
}