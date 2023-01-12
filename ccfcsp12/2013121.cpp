#include<bits/stdc++.h>
using namespace std;

int n;
map<int,int> m;
int main(){
    cin>>n;
    int s;
    for(int i=1;i<=n;++i){
        cin>>s;
        if(!m.count(s)) m[s]=1;
        else m[s]=m[s]+1;
    }
    int maxcnt=0;
    int maxnum=0;
    for(auto &x:m){
        if(x.second>maxcnt){
            maxnum=x.first;
            maxcnt=x.second;
        }
    }
    cout<<maxnum;
    return 0;
}