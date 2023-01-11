/**
 * @file 2017121.cpp
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
int n,m,l,ans=INT_MAX;
multiset<int> ms;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    rep(i,1,n){
        cin>>m;
        ms.insert(m);
    }
    auto it=ms.begin();
    l=*it;
    ++it;
    for(;it!=ms.end();++it){
        ans=min(ans,abs(l-*it));
        l=*it;
    }
    cout<<ans;
    return 0;
}