/**
 * @file 2018092.cpp
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
const int maxn=2001;
int n,c,d,ans;
pii ab[maxn];
map<int,int> mab;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    rep(i,1,n){
        cin>>ab[i].first>>ab[i].second;
        mab[ab[i].first]=i;
        mab[ab[i].second]=i;
    }
    rep(j,1,n){
        cin>>c>>d;
        auto lb=mab.lower_bound(c);
        while(lb!=mab.end()&&d>ab[lb->second].first){
            if(d<=ab[lb->second].second){
                ans+=(d-max(c,ab[lb->second].first));
                break;
            }else{
                ans+=(ab[lb->second].second-max(c,ab[lb->second].first));
                c=ab[lb->second].second;
                lb=mab.upper_bound(c);
            }
        }
        // if(lb==mab.end()) break;//
        // int i=lb->second;
        // if(d<ab[i].first) continue;//
        // if(d<=ab[i].second) ans+=(d-max(ab[i].first,c));//
        // else{
        //     ans+=(ab[i].second-max(ab[i].first,c));//
        //     while(d>ab[i].second){
        //         c=ab[i++].second;
        //         auto ub=mab.upper_bound(c);
        //         if(ub==mab.end()) break;//
        //         if(d<ab[i].first) break;//
        //         if(d<=ab[i].second) ans+=(d-max(ab[i].first,c));//
        //         else ans+=(ab[i].second-ab[i].first);//
        //     }
        // }
    }
    cout<<ans;
    return 0;
}