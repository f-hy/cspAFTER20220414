//AC
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+6;
ll n,m;
ll c[maxn],dfn[maxn],vis[maxn],dcnt,scnt;
/*
dcnt	dfs序计数
scnt	scc计数
dfn[i]	dfs后序列中第i个点
c[i]	i号所在scc编号
vis[i]  i号遍历情况
*/
vector<ll> G1[maxn],G2[maxn],E[maxn];//G1原图，G2反图,E缩点后的原图边
ll sz[maxn],d[maxn];
/*
sz[i]   缩点后第i个点内所含的点数   没用到
d[i]    缩点后各点的入度数
*/
void dfs1(int x){
    vis[x]=1;
    for(auto y:G1[x])
        if(!vis[y]) dfs1(y);
    dfn[++dcnt]=x;
}
void dfs2(int x){
    c[x]=scnt;//scc计数
    for(auto y:G2[x])
        if(!c[y]) dfs2(y);
}
void kosaraju(){//O(m+n)
    dcnt=scnt=0;//初始化
    memset(c,0,sizeof(c));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i)//第一遍dfs
        if(!vis[i]) dfs1(i);
    for(int i=n;i>=1;--i)//第二遍dfs
        if(!c[dfn[i]]) ++scnt,dfs2(dfn[i]);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    ll a,b;
    while(m--){//原图反图数据插入
        cin>>a>>b;
        G1[a].push_back(b);
        G2[b].push_back(a);
    }
    kosaraju();
    memset(sz,0,sizeof(sz));
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;++i){//缩点后的图的重构
        ++sz[c[i]];
        for(auto v:G1[i])
            if(c[i]!=c[v])//避免出现自环
                E[c[i]].push_back(c[v]);//为缩点后的新图添加边，可能会有重复边
    }
    for(int i=1;i<=scnt;++i){//缩点操作，去除重复边
        sort(E[i].begin(),E[i].end());//对点i连向的点进行排序
        vector<ll>::iterator new_end;
        new_end=unique(E[i].begin(),E[i].end());//用unique去重
        E[i].erase(new_end,E[i].end());//删除重复的点
        for(auto v:E[i]) ++d[v];//去重后的边可以应用于图论
    }
    ll res=0;//结果计数
    for(int i=1;i<=scnt;++i)
        if(d[i]==0)//入度为0的点即为需要告诉的人
            ++res;
    cout<<res<<'\n';
    return 0;
}
/*
dfn     3198542670
rdfn    0762458913
scc/c   6474432541
sz      1114111
*/