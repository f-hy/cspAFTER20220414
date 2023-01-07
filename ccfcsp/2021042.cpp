#include<bits/stdc++.h>
using namespace std;
const int maxn=601;
int n,l,r,t;
int b[maxn][maxn];
bool isgray(int i1, int j1, int i2, int j2, int t){
    int sum = b[i2][j2]+b[i1-1][j1-1]-b[i1-1][j2]-b[i2][j1-1];
    int cnt = (j2-j1+1)*(i2-i1+1);
    return sum<=(cnt*t);
}
int main(){
    cin>>n>>l>>r>>t;
    int a;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a;
            b[i][j] = a + b[i][j-1]+b[i-1][j]-b[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int i1 = i-r>0?(i-r):1;
            int j1 = j-r>0?(j-r):1;
            int i2 = i+r<n?(i+r):n;
            int j2 = j+r<n?(j+r):n;
            if(isgray(i1,j1,i2,j2,t)) ++ans;
        }
    }
    cout<<ans;
    return 0;
}