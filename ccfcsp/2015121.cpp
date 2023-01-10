#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
    cin>>n;
    while(n>0){
        ans+=n%10;
        n/=10;
    }
    cout<<ans;
    return 0;
}