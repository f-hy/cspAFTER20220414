/**
 * @file 2017092.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-01-11
 * @version 0.1
 * @brief csp competition
 * @copyright Copyright (c) 2023
 */
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ite(it,s,e) for(auto it=s;it!=e;++it)
const int maxn=1e3+1;
int n,k,w,s,c,key[maxn],box[maxn];
priority_queue<int,vector<int>, greater<int>> emp;
map<int,multiset<pair<bool,int> > > mmp;
//先挂再取，挂0取1
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n>>k;
    rep(i,1,n)
        key[i]=i;
    rep(i,1,k){
        cin>>w>>s>>c;//1,0
        c+=s;
        if(mmp.count(s)) mmp[s].insert({true,w});
        else mmp[s]=multiset<pair<bool,int> >({{true,w}});
        if(mmp.count(c)) mmp[c].insert({false,w});
        else mmp[c]=multiset<pair<bool,int> >({{false,w}});
    }
    for(auto &mp:mmp){
        for(auto &w:mp.second){
            if(!w.first){//挂
                key[w.second]=emp.top();
                emp.pop();
            }else{//取
                emp.push(key[w.second]);
            }
        }
    }
    rep(i,1,n)
        box[key[i]]=i;
    rep(i,1,n)
        cout<<box[i]<<' ';
    return 0;
}