/**
 * @file 2016092.cpp
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
const int maxn=101;
int n,need,cx[20];
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    int i,j;
    rep(i,1,n){
        cin>>need;
        bool get=false;
        rep(j,0,19){
            if(cx[j]+need<6){
                rep(k,cx[j]+1,cx[j]+need)
                    cout<<k+j*5<<' ';
                cout<<endl;
                cx[j]+=need;
                get=true;
                break;
            }
        }
        if(!get){
            int j=0;
            while(need>0){
                if(cx[j]<6){
                    rep(k,cx[j]+1,min(cx[j]+need,5))
                        cout<<k+j*5<<' ';
                    need-=(5-cx[j]);
                    cx[j]=need+5;
                    if(need<=0) break;
                }
                ++j;
            }
        }
    }
    return 0;
}