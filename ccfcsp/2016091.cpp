/**
 * @file 2016091.cpp
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
#define ite(it,s,e) for(auto it=s,it!=e,++it)
int n,l,ans,m,i;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n>>l;
    rep(i,2,n){
        cin>>m;
        ans=max(ans,abs(l-m));
        l=m;
    }
    cout<<ans;
    return 0;
}