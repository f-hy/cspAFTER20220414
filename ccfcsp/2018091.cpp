/**
 * @file 2018091.cpp
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
const int maxn=1001;
int n,a[maxn];
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    cout<<(a[1]+a[2])/2<<' ';
    rep(i,2,n-1)
        cout<<(a[i-1]+a[i]+a[i+1])/3<<' ';
    cout<<(a[n-1]+a[n])/2<<' ';
    return 0;
}