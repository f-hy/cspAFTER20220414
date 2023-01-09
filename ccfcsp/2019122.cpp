#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int maxn=1e3+1;
int n;
map<int,set<int> > dots;
int scores[5];
int main(){
    cin>>n;
    int x,y;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        dots[x].insert(y);
    }
    for(auto it=dots.begin();it!=dots.end();++it){
        x = it->first;
        for(auto &y:it->second){
            if(dots[x].count(y-1)&&dots[x].count(y+1)&&
            dots.count(x+1)&&dots[x+1].count(y)&&
            dots.count(x-1)&&dots[x-1].count(y)){
                int cnt=0;
                if(dots[x-1].count(y-1)) ++cnt;
                if(dots[x+1].count(y-1)) ++cnt;
                if(dots[x-1].count(y+1)) ++cnt;
                if(dots[x+1].count(y+1)) ++cnt;
                ++scores[cnt];
            }
        }
        
    }
    for(int i=0;i<5;++i){
        cout<<scores[i]<<endl;
    }
    return 0;
}