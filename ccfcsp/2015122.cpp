/**
 * @file 2015122.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-01-10
 * @version 0.1
 * @brief 
 * @copyright Copyright (c) 2023
 */
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn=31;
int n,m,rec[maxn][maxn];
vector<pair<int,pii>> v;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int l=1,cnt=0,s=0,j=1;
        for(;j<=m;++j){
            cin>>rec[i][j];
            if(rec[i][j]==s) ++cnt;
            else{
                if(cnt>2)
                    v.push_back({i,{l,j-1}});
                l=j;
                cnt=1;
                s=rec[i][j];
            }
        }
        if(cnt>2) v.push_back({i,{l,j-1}});
    }
    for(int j=1;j<=m;++j){
        int l=1,cnt=0,s=0,i=1;
        for(;i<=n;++i){
            if(rec[i][j]==s) ++cnt;
            else{
                if(cnt>2)
                    for(int k=l;k<i;++k) rec[k][j]=0;
                l=i;
                cnt=1;
                s=rec[i][j];
            }
        }
        if(cnt>2) for(int k=l;k<i;++k) rec[k][j]=0;
    }
    for(auto &x:v)
        for(int j=x.second.first;j<=x.second.second;++j)
            rec[x.first][j]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cout<<rec[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}