//v2.1
//https://oj.qd.sdu.edu.cn/v2/contest/163/problem/1
//AC
#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define FILE(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define pll pair<ll,ll>

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

vector<int> tim(7);//输入的abcdef
vector<int> ti(7);//临时用
vector<int> resu(7);//最优情况的abcdef
//最优情况的边长，最优情况的时间差，最优情况的选择的完成任务的时间与实际完成任务的时间差的绝对值，最优情况的形状格式
int side0;pll se0;ll waste0;vector<int> order0(5);
ll waste;pll se;//临时用
vector<int> gettime(pll t){//(abc化秒,def化秒)->{a,b,c,d,e,f}
    vector<int> res(6);
    res[0]=t.first/3600;
    t.first%=3600;
    res[1]=t.first/60;
    t.first%=60;
    res[2]=t.first;
    res[3]=t.second/3600;
    t.second%=3600;
    res[4]=t.second/60;
    t.second%=60;
    res[5]=t.second;
    return res;
}
pll gettime(vector<int> t){return {t[0]*3600+t[1]*60+t[2],t[3]*3600+t[4]*60+t[5]};}//{a,b,c,d,e,f}->(abc化秒,def化秒)
void init(){//初始化
    se0=gettime(tim);
    if(se0.first<3661){
        se0.first=3661;
        tim=gettime(se0);
    }
    side0=sqrt(se0.second-se0.first);
    waste0=inf;//
}
ll getSquare(vector<int> vec){return vec[0]*vec[1]+vec[2]*vec[3]+vec[4]*vec[5];}//获取{a,b,c,d,e,f}的三个矩形面积和
vector<int> judgeOrder(vector<int> t,int side){//判断形状
    /*
    输出的vector<int> res的规则：
    res[0]=1: 目的形状
        res[1]: ab小者
        res[2]: cd小者
        res[3]: ef小者
    res[0]=2: 品的形状
        res[1]，res[2]，res[3]是非最长边、共同边的其余三种边的位置
    res[0]=0: 都不是
    */
    vector<int> res;
    vector<int> ti=t;
    vector<bool> swap(3);
    ti[1]=ti[0]>ti[1]?ti[0]:ti[1];
    ti[3]=ti[2]>ti[3]?ti[2]:ti[3];
    ti[5]=ti[4]>ti[5]?ti[4]:ti[5];
    if(ti[1]!=t[1]) ti[0]=t[1],swap[0]=true;//ab交换？
    if(ti[3]!=t[3]) ti[2]=t[3],swap[1]=true;//cd交换？
    if(ti[5]!=t[5]) ti[4]=t[5],swap[2]=true;//ef交换？
    if(ti[1]==ti[3]&&ti[3]==ti[5]){//目的形状
        res={1,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
    }else{//品的形状
        if(ti[1]==side){
            int same=side-ti[0];
            if(ti[2]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else if(ti[3]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else if(ti[3]==side){
            int same=side-ti[2];
            if(ti[0]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?0:1};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else{
            int same=side-ti[4];
            if(ti[0]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?0:1};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }
    }
    return res;
}
void printt(vector<int> times){//输出起止时间
    for(int i=0;i<6;++i){
        if(times[i]>9){
            cout<<times[i];
        }else{
            cout<<'0'<<times[i];
        }
        if(i==2){cout<<' ';}
        else if(i==5){cout<<'\n';}
        else{cout<<':';}
    }
}
void print(vector<int> times,vector<int> order,int side){//格式输出
    cout<<side<<'\n';
    printt(times);
    se=gettime(times);
    waste0=(waste0<0)?-waste0:waste0;
    cout<<se.second-se.first<<' '<<waste0<<'\n';
    if(order[0]==1){//目字形输出
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<times[order[1]]+times[order[2]];++i){
            for(int j=0;j<side;++j){
                cout<<'1';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            for(int j=0;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }else{//品字形输出
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            int j=0;
            for(;j<times[order[2]];++j){
                cout<<'1';
            }
            for(;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }
    cout<<'\n';
}
void solve(){
    if(se0.second<3661){//结束时间须大于01:01:01
        cout<<"-1\n\n";
        return ;
    }
    for(ll i=se0.first;i<se0.second;++i){//开始时间化秒的遍历
        if((i%3600)/60==0){//minute==0
            i=(i/3600)*3600+60;
            continue;
        }else if(i%60==0){//second==0
            continue;
        }
        for(ll j=i+1;j<=se0.second;++j){//结束时间化秒的遍历
            if((j%3600)/60==0){//minute==0
                j=(j/3600)*3600+60;
                continue;
            }else if(j%60==0){//second==0
                continue;
            }
            vector<int> tmpt=gettime(pll{i,j});
            ll square=getSquare(tmpt);
            waste=j-i-square;
            if(abs(waste)>abs(waste0)) continue;//若该次waste大于之前得到的符合要求的最小waste，则舍去
            int side=sqrt(square);
            if(side*side!=square){//若正方形面积不等于三个矩形面积之和，舍去
                continue;
            }
            bool flag=true;
            for(int k=0;k<6;++k){//若有矩形边长大于正方形边长或没有矩形边长等于正方形边长，则舍去
                if(tmpt[k]>side){flag=true;break;} //
                if(tmpt[k]==side) flag=false;
            }
            if(flag){continue;}//
            vector<int> order=judgeOrder(tmpt,side);//判断拼接形状
            if(!order[0]){//无法拼接，舍去
                continue;
            }else{
                if(abs(waste)==abs(waste0)){
                    if(se.second-se.first<=j-i)//waste相同时完成任务的起止时间差最小的优先
                        continue;
                }
                //替换
                waste0=waste;
                resu=tmpt;
                order0=order;
                side0=side;
                se=gettime(tmpt);
            }
        }
    }
    if(waste0!=inf){
        print(resu,order0,side0);//有答案
        return ;
    }
    cout<<"-1\n\n";//无答案
}

int main(){
    ios::sync_with_stdio(false);
    //FILE(tmp);
    int T;cin>>T;
    for(int i=1;i<=T;++i){
        for(int j=0;j<6;++j){
            cin>>tim[j];
        }
        init();
        cout<<"Case #"<<i<<":\n";
        solve();
    }
    return 0;
}

/*
//v2.0
//https://oj.qd.sdu.edu.cn/v2/contest/163/problem/1
//8Wrong Answer
#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define FILE(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define pll pair<ll,ll>

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

vector<int> tim(7);
vector<int> ti(7);
vector<int> resu(7);
int side0;pll se0;ll waste0;vector<int> order0(5);
//int side;
ll waste;pll se;
vector<int> gettime(pll t){
    vector<int> res(6);
    res[0]=t.first/3600;
    t.first%=3600;
    res[1]=t.first/60;
    t.first%=60;
    res[2]=t.first;
    res[3]=t.second/3600;
    t.second%=3600;
    res[4]=t.second/60;
    t.second%=60;
    res[5]=t.second;
    return res;
}
pll gettime(vector<int> t){return {t[0]*3600+t[1]*60+t[2],t[3]*3600+t[4]*60+t[5]};}
void init(){
    se0=gettime(tim);
    if(se0.first<3661){
        se0.first=3661;
        tim=gettime(se0);
    }
    side0=sqrt(se0.second-se0.first);
    waste0=inf;//
}
ll getSquare(vector<int> vec){return vec[0]*vec[1]+vec[2]*vec[3]+vec[4]*vec[5];}
vector<int> judgeOrder(vector<int> t,int side){
    vector<int> res;
    vector<int> ti=t;
    vector<bool> swap(3);
    ti[1]=ti[0]>ti[1]?ti[0]:ti[1];
    ti[3]=ti[2]>ti[3]?ti[2]:ti[3];
    ti[5]=ti[4]>ti[5]?ti[4]:ti[5];
    if(ti[1]!=t[1]) ti[0]=t[1],swap[0]=true;
    if(ti[3]!=t[3]) ti[2]=t[3],swap[1]=true;
    if(ti[5]!=t[5]) ti[4]=t[5],swap[2]=true;
    if(ti[1]==ti[3]&&ti[3]==ti[5]){
        res={1,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
    }else{
        if(ti[1]==side){
            int same=side-ti[0];
            if(ti[2]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else if(ti[3]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else if(ti[3]==side){
            int same=side-ti[2];
            if(ti[0]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?0:1};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else{
            int same=side-ti[4];
            if(ti[0]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?0:1};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }
    }
    return res;
}
void printt(vector<int> times){
    for(int i=0;i<6;++i){
        if(times[i]>9){
            cout<<times[i];
        }else{
            cout<<'0'<<times[i];
        }
        if(i==2){cout<<' ';}
        else if(i==5){cout<<'\n';}
        else{cout<<':';}
    }
}
void print(vector<int> times,vector<int> order,int side){
    cout<<side<<'\n';
    printt(times);
    se=gettime(times);
    waste0=(waste0<0)?-waste0:waste0;
    cout<<se.second-se.first<<' '<<waste0<<'\n';
    if(order[0]==1){
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<times[order[1]]+times[order[2]];++i){
            for(int j=0;j<side;++j){
                cout<<'1';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            for(int j=0;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }else{
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            int j=0;
            for(;j<times[order[2]];++j){
                cout<<'1';
            }
            for(;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }
    cout<<'\n';
}
void solve(){
    if(se0.second<3661){
        cout<<"-1\n\n";
        return ;
    }
    for(ll i=se0.first;i<se0.second;++i){
        if((i%3600)/60==0){//minute==0
            i=(i/3600)*3600+60;
            continue;
        }else if(i%60==0){//second==0
            continue;
        }
        for(ll j=i+1;j<=se0.second;++j){
            if((j%3600)/60==0){//minute==0
                j=(j/3600)*3600+60;
                continue;
            }else if(j%60==0){//second==0
                continue;
            }
            vector<int> tmpt=gettime(pll{i,j});
            ll square=getSquare(tmpt);
            waste=j-i-square;
            if(abs(waste)>=abs(waste0)) continue;
            int side=sqrt(square);
            if(side*side!=square){
                continue;
            }
            bool flag=true;
            for(int k=0;k<6;++k){
                if(tmpt[k]>side){flag=true;break;} //
                if(tmpt[k]==side) flag=false;
            }
            if(flag){continue;}//
            vector<int> order=judgeOrder(tmpt,side);
            if(!order[0]){
                continue;
            }else{
                waste0=waste;
                resu=tmpt;
                order0=order;
                side0=side;
            }
        }
    }
    if(waste0!=inf){
        print(resu,order0,side0);
        return ;
    }
    cout<<"-1\n\n";
}

int main(){
    ios::sync_with_stdio(false);
    //FILE(tmp);
    int T;cin>>T;
    for(int i=1;i<=T;++i){
        for(int j=0;j<6;++j){
            cin>>tim[j];
        }
        init();
        cout<<"Case #"<<i<<":\n";
        solve();
    }
    return 0;
}
*/
/*
//v1.1
//https://oj.qd.sdu.edu.cn/v2/contest/163/problem/1
//4,8,9Wrong Answer
#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define FILE(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define pll pair<ll,ll>

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

vector<int> tim(7);
vector<int> ti(7);
int side0;pll se0;
//int side;
ll waste;pll se;
vector<int> gettime(pll t){
    vector<int> res(6);
    res[0]=t.first/3600;
    t.first%=3600;
    res[1]=t.first/60;
    t.first%=60;
    res[2]=t.first;
    res[3]=t.second/3600;
    t.second%=3600;
    res[4]=t.second/60;
    t.second%=60;
    res[5]=t.second;
    return res;
}
pll gettime(vector<int> t){return {t[0]*3600+t[1]*60+t[2],t[3]*3600+t[4]*60+t[5]};}
void init(){
    se0=gettime(tim);
    if(se0.first<3661){
        se0.first=3661;
        tim=gettime(se0);
    }
    side0=sqrt(se0.second-se0.first);
    waste=0;
}
void printt(vector<int>);
vector<int> judgeOrder(vector<int> t,int side){
    vector<int> res;
    vector<int> ti=t;
    vector<bool> swap(3);
    ti[1]=ti[0]>ti[1]?ti[0]:ti[1];
    ti[3]=ti[2]>ti[3]?ti[2]:ti[3];
    ti[5]=ti[4]>ti[5]?ti[4]:ti[5];
    if(ti[1]!=t[1]) ti[0]=t[1],swap[0]=true;
    if(ti[3]!=t[3]) ti[2]=t[3],swap[1]=true;
    if(ti[5]!=t[5]) ti[4]=t[5],swap[2]=true;
    if(ti[1]==ti[3]&&ti[3]==ti[5]){
        res={1,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
    }else{
        if(ti[1]==side){
            int same=side-ti[0];
            if(ti[2]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else if(ti[3]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else if(ti[3]==side){
            int same=side-ti[2];
            if(ti[0]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?0:1};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else{
            int same=side-ti[4];
            if(ti[0]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?0:1};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }
    }
    return res;
}
void printt(vector<int> times){
    for(int i=0;i<6;++i){
        if(times[i]>9){
            cout<<times[i];
        }else{
            cout<<'0'<<times[i];
        }
        if(i==2){cout<<' ';}
        else if(i==5){cout<<'\n';}
        else{cout<<':';}
    }
}
void print(vector<int> times,vector<int> order,int side){
    cout<<side<<'\n';
    printt(times);
    se=gettime(times);
    waste=(waste<0)?-waste:waste;
    cout<<se.second-se.first<<' '<<waste<<'\n';
    if(order[0]==1){
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<times[order[1]]+times[order[2]];++i){
            for(int j=0;j<side;++j){
                cout<<'1';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            for(int j=0;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }else{
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            int j=0;
            for(;j<times[order[2]];++j){
                cout<<'1';
            }
            for(;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }
    cout<<'\n';
}

void solve(){
    if(se0.second<3661){
        cout<<"-1\n\n";
        return ;
    }
    //
    for(waste=0;waste<se0.second-se0.first;waste=(waste>0)?-waste:-waste+1){//waste<tim[0]*tim[1]+tim[2]*tim[3]+tim[4]*tim[5]
        for(ll i=se0.first;i<se0.second;++i){
            if((i%3600)/60==0){//minute==0
                i=(i/3600)*3600+60;
                continue;
            }else if(i%60==0){//second==0
                continue;
            }
            int side=sqrt((i/3600)*((i%3600)/60));
            set<vector<int> > ct;
            for(;;++side){//side<=side0
                if(waste>se0.second-se0.first-side*side){break;}
                ll poor=side*side+waste;
                ll maxEnd=se0.second-poor;
                if(i>maxEnd){break;}//
                if(((i+poor)%3600)/60==0){
                    break;//
                }else if((i+poor)%60==0){
                    break;//
                }
                vector<int> tmpt=gettime(pll{i,i+poor});
                if(tmpt[0]*tmpt[1]+tmpt[2]*tmpt[3]+tmpt[4]*tmpt[5]!=poor-waste){continue;}
                bool flag=true;
                for(int j=0;j<6;++j){
                    if(tmpt[j]>side) break;//
                    if(tmpt[j]==side) flag=false;
                }
                if(flag){break;}//
                tmpt.push_back(side);
                ct.emplace(tmpt);
            }
            for(auto &v:ct){
                vector<int> order=judgeOrder(v,v[6]);
                if(!order[0]){
                    continue;
                }else{
                    print(v,order,v[6]);
                    return ;
                }
            }
        }
    }
    cout<<"-1\n\n";
}
int main(){
    ios::sync_with_stdio(false);
    //FILE(tmp);
    int T;cin>>T;
    for(int i=1;i<=T;++i){
        for(int j=0;j<6;++j){
            cin>>tim[j];
        }
        init();
        cout<<"Case #"<<i<<":\n";
        solve();
    }
    return 0;
}

*/
/*
//v1.0
//https://oj.qd.sdu.edu.cn/v2/contest/163/problem/1
#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define pll pair<ll,ll>

typedef long long ll;
const int maxn = 1e6+6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

vector<int> tim(7);
vector<int> ti(7);
int side0;ll waste0;pll se0;
int side;ll waste;pll se;
vector<int> gettime(pll t){
    vector<int> res(6);
    res[0]=t.first/3600;
    t.first%=3600;
    res[1]=t.first/60;
    t.first%=60;
    res[2]=t.first;
    res[3]=t.second/3600;
    t.second%=3600;
    res[4]=t.second/60;
    t.second%=60;
    res[5]=t.second;
    return res;
}
pll gettime(vector<int> t){return {t[0]*3600+t[1]*60+t[2],t[3]*3600+t[4]*60+t[5]};}
void init(){
    se0=gettime(tim);
    if(se0.first<3661){
        se0.first=3661;
        tim=gettime(se0);
    }
    side0=sqrt(se0.second-se0.first);
    waste=0;
}
void printt(vector<int>);
vector<int> judgeOrder(vector<int> t,int side){
    vector<int> res;
    vector<int> ti=t;
    vector<bool> swap(3);
    ti[1]=ti[0]>ti[1]?ti[0]:ti[1];
    ti[3]=ti[2]>ti[3]?ti[2]:ti[3];
    ti[5]=ti[4]>ti[5]?ti[4]:ti[5];
    if(ti[1]!=t[1]) ti[0]=t[1],swap[0]=true;
    if(ti[3]!=t[3]) ti[2]=t[3],swap[1]=true;
    if(ti[5]!=t[5]) ti[4]=t[5],swap[2]=true;
    if(ti[1]==ti[3]&&ti[3]==ti[5]){
        res={1,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
    }else{
        if(ti[1]==side){
            int same=side-ti[0];
            if(ti[2]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else if(ti[3]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else if(ti[3]==side){
            int same=side-ti[2];
            if(ti[0]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?0:1};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[4]==same){
                    res={2,swap[2]?4:5,swap[1]?3:2,swap[0]?1:0};
                }else if(ti[5]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }else{
            int same=side-ti[4];
            if(ti[0]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?0:1};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?0:1};
                }else{
                    res={0};
                }
            }else if(ti[1]==same){
                if(ti[2]==same){
                    res={2,swap[2]?5:4,swap[1]?2:3,swap[0]?1:0};
                }else if(ti[3]==same){
                    res={2,swap[2]?5:4,swap[1]?3:2,swap[0]?1:0};
                }else{
                    res={0};
                }
            }else{
                res={0};
            }
        }
    }
    return res;
}
void print(vector<int> times,vector<int> order,int side){
    cout<<side<<'\n';
    for(int i=0;i<6;++i){
        if(times[i]>9){
            cout<<times[i];
        }else{
            cout<<'0'<<times[i];
        }
        if(i==2){cout<<' ';}
        else if(i==5){cout<<'\n';}
        else{cout<<':';}
    }
    se=gettime(times);
    waste=(waste<0)?-waste:waste;
    cout<<se.second-se.first<<' '<<waste<<'\n';
    if(order[0]==1){
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<times[order[1]]+times[order[2]];++i){
            for(int j=0;j<side;++j){
                cout<<'1';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            for(int j=0;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }else{
        int i=0;
        for(;i<times[order[1]];++i){
            for(int j=0;j<side;++j){
                cout<<'2';
            }
            cout<<'\n';
        }
        for(;i<side;++i){
            int j=0;
            for(;j<times[order[2]];++j){
                cout<<'1';
            }
            for(;j<side;++j){
                cout<<'0';
            }
            cout<<'\n';
        }
    }
    cout<<'\n';
}
void printt(vector<int> times){
    for(int i=0;i<6;++i){
        if(times[i]>9){
            cout<<times[i];
        }else{
            cout<<'0'<<times[i];
        }
        if(i==2){cout<<' ';}
        else if(i==5){cout<<'\n';}
        else{cout<<':';}
    }
}

void solve(){
    if(se0.second<3661){
        cout<<"-1\n\n";
        return ;
    }
    for(waste=0;waste<se0.second-se0.first;waste=(waste>0)?-waste:-waste+1){
        for(ll i=se0.first;i<se0.second;++i){
            if((i%3600)/60==0){//minute==0
                i=(i/3600)*3600+60;
                continue;
            }else if(i%60==0){//second==0
                continue;
            }
            side=sqrt((i/3600)*((i%3600)/60));
            set<vector<int> > ct;
            for(;side<=side0;++side){
                if(waste>se0.second-se0.first-side*side){break;}
                ll poor=side*side+waste;
                ll maxEnd=se0.second-poor;
                if(i>maxEnd){break;}//
               if(((i+poor)%3600)/60==0){
                    break;//
                }else if((i+poor)%60==0){
                    break;//
                }
                vector<int> tmpt=gettime(pll{i,i+poor});
                if(tmpt[0]*tmpt[1]+tmpt[2]*tmpt[3]+tmpt[4]*tmpt[5]!=poor-waste){continue;}
                bool flag=true;
                for(int j=0;j<6;++j){
                    if(tmpt[j]>side) break;//
                    if(tmpt[j]==side) flag=false;
                }
                if(flag){break;}//
                tmpt.push_back(side);
                ct.emplace(tmpt);
            }
            for(auto &v:ct){
                vector<int> order=judgeOrder(v,v[6]);
                if(!order[0]){
                    continue;
                }else{
                    print(v,order,v[6]);
                    return ;
                }
            }
        }
    }
    cout<<"-1\n\n";
}
int main(){
    ios::sync_with_stdio(false);
    int T;cin>>T;
    for(int i=1;i<=T;++i){
        for(int j=0;j<6;++j){
            cin>>tim[j];
        }
        init();
        cout<<"Case #"<<i<<":\n";
        solve();
    }
    return 0;
}
*/