#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
bool cmp(int a,int b){return a<b;}
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    int s[7]={3,2,5,1,9,2};
    sort(s,s+6,cmp);
    for(int i=0;i<6;++i) cout<<s[i];
    return 0;
}