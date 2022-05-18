#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

int n,q;//1,n,q,1e6
vector<ll> s(maxn);
#define lb(x) (x&-x)
ll ask(int x){//get d[1:x]
    ll res=0;
    for(int i=x;i>=1;i-=lb(i))
        res+=s[i];
    return res;
}
void upd(int x,int v){//将d[x]的值增加 v: x 所有祖先节点+v
    for(int i=x;i<=n;i+=lb(i))
        s[i]+=v;
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    vector<ll> x(maxn,0);
    cin>>n>>q;
    s[0]=0;
    int tmp;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        upd(i,tmp);
    }
    int a,b,c;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            upd(b,c);
        }else{
            cout<<ask(c)-ask(b-1)<<'\n';
        }
    }
    return 0;
}