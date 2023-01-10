#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
int n,m,t,d,e,tmp,val;
bool ee[4];//1,2,n-1,n是否有落果
int tree[maxn];//树上剩余苹果数
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>m>>tree[i];
        bool drop=false;//落果
        for(int j=2;j<=m;++j){
            cin>>val;
            if(val<=0){
                tree[i]+=val;//疏果
            }else{//统计个数
                if(!drop) drop=(tree[i]>val);//判断是否落果
                tree[i]=val;//刷新剩余苹果数
            }
        }
        t+=tree[i];//T统计
        if(drop){//发生了落果
            ++d;//落果数加一
            ++tmp;//连续值加一
            if(tmp==3){//有三个连续
                ++e;//连续组加一
                tmp=2;//连续值记2
            }
            if(i<=2||i+1>=n){//收尾判断，落果记录
                if(i==1) ee[0]=true;
                if(i==2) ee[1]=true;
                if(i==n-1) ee[2]=true;
                if(n==n) ee[3]=true;
            }
        }else{//未发生落果，连续值清零
            tmp=0;
        }
    }
    if(ee[0]&&ee[3]){//首尾连续组统计
        if(ee[1]) ++e;
        if(ee[2]) ++e;
    }
    cout<<t<<' '<<d<<' '<<e;
    return 0;
}