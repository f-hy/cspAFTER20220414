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
const int maxn = 1e5+5;
int n;//0,n,1e5
struct Edge{
    int v,w,next;
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
int maxd=-inf,dk=0;
vector<int> far(maxn,0);//max depth
int cntf[maxn];//最长边的个数
void dfs(int u,int f){//f: farther node
    int i,v,tmp;
    far[u]=0;
    cntf[u]=1;
    int m1=0,m2=0;
    for(i=head[u];i!=-1;i=Edges[i].next){
        v=Edges[i].v;
        if(v==f){continue;}//if v is its parent node, then continue
        dfs(v,u);//another part
        tmp=far[v]+Edges[i].w;//depth of u->v direction
        if(tmp+far[u]>maxd){//refresh maxd and dk
            dk=cntf[v]*cntf[u];
            maxd=tmp+far[u];
        }else if(tmp+far[u]==maxd){
            dk+=cntf[v]*cntf[u];
        }
        if(far[u]<tmp){//refresh far[u]
            far[u]=tmp;
            cntf[u]=cntf[v];
        }else if(far[u]==tmp){
            cntf[u]+=cntf[v];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    int a,b;
    init(n);
    for(int i=1;i<n;++i){
        cin>>a>>b;
        addEdge(a,b,1);
        addEdge(b,a,1);
    }
    dfs(1,0);
    cout<<maxd<<' '<<dk<<'\n';
    return 0;
}
/*
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
const int maxn = 1e5+5;
int n;//0,n,1e5
struct Edge{
    int v,w,next;
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
int maxd=-inf,dk=0;
vector<int> far(maxn,0);
int len[maxn],node[maxn];
void dfs(int u,int f){//f: farther node
    int i,v,tmp;
    len[u]=0;
    node[u]=1;
    int m1=0,m2=0;
    for(i=head[u];i!=-1;i=Edges[i].next){
        v=Edges[i].v;
        if(v==f){continue;}//parent节点
        dfs(v,u);
        tmp=len[v]+Edges[i].w;
        if(tmp+len[u]>maxd){
            dk=node[v]*node[u];
            maxd=tmp+len[u];
        }else if(tmp+len[u]==maxd){
            dk+=node[v]*node[u];
        }
        if(len[u]<tmp){
            len[u]=tmp;
            node[u]=node[v];
        }else if(len[u]==tmp){
            node[u]+=node[v];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    int a,b;
    init(n);
    for(int i=1;i<n;++i){
        cin>>a>>b;
        addEdge(a,b,1);
        addEdge(b,a,1);
    }
    dfs(1,0);
    cout<<maxd<<' '<<dk<<'\n';
    return 0;
}
*/