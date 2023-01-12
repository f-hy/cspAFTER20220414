#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+1;
const int maxa = 1e4+1;
//1,i,k,j,n
int n;
int maxval=0;
set<int> ct;
vector<set<int>> vec(maxa);
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int a[maxn];
    bool flag=false;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        bool ai=a[i]>0;
        if(ai!=flag){
            flag=ai;
            if(ai) ++maxval;
        }
        ct.insert(a[i]);
        vec[a[i]].insert(i);
    }
    if(*ct.begin()==0){
        ct.erase(ct.begin());
    }
    int val=maxval;
    for(auto &x:ct){
        for(auto &y:vec[x]){
            bool l = a[y-1]>x;
            bool r = a[y+1]>=x;
            if(l==r){
                if(l) ++val;
                else --val;
            }
        }
        maxval = val>maxval?val:maxval;
    }
    cout<<maxval;
    return 0;
}