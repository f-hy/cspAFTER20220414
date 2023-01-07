#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,xx,yy;
struct{
    int num;
    int dist;
}s[200];
int square(int x){
    return x*x;
}
priority_queue<pii,vector<pii>,greater<pii> > pq;
int main(){
    cin>>n>>xx>>yy;
    int x,y,d;
    for(int i=1;i<=n;++i){
        cin>>x>>y;
        d = square(xx-x)+square(yy-y);
        pq.push({d,i});
    }
    cout<<pq.top().second<<endl;
    pq.pop();
    cout<<pq.top().second<<endl;
    pq.pop();
    cout<<pq.top().second<<endl;
    return 0;
}