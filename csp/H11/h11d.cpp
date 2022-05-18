#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int n;
int bit[maxn];
int f[maxn];
int lowbit(int x){return x&-x;}
void upd(int x,int val){
    while(x<=maxn){
        bit[x]=max(bit[x],val);
        x+=lowbit(x);
    }
}
int query(int x){
    int res=0;
    while(x){
        res=max(res,bit[x]);
        x-=lowbit(x);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    int tmp;
    int res=0;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        f[i]=query(tmp-1)+1;
        upd(tmp,f[i]);
        res=max(res,f[i]);
    }
    cout<<res<<'\n';
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MOD 998244353
#define MAXN 1000010
#define INF 0x3f3f3f3f
using namespace std;
vector<int> a;
int len = 0;
int dp[MAXN];//记录长度为i的上升子串末尾元素的最小值
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (dp[len] < temp) dp[++len] = temp;
        else {
            int j = lower_bound(dp, dp + len,temp)-dp;
            dp[j] = temp;
        }
    }
    cout << len << endl;

    return 0;
}
*/