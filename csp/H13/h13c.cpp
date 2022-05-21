#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
const int maxn = 4e3+3;
string str;
vector<vector<int>> f(maxn,vector<int>(maxn,0));

int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cin>>str;
    /*
    for(int i=0;i<str.size();++i){
        f[i][i]=1;
    }
    */
    for(int len=1;len<=str.size();++len){
        for(int l=0;l<str.size()-len+1;++l){
            int r=l+len-1;
            if(str[l]==str[r]){
                if(l==r) f[l][r]=1;
                else if(l+1==r) f[l][r]=2;
                else f[l][r]=f[l+1][r-1]+2;
            }else{
                f[l][r]=max(f[l+1][r],f[l][r-1]);
            }
        }
    }
    cout<<f[0][str.size()-1];
    return 0;
}