#include<bits/stdc++.h>
using namespace std;
const int maxn=11;
int n,m;
struct windows{
    int x1,x2,y1,y2;
}win[maxn];
deque<int> sequence;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>win[i].x1>>win[i].y1>>win[i].x2>>win[i].y2;
        sequence.push_front(i);
    }
    int x,y;
    for(int i=1;i<=m;++i){
        cin>>x>>y;
        bool flag=false;
        for(deque<int>::iterator it=sequence.begin();it!=sequence.end();++it){
            int j=*it;
            if(x>=win[j].x1&&x<=win[j].x2&&y>=win[j].y1&&y<=win[j].y2){
                cout<<j<<endl;
                sequence.erase(it);
                sequence.push_front(j);
                flag=true;
                break;
            }
        }
        if(!flag) cout<<"IGNORED"<<endl;
    }
    return 0;
}