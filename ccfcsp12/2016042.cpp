/**
 * @file 2016042.cpp
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
bool screen[16][11],rec[5][5];//初始方格图，新加入的版块
int col,scr[11],d[5];//哪一列，方格图各列最上面行号，板块最下面行号
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    int i,j;
    rep(i,1,15)
        rep(j,1,10){
            cin>>screen[i][j];
            if(screen[i][j]&&!scr[j]) scr[j]=i;//0,[5,15]
        }
    rep(i,1,4)
        rep(j,1,4){
            cin>>rec[i][j];
            if(rec[i][j]) d[j]=i;//[0,4]
        }
    cin>>col;
    rep(i,col,col+3){//=>相当于scr[5,16]
        int tmp=i-col+1;
        if(!d[tmp]) d[tmp]=INT_MIN;
        else if(scr[i]) d[tmp]-=scr[i];
        else d[tmp]-=16;//方格图整列无方块
    }
    int dd=-16;
    rep(i,1,4)
        if(dd<d[i]) dd=d[i];//取d大值 [-16,-1]
    rep(i,1,4)
        rep(j,1,4)
            screen[i-dd-1][col+j-1]|=rec[i][j];
    rep(i,1,15){
        rep(j,1,10)
            cout<<screen[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}