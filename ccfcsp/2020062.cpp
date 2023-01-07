#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
const int maxn=1e9+1;
const int maxa=5e5;
int n,a,b;
map<int,int> valu;
int main(){
    cin>>n>>a>>b;
    int idx,val;
    ll res=0;
    for(int i=1;i<=a;++i){
        cin>>idx>>val;
        valu[idx]=val;
    }
    for(int i=1;i<=b;++i){
        cin>>idx>>val;
        if(valu.count(idx)){
            res+=valu[idx]*val;
        }
    }
    cout<<res<<endl;
    return 0;
}