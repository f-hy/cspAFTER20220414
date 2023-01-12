/**
 * @file 20160421.cpp
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
bool screen[16][11];
int col;
pii block[4];
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    int i,j,t=0,tmp;
    rep(i,1,15)
        rep(j,1,10)
            cin>>screen[i][j];
    rep(i,1,4)
        rep(j,1,4){
            cin>>tmp;
            if(tmp)
                block[t++]={i,j};
        }
    cin>>col;
    rep(i,0,3) block[i].second+=(col-1);
    rep(i,0,15)
        if(i+block[3].first>15||
        screen[i+block[0].first][block[0].second]||
        screen[i+block[1].first][block[1].second]||
        screen[i+block[2].first][block[2].second]||
        screen[i+block[3].first][block[3].second]){
            --i;
            screen[i+block[0].first][block[0].second]=true;
            screen[i+block[1].first][block[1].second]=true;
            screen[i+block[2].first][block[2].second]=true;
            screen[i+block[3].first][block[3].second]=true;
            break;
        }
    rep(i,1,15){
        rep(j,1,10)
            cout<<screen[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}