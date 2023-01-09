#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
int n,m,rec[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>rec[i][j];
    for(int j=m;j>=1;--j){
        for(int i=1;i<=n;++i){
            cout<<rec[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}