#include<bits/stdc++.h>
using namespace std;
int n,k,t,xl,yd,xr,yu;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    int x,y;
    int cntpass=0,cntstay=0;//经过、逗留计数
    for(int i=1;i<=n;++i){
        int cntrisk=0;//逗留时间计数
        bool judge=false;//若非逗留，则是否经过
        for(int j=1;j<=t;++j){
            cin>>x>>y;
            if(cntrisk>=k) continue;//逗留
            if(x>=xl&&x<=xr&&y>=yd&&y<=yu){//在高危区
                ++cntrisk;
            }else{//不在高危区
                 if(cntrisk>=1){//经过
                    judge=true;
                 }
                cntrisk=0;
            }
        }
        if(cntrisk>=k){//逗留
            ++cntpass;
            ++cntstay;
        }else if(judge||cntrisk>0){//经过
            ++cntpass;
        }
    }
    cout<<cntpass<<endl;
    cout<<cntstay;
    return 0;
}