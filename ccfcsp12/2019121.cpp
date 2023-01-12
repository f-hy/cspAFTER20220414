#include<bits/stdc++.h>
using namespace std;
const int maxn=666;
int n,ans[4];
int main(){
    cin>>n;
    int i=1;
    while(i<=n){
        if(i%7==0||i%10==7||i/10%10==7||i/100==7){
            ++ans[i%4];
            ++n;
        }
        ++i;
    }
    // for(int i=1;i<=n;++i){
    //     if(i%7==0||i%10==7||i/10%10==7||i/100==7){
    //         ++ans[i%4];
    //         ++n;
    //     }
    // }
    cout<<ans[1]<<endl;
    cout<<ans[2]<<endl;
    cout<<ans[3]<<endl;
    cout<<ans[0];
    return 0;
}