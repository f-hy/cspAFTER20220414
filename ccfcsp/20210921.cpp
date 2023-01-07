// https://blog.csdn.net/weixin_43895428/article/details/123317608
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=5e5+1;
int a[maxn],b[maxn];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]>a[i-1]){
            // a[i-1]~a[i] 之间是以前斜线在该范围内被横切都会产生一个切点，升降数同
            ++b[a[i-1]];
            --b[a[i]];
        }
    }
    int ans=0,t=0;
    for(int i=0;i<maxn;++i){
        t+=b[i];
        ans = max(ans,t);
    }
    cout<<ans;
    return 0;
}