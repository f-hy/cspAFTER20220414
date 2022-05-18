#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+6;
const ll maxm=1e6+6;
ll n,m;
struct Edge{
    ll v,next;
}Edges[2*maxn];
ll head[maxn],tot;
void addEdge(ll u,ll v){
    Edges[tot].v=v;
    Edges[tot].next=head[u];
    head[u]=tot++;
}
ll ine[maxn];
void init(ll n){
    tot=0;
    for(ll i=1;i<=n;++i) ine[i]=0,head[i]=-1;
}
void toposort(){
    priority_queue<ll,vector<ll>,greater<ll> > q;
    for(int i=1;i<=n;++i)
        if(ine[i]==0) q.push(i);
    while(!q.empty()){
        ll u=q.top();
        q.pop();
        cout<<u<<' ';
        for(ll i=head[u];i!=-1;i=Edges[i].next){
            if(--ine[Edges[i].v]==0) q.push(Edges[i].v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    ll a,b;
    init(n);
    for(ll i=0;i<m;++i){
        cin>>a>>b;
        addEdge(a,b);
        ++ine[b];
    }
    toposort();
    return 0;
}