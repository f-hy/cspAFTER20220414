#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const int maxn = 1e2+2;
const int maxnl=maxn<<1;
int n;//1,n,1e2
ll sum0[maxnl];//前缀和
vector<vector<ll>>  smin(maxnl,vector<ll>(maxnl,linf)),//min of f
                    smax(maxnl,vector<ll>(maxnl,0));//max of f
ll sum(int i,int j){return sum0[j]-sum0[i-1];}//获取[i,j]的石子的数量和
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    int tmp;
    sum0[0]=0;
    for(int i=1;i<=n;++i){//获取的石子的数量，并得到1~n的前缀和
        cin>>tmp;
        sum0[i]=sum0[i-1]+tmp;
    }
    for(int i=n+1;i<=2*n;++i){//得到n+1~2n的前缀和
        sum0[i]=sum0[n]+sum0[i-n];
    }
    for(int i=1;i<=2*n;++i){//f[i][i]值为0
        smin[i][i]=0;
        smax[i][i]=0;
    }
    for(int len=2;len<=n;++len){//长度由2向n遍历
        for(int l=1;l<=2*n-len+1;++l){//左端由1向2n-len+1遍历
            int r=l+len-1;//右端
            for(int k=l;k<r;++k){//r-l种情况取最佳方案
                smin[l][r]=min(smin[l][r],smin[l][k]+smin[k+1][r]+sum(l,r));
                smax[l][r]=max(smax[l][r],smax[l][k]+smax[k+1][r]+sum(l,r));
            }
        }
    }
    ll resmin=linf;//result min f
    ll resmax=0;//result max f
    for(int i=1;i<=n;++i){//n个结果比较得到最值
        resmin=min(resmin,smin[i][i+n-1]);
        resmax=max(resmax,smax[i][i+n-1]);
        //resmin=resmin<smin[i][i+n]?resmin:smin[i][i+n-1];
        //resmax=resmax>smax[i][i+n]?resmax:smax[i][i+n-1];
    }
    cout<<resmin<<"\n"<<resmax<<"\n";//输出结果
    return 0;
}