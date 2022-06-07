#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i, s, t) for(int i=s;i<=t;i++)
#define ite(it,s,e) for(auto it=s,it!=e,++it)
const ll mod=998244353;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const int maxn = 1e6+6;
struct Matrix{
    ll x[3][3];
    Matrix operator*(const Matrix& t)const{
        Matrix res;
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                res.x[i][j]=0;
                for(int k=0;k<3;++k){
                    res.x[i][j]+=x[i][k]*t.x[k][j];
                    if(mod){
                        res.x[i][j]%=mod;
                    }
                }
            }
        }
        return res;
    }
    //强烈建议实现构造函数和复制构造函数以避免出现奇怪的bug
    Matrix(){memset(x,0,sizeof(x));}
    Matrix(bool flag){x[0][0]=x[1][1]=x[0][2]=x[1][2]=x[2][2]=1;x[1][0]=x[0][1]=0;x[2][0]=x[2][1]=2;}
    Matrix(const Matrix& t){memcpy(x,t.x,sizeof(x));}
};
Matrix quick_pow(Matrix a,int x){
    Matrix I;
    memset(I.x,0,sizeof(I.x));
    for(int i=0;i<3;++i){I.x[i][i]=1;}
    Matrix res(I);
    while(x){
        if(x&1){res=res*a;}
        a=a*a;
        x>>=1;
    }
    return res;
}
ll n;
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    int T;cin>>T;
    while(T--){
        cin>>n;
        Matrix coe(true);
        Matrix mat=quick_pow(coe,n-1);
        ll res=mat.x[0][0]%mod;
        res=(res+2*mat.x[0][2])%mod;
        cout<<res<<'\n';
    }
    return 0;
}