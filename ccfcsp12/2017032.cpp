/**
 * @file 2017032.cpp
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
#define ite(it,s,e) for(auto it=s;it!=e;++it)
const int maxn=1001;
int n,m,p,q;
deque<int> dq;
int findp(int p){
    deque<int>::iterator it=dq.begin();
    rep(i,0,n-1)
        if(*it==p) return i;
        else ++it;
}
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n>>m;
    rep(i,1,n)
        dq.push_back(i);
    rep(i,1,m){
        cin>>p>>q;
        int posi=findp(p);
        int pos=posi+q;
        dq.erase(dq.begin()+posi);
        if(pos<=0)//move to head
            dq.push_front(p);
        else if(pos>=n-1)
            dq.push_back(p);
        else
            dq.insert(dq.begin()+pos,p);
    }
    for(auto &x:dq)
        cout<<x<<' ';
    return 0;
}