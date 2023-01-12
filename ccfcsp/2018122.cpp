//need retry
/**
 * @file 2018122.cpp
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
int r,y,g,n,k,t,turn;
ll ans,tmp;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>r>>y>>g>>n;
    turn=r+y+g;
    rep(i,1,n){//rgy
        cin>>k>>t;
        if(k){
            //相较于rgy开头过去多久
            if(k==1) tmp=ans+r-t;//r
            else if(k==2) tmp=ans+r+g+y-t;//y
            else if(k==3) tmp=ans+r+g-t;//g
            tmp%=turn;//>0
            if(tmp>=r+g) t=y-(tmp-r-g)+r;
            else if(tmp<=r) t=r-tmp;
            else t=0;
        }
        ans+=t;
    }
    cout<<ans;
    return 0;
}