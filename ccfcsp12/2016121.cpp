/**
 * @file 2016121.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-01-10
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
int n;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    int m;
    rep(i,1,n){
        cin>>m;
        if(mp.count(m)) mp[m]+=1;
        else mp[m]=1;
    }
    int ans=-1;
    int cnt=0;
    ite(it,mp.begin(),mp.end()){
        if(n-2*cnt==it->second) ans=it->first;
        cnt+=it->second;
    }
    cout<<ans;
    return 0;
}