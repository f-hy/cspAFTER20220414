#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,ans;
bool rec[maxn][maxn];
int main(){
    cin>>n;
    int x1,x2,y1,y2,tmp;
    for(int i=1;i<=n;++i){
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1;x<x2;++x)
            for(int y=y1;y<y2;++y)
                rec[x][y]=true;
    }
    for(int i=0;i<maxn;++i)
        for(int j=0;j<maxn;++j)
            if(rec[i][j])
                ++ans;
    cout<<ans;
    return 0;
}