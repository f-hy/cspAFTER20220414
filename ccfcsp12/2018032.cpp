/**
 * @file 2018032.cpp
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
const int maxn=101;
int n,l,t;
pair<int,bool> a[maxn];//position,left?
set<int> cracked;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n>>l>>t;
    rep(i,1,n) cin>>a[i].first;//position
    rep(j,1,t){
        rep(i,1,n){
            if(a[i].first==0)
                a[i]={1,false};
            else if(a[i].first==l)
                a[i]={l-1,true};
            else if(cracked.count(a[i].first)){
                if(a[i].second) a[i]={a[i].first+1,false};
                else a[i]={a[i].first-1,true};
            }else if(a[i].second) a[i]={a[i].first-1,true};
            else a[i]={a[i].first+1,false};
        }
        cracked.clear();
        set<int> tmp;
        rep(i,1,n)
            if(tmp.count(a[i].first)) cracked.insert(a[i].first);
            else tmp.insert(a[i].first);
    }
    rep(i,1,n)
        cout<<a[i].first<<' ';
    return 0;
}