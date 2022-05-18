#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

typedef long long ll;
const int maxn = 1e6+6;//开辟数组等用
const int maxc=1e6+1;//内存占用最大值
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
#define pii pair<int,int>
#define pll pair<ll,ll>
ll n;//1,n,1e6
set<pii> ct;//按运行时间,内存占用顺序对输入的数据排序
vector<ll> res(maxn,0);//结果存储
vector<ll> s(maxn,0);//
#define lb(x) (x&-x)//lowerbit
int ask(int x){//get d[1:x]
    int res=0;
    for(int i=x;i>=1;i-=lb(i))
        res+=s[i];
    return res;
}
void upd(int x,int v){//将d[x]的值增加 v: x 所有祖先节点+v
    for(int i=x;i<=maxc;i+=lb(i))
        s[i]+=v;
}
int main(){
    //ios::sync_with_stdio(false);
    //file(data);
    scanf("%d",&n);
    pii tmp;
    for(int i=0;i<n;++i){
        scanf("%d%d",&tmp.first,&tmp.second);
        ++tmp.second;//注意：运行时间,内存占用可能为0，故+1避免！！！！
        ct.emplace(tmp);
    }
    //运行时间随ct向后迭代而增大，且相同运行时间时按内存占用升序排序
    for(auto it=ct.begin();it!=ct.end();++it){
        ++res[ask(it->second)];//该分数程序数+1
        upd(it->second,1);//it->second-1内存占用的程序数+1
    }
    for(int i=0;i<n;++i){//输出结果
        printf("%d\n",res[i]);
    }
    return 0;
}