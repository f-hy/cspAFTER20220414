#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn=1e3+1;
int n,m,t;
int main(){
    cin>>n>>m;
    int val;
    int num=1,maxval=0;
    for(int i=1;i<=n;++i){
        cin>>val;
        t+=val;
        int cnt=0;
        for(int j=1;j<=m;++j){
            cin>>val;
            cnt+=val;
        }
        t+=cnt;
        if(cnt<maxval){
            maxval=cnt;
            num=i;
        }
    }
    cout<<t<<' '<<num<<' '<<-maxval<<endl;
    return 0;
}