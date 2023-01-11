/**
 * @file 2017091.cpp
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
int n,ans;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    n/=10;
    while(n>2){
        if(n>4){
            n-=5;
            ans+=7;
        }else{
            n-=3;
            ans+=4;
        }
    }
    cout<<ans+n;
    return 0;
}