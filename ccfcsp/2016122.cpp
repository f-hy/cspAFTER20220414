/**
 * @file 2016122.cpp
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
int t,shuihoumax[7];
int shuiqian[8] = {0,3500,1500,4500,9000,35000,55000,80000};
float shuilv[8] = {1,0.97,0.90,0.80,0.75,0.70,0.65,0.55};
int cntget(int x){
    int res=0;
    rep(i,1,8){
        if(x<=shuiqian[i]) return res+(x-shuiqian[i-1])*shuilv[i-1];
        res+=(shuiqian[i]-shuiqian[i-1])*shuilv[i-1];
    }
    return res+(x-shuiqian[7])*shuilv[7];
}
int getshuiqian(int x){
    int res=0;
    rep(i,0,6){
        if(x<=shuihoumax[i]) return shuiqian[i]+(x-shuihoumax[i-1])/shuilv[i];
    }
    return shuiqian[7]+(x-shuihoumax[6])/shuilv[7];
}
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>t;
    rep(i,2,7) shuiqian[i]+=shuiqian[1];
    rep(i,0,6) shuihoumax[i]=cntget(shuiqian[i+1]);
    cout<<getshuiqian(t);
    return 0;
}