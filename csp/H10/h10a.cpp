#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

int r,y,g;
int n;

int main(){
    ios::sync_with_stdio(false);
    //file(data);
    ll res=0;
    cin>>r>>y>>g;//1e6
    cin>>n;//1e2
    int k,t;//1234,1e6
    while(n--){
        cin>>k>>t;
        switch(k){
            case 0:{
                res+=t;
                break;
            }
            case 1:{//red
                res+=t;
                break;
            }
            case 2:{//yellow
                res+=t+r;
                break;
            }
            case 3:{//green
                break;
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}