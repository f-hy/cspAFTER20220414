/**
 * @file 2018031.cpp
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
int score,ans,cnt;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    //scanf("%d", score)!=EOF
    cin>>score;
    while(score){
        if(score==1)
            cnt=1;
        else if(cnt>1)
            cnt+=2;
        else
            cnt=2;
        ans+=cnt;
        cin>>score;
    }
    cout<<ans;
    return 0;
}