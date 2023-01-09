#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn=1e3+1;
int n,t,m[maxn];
pii p[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t;
        ++m[t];
    }
    int j=0;
    for(int i=1;i<maxn;++i)
        if(m[i]){
            p[j].first=i;
            p[j++].second=m[i];
        }
    sort(p,p+j,
    [](pii a,pii b){
        if(a.second!=b.second)
            return a.second>b.second;
        else return a.first<b.first;
    });
    for(int i=0;i<j;++i)
        cout<<p[i].first<<' '<<p[i].second<<endl;
    return 0;
}