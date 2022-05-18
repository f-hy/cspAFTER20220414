#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
struct struc{
    int a=3;
    int b;
}st;
int main(){
    ios::sync_with_stdio(false);
    //file(data);
    cout<<st.a;
    st.a+=5;
    st.b=3;
    cout<<st.a<<st.b;
    return 0;
}