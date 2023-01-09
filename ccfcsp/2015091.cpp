#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
    cin>>n;
    int l=-1;
    for(int i=1;i<=n;++i){
        cin>>m;
        if(m!=l){
            ++ans;
            l=m;
        }
    }
    cout<<ans;
    return 0;
}