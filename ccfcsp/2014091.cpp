#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
set<int> s;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>m;
        s.insert(m);
    }
    set<int>::iterator it=s.begin();
    int l=*it;
    ++it;
    for(;it!=s.end();++it){
        if(*it==l+1) ++ans;
        l=*it;
    }
    cout<<ans;
    return 0;
}