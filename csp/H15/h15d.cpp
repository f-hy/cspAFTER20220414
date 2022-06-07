#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i, s, t) for(int i=s;i<=t;i++)
#define ite(it,s,e) for(auto it=s,it!=e,++it)

const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const int maxn = 1e6+6;
const int maxN=1e2+2;
ll n,m;
struct Matrix{
    ll x[maxN][maxN];
    Matrix operator*(const Matrix& t){
        Matrix res;
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                for(int k=0;k<m;++k){
                    res.x[i][j]=max(res.x[i][j],x[i][k]+t.x[k][j]);
                }
            }
        }
        return res;
    }
    //强烈建议实现构造函数和复制构造函数以避免出现奇怪的bug
    Matrix(){memset(x,0,sizeof(x));}
    Matrix(const Matrix& t){memcpy(x,t.x,sizeof(x));}
};
Matrix quick_pow(Matrix a,ll x){
    Matrix I;
    for(int i=0;i<m;++i){I.x[i][i]=1;}
    I=a;
    while(x){
        if(x&1){I=I*a;}
        a=a*a;
        x>>=1;
    }
    return I;
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n>>m;
    Matrix coe;
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            cin>>coe.x[i][j];
        }
    }
    Matrix mat(quick_pow(coe,n-2));
    ll res=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            res=max(res,mat.x[i][j]);
        }
    }
    cout<<res<<'\n';
    return 0;
}