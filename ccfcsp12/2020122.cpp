#include<bits/stdc++.h>
using namespace std;
const int maxm=1e5+1;
const int maxy=1e8+1;
int m;
int pred[maxy];
set<int> ct;
int main(){
    cin>>m;
    ct.insert(1);
    int y,result;
    int my=0;
    for(int i=1;i<=m;++i){
        cin>>y>>result;
        ct.insert(y);
        if(result==0){
            ++pred[y+1];
        }else{
            ++pred[0];
            --pred[y+1];
        }
    }
    int ipred = pred[0];
    int anspred = pred[0];
    int ans=0;
    bool flag=false;
    for(auto &x:ct){
        if(flag){
            ans = x;
            flag=false;
        }
        ipred+=pred[x+1];
        if(anspred<=ipred){
            anspred=ipred;
            flag=true;
            ans=x;
        }
    }
    cout<<ans;
    return 0;
}