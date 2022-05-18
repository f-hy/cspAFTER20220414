#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;//书的数目,暑假的天数
    //w：各书的重量，d：各天要读的书，pre：各书上一次读的时间
    vector<int> w(n),d(m),pre(n+1,-1);
    for(auto &x:w) cin>>x;//读入各书的各天要读的书重量
    for(auto &x:d) cin>>x;//读入各天要读的书
    ll res=0;//结果
    for(int i=0;i<m;++i){//m天逐个遍历
        for(int j=1;j<=n;++j)
            if(pre[j]>pre[d[i]])//第i天时在d[i]本书上一次读的时间之后读的书
                res+=w[j-1];//需要耗费第j本书重量的力气w[j-1]
        pre[d[i]]=i;//重新标记第d[i]本书读的时间
    }
    cout<<res<<'\n';
    return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define inf 1e16;
const ll maxn=1e5;
ll n,m;//n books, m days
ll wei[maxn];//weight
ll d[maxn];//date for which book
ll read(deque<ll> s){//O(km)
    ll res=0;
    for(ll i=1;i<=m;++i){
        ll j=1;
        for(;j<=m&&d[i]!=s.at(j-1);++j){
            res+=wei[s.at(j-1)];
        }
        ll tmp=s.at(j-1);
        s.erase(s.begin()+j-1);
        s.push_front(tmp);
    }
    return res;
}
ll res;
void perm(ll list[],ll st,ll en){//Arrangement
    if(st==en){
        deque<ll> deq(list+1,list+n+1);
        ll tmp=read(deq);
        res=res>tmp?tmp:res;
    }else{
        for(ll i=st;i<=en;++i){
            ll tmp=list[i];
            list[i]=list[st];
            list[st]=tmp;
            perm(list,i+1,en);
            list[st]=list[i];
            list[i]=tmp;
        }
    }
}
int main(){
    cin>>n>>m;
    res=inf;
    ll lis[maxn];
    for(ll i=1;i<=n;++i){
        cin>>wei[i];
        lis[i]=i;
    }
    for(int i=1;i<=m;++i){
        cin>>d[i];
    }
    perm(lis,1,n+1);
    cout<<res<<endl;
    return 0;
}
*/