/**
 * @file 2019031.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-01-12
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
const int maxn=1e5+1;
int n,m,a[maxn];
float mid;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    cout<<max(a[1],a[n])<<' ';
    if(n%2==0){
        mid=(a[n/2]+a[n/2+1])/2.0;
        if(mid==(int)mid) cout<<(int)mid<<' ';
        else cout<<fixed<<setprecision(1)<<mid<<' ';
    }
    else cout<<a[n/2+1]<<' ';
    cout<<min(a[1],a[n]);
    return 0;
}