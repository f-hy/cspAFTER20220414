#include<bits/stdc++.h>
using namespace std;

int n,m,l;

int main(){
    cin>>n>>m>>l;
    int h[256];
    memset(h,0,sizeof(h));
    int val;
    for(int i=1;i<=n*m;++i){
        cin>>val;
        ++h[val];
    }
    for(int i=0;i<l;++i){
        cout<<h[i]<<' ';
    }
    return 0;
}