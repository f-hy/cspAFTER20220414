#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
typedef long long ll;
const int maxn = 2e5+5;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
ll m,p;
ll d[maxn<<2];
ll dishes;
ll pos,value;//将pos位置的值增加value
void upd(ll x=1,ll l=1,ll r=-1){
    if(r==-1) r=m;
    if(l==r){d[x]+=value;return ;}
    ll mid=(l+r)/2;
    if(pos<=mid) upd(x*2,l,mid);
    else upd(x*2+1,mid+1,r);
    //由于孩子被更新，当前节点也要更新
    d[x]=max(d[x*2],d[x*2+1]);
}
ll askm(ll pl,ll pr,ll x=1,ll l=1,ll r=m){//查询[pl,pr]的答案
    //r=(r==-1?mops:r);
    if(pl==l&&pr==r) return d[x];//要查的区间刚好使当前区间，直接返回
    ll mid=(l+r)/2;
    if(pr<=mid) return askm(pl,pr,x*2,l,mid);//要查询的区间完全在左边的区间
    else if(pl>mid)  return askm(pl,pr,x*2+1,mid+1,r);//要查询的区间完全在右边的区间
    else return max(askm(pl,mid,x*2,l,mid),askm(mid+1,pr,x*2+1,mid+1,r));//要查询的区间分布在左右两边，分别计算，合并作为答案
}
int main(){
    ios::sync_with_stdio(false);
    dishes=1;
    //file(data);
    cin>>m>>p;//1,m,2e5; 1,p,2e9; 0,t,p
    char op;ll t;
    ll a=0;//在这个添加操作之前最后一个点菜操作的答案
    for(int i=0;i<m;++i){
        cin>>op>>t;
        if(op=='Q'){//max(L)
            a=askm(dishes-t,dishes-1);
            cout<<a<<'\n';
        }else if(op=='A'){//(t+a)%p
            t=(t+a)%p;
            pos=dishes++;
            value=t;
            upd();
        }
    }
    return 0;
}