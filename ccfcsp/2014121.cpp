#include<bits/stdc++.h>
using namespace std;

int n;
map<int,int> m;
int main(){
    cin>>n;
    int t;
    for(int i=1;i<=n;++i){
        cin>>t;
        if(m.count(t)){
            m[t]=m[t]+1;
            cout<<m[t]<<' ';
        }else{
            m[t]=1;
            cout<<1<<' ';
        }
    }
    return 0;
}