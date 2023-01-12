#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;

int n;
int main(){
    cin>>n;
    int w,score;
    int sum=0;
    for(int i=1;i<=n;++i){
        cin>>w>>score;
        sum+=w*score;
    }
    cout<<max(0,sum)<<endl;
    return 0;
}