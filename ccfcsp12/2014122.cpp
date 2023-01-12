#include<bits/stdc++.h>
using namespace std;
const int maxn=501;
int n,rec[maxn][maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>rec[i][j];
        }
    }
    int i=1,j=1;
    bool up=false;
    if(n%2){
        while(i!=n||j!=n){
            cout<<rec[i][j]<<' ';
            if(i==n){
                if(j%2){
                    up=true;
                    --i;
                }
                ++j;
            }else if(j==n){
                if(!(i%2)){
                    --j;
                    up=false;
                }
                ++i;
            }else if(i==1){
                if(j%2){
                    ++j;
                }else{
                    --j;
                    ++i;
                    up=false;
                }
            }else if(j==1){
                if(i%2){
                    --i;
                    ++j;
                }else{
                    ++i;
                    up=true;
                }
            }else if(up){
                --i;
                ++j;
            }else{
                ++i;
                --j;
            }
        }
    }else{
        while(i!=n||j!=n){
            cout<<rec[i][j]<<' ';
            if(i==n){
                if(!(j%2)){
                    up=true;
                    --i;
                }
                ++j;
            }else if(j==n){
                if(i%2){
                    --j;
                    up=false;
                }
                ++i;
            }else if(i==1){
                if(j%2){
                    ++j;
                }else{
                    --j;
                    ++i;
                    up=false;
                }
            }else if(j==1){
                if(i%2){
                    --i;
                    ++j;
                }else{
                    ++i;
                    up=true;
                }
            }else if(up){
                --i;
                ++j;
            }else{
                ++i;
                --j;
            }
        }
    }
    cout<<rec[n][n];
    return 0;
}