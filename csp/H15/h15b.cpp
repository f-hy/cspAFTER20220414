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
ll mod=1e9+7;
const int maxk=10;
int n,k;
ll cres[67][67]={0};//存储组合数
ll C(ll _n,ll _m){//求组合数
    if(_m<=0||_m==_n)return 1;
    if(cres[_n][_m]!=0)return cres[_n][_m];
    return cres[_n][_m]=C(_n-1,_m)+C(_n-1,_m-1);//赋值给res[n][m]并返回
}
const int maxN=maxk+2;
ll N=maxN;
struct Matrix{
    ll x[maxN][maxN];
    Matrix operator*(const Matrix& t)const{
        Matrix res;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                res.x[i][j]=0;
                for(int k=0;k<N;++k){
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
    Matrix(const Matrix& t){memcpy(x,t.x,sizeof(x));}
};
Matrix quick_pow(Matrix a,int x){
    Matrix I;//单位矩阵
    memset(I.x,0,sizeof(I.x));
    for(int i=0;i<N;++i){I.x[i][i]=1;}
    Matrix res(I);
    while(x){
        if(x&1){res=res*a;}
        a=a*a;
        x>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    int T;cin>>T;
    while(T--){
        cin>>n>>k;
        N=k+2;
        Matrix coe;//转移矩阵
        for(int j=0;j<N;++j){//转移矩阵第一行赋值
            coe.x[0][j]=C(k,j-1);
        }
        for(int i=1;i<N;++i){//转移矩阵其它行赋值
            for(int j=i;j<N;++j){
                coe.x[i][j]=C(k-i+1,j-i);
            }
        }
        Matrix mat(quick_pow(coe,n-1));//求转移矩阵的n-1次方
        ll res=0;
        for(ll i=0;i<N;++i){//mat矩阵第一行求和获取结果
            res=(res+mat.x[0][i])%mod;
        }
        cout<<res<<'\n';
    }
    return 0;
}