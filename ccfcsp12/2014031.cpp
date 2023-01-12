#include<bits/stdc++.h>
using namespace std;
set<int> s;
int n,m,ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>m;
        if(m<0) m=-m;
        if(s.count(m)) ++ans;
        else s.insert(m);
    }
    cout<<ans;
    return 0;
}