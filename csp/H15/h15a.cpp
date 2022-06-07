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
//const int maxn = 1e6+6;
ll n,p;
const int N=2;
struct Matrix{
    ll x[N][N];
    Matrix operator*(const Matrix& t)const{
        Matrix res;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                res.x[i][j]=0;
                for(int k=0;k<N;++k){
                    res.x[i][j]+=x[i][k]*t.x[k][j];
                    res.x[i][j]%=p;//mod
                }
            }
        }
        return res;
    }
    //强烈建议实现构造函数和复制构造函数以避免出现奇怪的bug
    Matrix(){memset(x,0,sizeof(x));}
    //Matrix(){x[0][0]=x[0][1]=x[1][0]=1;x[1][1]=0;}
    Matrix(ll _x[N][N]){memcpy(x,_x,sizeof(x));}
    Matrix(const Matrix& t){memcpy(x,t.x,sizeof(x));}
};
Matrix quick_pow(Matrix a,int x){
    ll _x[N][N]={{1,0},{0,1}};
    Matrix res(_x);
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
    int T;
    cin>>T;
    ll x[N][N]={{1,1},{1,0}};
    Matrix ma(x);
    while(T--){
        cin>>n>>p;
        if(n<3){
            cout<<"1\n";
        }else{
            Matrix mat(quick_pow(ma,n-2));
            ll res=mat.x[0][0]+mat.x[0][1];
            res%=p;
            cout<<res<<'\n';
        }
    }
    return 0;
}