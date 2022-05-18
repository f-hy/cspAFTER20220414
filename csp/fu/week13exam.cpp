#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int inf = 1e8;
const ll linf = 1e18;
const int maxn = 1e3 + 3;
const int maxm = 1e5 + 5;
int n, m;//
ll d; //n<=1e3; m<=1e5; d<=1e7; sumK<=1e6
ll t;//t<=1e9;
map<string, int> mworkshop;//a map from workshop's name to its id 
struct thetasks{// the struct of the task
    ll t;//addTime
    string s;//task name
    ll d;//need time
    int workshop;
    ll endtime;
    bool operator<(thetasks& _task){
        if(endtime<_task.endtime) return true;
        else if(endtime==_task.endtime&&t<_task.t) return true;
        else return false;
    }
} task[maxm];
struct sfcmp{//时间短的在前面,名称字典序大在前
    bool operator()(const ll& x,const ll&y) const{
        if(task[x].d>task[y].d) return true;
        else if(task[x].d==task[y].d&&task[x].s<task[y].s) return true;
        else return false;
        //return task[x].d > task[y].d;
    }
};
struct lfcmp{//时间长的在前面,名称字典序大在前
    bool operator()(const ll &x, const ll &y) const{
        if(task[x].d<task[y].d) return true;
        else if(task[x].d==task[y].d&&task[x].s<task[y].s) return true;
        else return false;
        //return task[x].d < task[y].d;
    }
};
struct workshops{// the struct of the workshop
    string name;
    int mode;//TF, SF, LF
    int dti=-1; //dealingtaski
    ll curtime=0;
    queue<int> tf;
    priority_queue<int,vector<int>,sfcmp> sf;
    priority_queue<int,vector<int>,lfcmp> lf;
    //workshops(bool _xian = true) : xian(_xian){};
    void gettask(int i){//select which workshop this task will come to
        if(mode==1){
            if(dti==-1){dti=i;curtime=task[i].t;return ;}//free
            while(true){
                if(curtime+task[dti].d>task[i].t){//dti not complete
                    tf.push(i);
                    return ;
                }else{//dti complete
                    curtime+=task[dti].d;
                    task[dti].endtime=curtime;
                    if(tf.empty()){
                        dti=i;
                        if(curtime<task[dti].t){curtime=task[dti].t;}
                        return ;
                    }else{
                        dti=tf.front();tf.pop();
                        if(curtime<task[dti].t){curtime=task[dti].t;}
                    }
                }
            }
        }else if(mode==2){
            if(dti==-1){dti=i;curtime=task[i].t;return ;}//free
            while(true){
                if(curtime+task[dti].d>task[i].t){//dti not complete
                    sf.push(i);//
                    return ;
                }else{//dti complete
                    curtime+=task[dti].d;
                    task[dti].endtime=curtime;
                    if(sf.empty()){
                        dti=i;
                        if(curtime<task[dti].t){curtime=task[dti].t;}
                        return ;
                    }else{
                        dti=sf.top();sf.pop();
                        if(curtime<task[dti].t){curtime=task[dti].t;}
                    }
                }
            }
        }else if(mode==3){
            if(dti==-1){dti=i;curtime=task[i].t;return ;}//free
            while(true){
                if(curtime+task[dti].d>task[i].t){//dti not complete
                    lf.push(i);
                    return ;
                }else{//dti complete
                    curtime+=task[dti].d;
                    task[dti].endtime=curtime;
                    if(lf.empty()){
                        dti=i;
                        if(curtime<task[dti].t){curtime=task[dti].t;}
                        return ;
                    }else{
                        dti=lf.top();lf.pop();
                        if(curtime<task[dti].t){curtime=task[dti].t;}
                    }
                }
            }
        }
    }
    void endtask(){//deal with the rest of the tasks in this workshop
        if(mode==1){
            while(dti!=-1){
                curtime+=task[dti].d;
                task[dti].endtime=curtime;
                if(!tf.empty()){
                    dti=tf.front();tf.pop();
                    if(curtime<task[dti].t){curtime=task[dti].t;}
                }else{
                    return ;
                }
            }
        }else if(mode==2){
            while(dti!=-1){
                curtime+=task[dti].d;
                task[dti].endtime=curtime;
                if(!sf.empty()){
                    dti=sf.top();sf.pop();
                    if(curtime<task[dti].t){curtime=task[dti].t;}
                }else{
                    return ;
                }
            }
        }else if(mode==3){
            while(dti!=-1){
                curtime+=task[dti].d;
                task[dti].endtime=curtime;
                if(!lf.empty()){//
                    dti=lf.top();lf.pop();//
                    if(curtime<task[dti].t){curtime=task[dti].t;}
                }else{
                    return ;
                }
            }
        }
    }
} workshop[maxn];

static unsigned int p = 1;
int myrand(void){//a number in [0,65535], the problem gives
    p = p * 1103515245 + 12345;
    return ((unsigned int)(p / 65536) % 100);
}
int selectWorkshop(int k){//choose which workshop to join
    unsigned int kp = 100 / k;
    int i = 0;
    for (; i < k-1; ++i)
    {
        if(kp>myrand())
            break;
    }
    return i;
}
void solve(){//solve the problem
    //input module
    cin >> n >> m;
    string name, attribute;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> attribute;
        mworkshop[name] = i;
        workshop[i].name = name;
        if (attribute == "TF")
        {
            workshop[i].mode = 1;
        }
        else if (attribute == "SF")
        {
            workshop[i].mode = 2;
        }
        else if (attribute == "LF")
        {
            workshop[i].mode = 3;
        }
    }
    int k;
    //input module and solve module
    for (int i = 0; i < m; ++i)
    {
        cin >> task[i].t >> task[i].s >> task[i].d >> k;
        vector<string> vs;//temporary store the orderly workshops
        for (int j = 0; j < k; ++j)
        {
            cin >> name;
            vs.push_back(name);
        }
        int cheid = mworkshop[vs[selectWorkshop(k)]];
        workshop[cheid].gettask(i);
    }
    //solve module
    for(int i=0;i<n;++i){//deal with the rest of the tasks in the workshops
        workshop[i].endtask();
    }
    sort(task,task+m);//sort it
    for(int i=0;i<m;++i){//output the endtime and the taskname
        cout<<task[i].endtime<<' '<<task[i].s<<'\n';
    }
}
int main(){//main function
    solve();
    return 0;
}