#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e9
const ll maxn=1e4+3;
ll n,m;
struct Edge{
    ll v,w,next;
}Edges[2*maxn];
ll head[maxn],tot, cnt[maxn];
void addEdge(ll u,ll v,ll w){
    Edges[tot].v=v;
    Edges[tot].w=w;//u+1,v之间种菜数的限制
    Edges[tot].next=head[u];
    head[u]=tot++;
}
ll dis[maxn],vis[maxn];
void init(ll n){
    tot=0;
    for(ll i=0;i<=n;++i) head[i]=-1;
}
//spfa算法
bool spfa(int s){
    for(int i=0;i<=n;++i) dis[i]=inf,vis[i]=0, cnt[i]=0;
    queue<ll> q;
    q.push(s);
    dis[s]=0;//s记为0
    vis[s]=1;//s在队列中
    while(!q.empty()){
        ll u=q.front();q.pop();
        vis[u]=0;
        for(ll i=head[u];i!=-1;i=Edges[i].next){
            if(dis[Edges[i].v]>dis[u]+Edges[i].w){
                dis[Edges[i].v]=dis[u]+Edges[i].w;//取短边
                cnt[Edges[i].v]++;
                if(cnt[Edges[i].v]>=n) return false;//无解
                if(!vis[Edges[i].v]){
                    q.push(Edges[i].v);
                    vis[Edges[i].v]=1;
                }
            }
        }
    }
    return true;//有解
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;//1,n,m,1e3
    init(n);
    ll k,a,b,c;
    for(int i=0;i<m;++i){
        cin>>k>>a>>b>>c;
        switch(k){
            case 1:{//b-a<=c
                addEdge(a-1,b,c);
                break;
            }
            case 2:{//b-a>=c --> a-b<=-c
                addEdge(b,a-1,-c);
                break;
            }
            case 3:{//b-a<c --> b-a<=c-1
                addEdge(a-1,b,c-1);
                break;
            }
            case 4:{//b-a>c --> a-b<=-c-1
                addEdge(b,a-1,-c-1);
                break;
            }
            case 5:{//b-a=c --> b-a<=c && a-b<=-c
                addEdge(a-1,b,c);
                addEdge(b,a-1,-c);
                break;
            }
        }
    }
    for(int i=1;i<=n;++i){//此外每个坑最多种一瓶酸奶，且不少于0瓶
        addEdge(i-1,i,1);
        addEdge(i,i-1,0);
    }
    if(spfa(0)){//有解
        cout<<dis[n]<<'\n';//dis[n]即为最大值
    }else cout << "impossible";
    return 0;
}
/*
5 5
1 1 4 4
2 2 5 1
3 2 4 2
4 1 5 2
5 1 3 2
*/