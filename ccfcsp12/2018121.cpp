/**
 * @file 2018121.cpp
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
int r,y,g,n,k,t,ans;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>r>>y>>g>>n;//rgy
    rep(i,1,n){
        cin>>k>>t;
        switch(k){
            case 0:
            case 1:ans+=t;break;//r
            case 2:ans+=(t+r);break;//y
            case 3:break;//g
            default:break;
        }
    }
    cout<<ans;
    return 0;
}