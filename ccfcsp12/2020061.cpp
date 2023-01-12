#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn=1e3+1;
const int maxm=20;

int n,m;
// forward_list<pii> a,b;
// queue<pii> a,b;
// vector<pii> a(maxn),b(maxn);
pii a[maxn],b[maxn];
int cnta=0,cntb=0;
int t1,t2,t3;
bool judge(pii p){
    return (t1+t2*p.first+t3*p.second)>0;
}
int main(){
    cin>>n>>m;
    int x,y;
    char type;
    for(int i=1;i<=n;++i){
        cin>>x>>y>>type;
        if(type=='A'){
            a[cnta++]={x,y};
        }else{
            b[cntb++]={x,y};
        }
    }
    for(int i=1;i<=m;++i){
        cin>>t1>>t2>>t3;
        bool outp=false;
        bool judge = (t1+t2*a[0].first+t3*a[0].second)>0;
        for(int j=1;j<cnta;++j){
            if(bool((t1+t2*a[j].first+t3*a[j].second)>0)!=judge){
                cout<<"No"<<endl;
                outp=true;
                break;
            }
        }
        if(outp) continue;
        for(int j=0;j<cntb;++j){
            if(bool((t1+t2*b[j].first+t3*b[j].second)>0)==judge){
                cout<<"No"<<endl;
                outp=true;
                break;
            }
        }
        if(!outp) cout<<"Yes"<<endl;
    }
    return 0;
}