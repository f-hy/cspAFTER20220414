#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int maxn = 4e1+2;
const ll maxv = 1e15+15;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

ll w[maxn],c[maxn];
ll N,V;
const ll maxl=1<<(maxn/2); //N/2的最大组合数
pll group1[maxl]; //组1
pll group2[maxl]; //组2
pll tmp[maxl]; //替换用
bool cmps(pll& a,pll& b){return a.second<b.second;}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>N>>V;
    for(int i=0;i<N;++i){
        cin>>w[i]>>c[i];
    }
    ll n=N>>1;// 将物品分成两组，每组 N/2 个物品
    ll pn=1<<n;// 2^n种排列
    for(ll i=0;i<pn;++i){//group1[i]: i的第j位为1则选取第j个物体，否则不选
        ll now_w=0,now_v=0;
        for(int j=0;j<n;++j){
            if(i>>j&1){ //若二进制数i的第j位是1
                now_w+=w[j];
                now_v+=c[j];
            }
        }
        group1[i]=pll{now_w,now_v}; //二进制数i表示当前选中的状态，对这个状态来计算当前的价值和重量
    }//group1得到这n(前N/2)个物体的取否的排列组合，有2^n种
    sort(group1,group1+pn); //weight升序
    ll curmin=group1[0].second;//min_w对应v
    ll j=0; //替换次数
    for(ll i=1;i<pn;++i){
        // 如果a[i].w1>a[j].w1，且a[i].v1<a[j].v1，那么a[i]就可以舍去，因为a[j]更“物美价廉”
        if(group1[i].second>curmin) group2[j++]=group1[i]; //选取价值更大的
        else curmin=group1[i].second; //否则更换比较价值
    }
    ll res=0;
    ll nn=N-n;
    for(ll i=0;i<(1ll<<nn);++i){
        ll now_w=0,now_v=0;
        for(ll k=0;k<nn;++k){ //若二进制数i的第k位是1
            if(i>>k&1){
                now_w+=w[n+k];
                now_v+=c[n+k];
            }
        }// 得到一个剩下的N-n个物品取否的组合，now_w为该组合weight，now_v为该组合value
        if(now_w<=V){
            ll v=0; //最优结果用
            for(ll k=j-1;k>=0;--k){// 替换组合的枚举
                if(group2[k].first<=V-now_w){ //替换在背包承受范围内
                    for(int l=0;l<=k;++l) tmp[l]=group2[l];
                    sort(tmp,tmp+k+1,cmps); //value升序
                    v=tmp[k].second;
                    break;
                }
            }
            res=max(res,v+now_v); //取更优结果
        }
    }
    cout<<res;
    return 0;
}