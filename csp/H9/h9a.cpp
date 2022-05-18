//CSP201912-3
//mys
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<string> split(string &s,char c){//根据c对s分割
    stringstream ss(s);
    string read;
    vector<string> res;
    while(getline(ss,read,c)){//从ss中读取字符串到read，直至遇见c
        res.push_back(read);//将分割后的片段放入res
    }
    return res;
}
int readInt(string &s,int &p){//获取一个数字
    int res=0;
    while(p!=s.size()&&isdigit(s[p])){
        res=res*10+(s[p++]-'0');
    }
    return res==0?1:res;
}
void merge(map<string,int> &res,map<string,int> &symbols,int &ratio){//乘倍率
    for(auto &i:symbols){
        res[i.first]+=i.second*ratio;
    }
}
string readElement(string &s,int &p){//获取一个化学元素
    string res;
    res+=s[p++];
    while(p!=s.size()&&islower(s[p])){
        res+=s[p++];
    }
    return res;
}
map<string,int> readFormula(string &s,int &p);
map<string,int> readTerm(string &s,int &p){//读取一个元素及其倍率
    if(s[p]=='('){//对()内的化学式分割存放
        map<string,int> res=readFormula(s,++p);
        ++p;
        return res;
    }else{//非()内的系数为1
        string element=readElement(s,p);//获取一个化学元素
        map<string,int> res;
        res[element]=1;
        return res;
    }
}
map<string,int> readFormula(string &s,int &p){//读取各个元素及倍率(')'之前的)
    map<string,int> res;
    while(p!=s.size()&&s[p]!=')'){
        map<string,int> tmp=readTerm(s,p);//读取一个元素及倍率
        int ratio=readInt(s,p);
        merge(res,tmp,ratio);
    }
    return res;
}
map<string,int> parseExpr(string &expr){//将反应式/生成式转化为<元素,系数>的格式
    map<string,int> res;
    vector<string> formulas=split(expr,'+');//拆分出各个化学物
    for(auto i:formulas){//遍历各个化学物，对各元素计数
        int p=0;
        int ratio=readInt(i,p);
        map<string,int> symbols=readFormula(i,p);
        merge(res,symbols,ratio);
    }
    return res;
}
void solve(){
    string equation;cin>>equation;
    vector<string> expr=split(equation,'=');//分成左右式子
    if(parseExpr(expr[0])==parseExpr(expr[1])){//字典比较，相同则配平
        cout<<"Y\n";
    }else{
        cout<<"N\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
/*
//CSP201912-3
//From Teacher
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define inf 1e18;
const ll maxn=1e2+2;
ll n;
vector<string> split(string &s,char c){//根据c对s分割
    stringstream ss(s);
    string read;
    vector<string> res;
    while(getline(ss,read,c)){//从ss中读取字符串到read，直至遇见c
        res.push_back(read);//将分割后的片段放入res
    }
    return res;
}
int readInt(string &s,int &p){//获取一个数字
    int res=0;
    while(p!=s.size() and isdigit(s[p])){
        res=res*10+(s[p]-'0');
        ++p;
    }
    if(res==0) return 1;
    else return res;
}
string readElement(string &s,int &p){//获取一个化学元素
    string res;
    res+=s[p];
    ++p;
    if(p!=s.size() and islower(s[p])){
        res+=s[p];
        ++p;
    }
    return res;
}
void merge(map<string,int> &res,map<string,int> &cur,int coef){
    for(auto &i:cur){
        res[i.first]+=i.second*coef;
    }
}
map<string,int> readFormula(string &formula,int &p);
map<string,int> readTerm(string &term,int &p){
    if(term[p]=='('){
        ++p;
        map<string,int> res=readFormula(term,p);
        ++p;
        return res;
    }else{
        string element=readElement(term,p);
        map<string,int> res;
        res[element]=1;
        return res;
    }
}
map<string,int> readFormula(string &formula,int &p){//读取各个元素及倍率
    map<string,int> res;
    while(p!=formula.size() and formula[p]!=')'){
        map<string,int> tmp=readTerm(formula,p);
        int coef=readInt(formula,p);
        merge(res,tmp,coef);
    }
    return res;
}

map<string,int> parseExpr(string &expr){
    map<string,int> res;
    vector<string> formulas=split(expr,'+');
    for(auto i:formulas){//处理每一组化学符号
        int p=0;
        int coef=readInt(i,p);//获得该组化学符号的系数
        map<string,int> tmp=readFormula(i,p);
        merge(res,tmp,coef);
    }
    return res;
}
void solve(){
    string equation;
    cin>>equation;
    vector<string> expr=split(equation,'=');
    if(parseExpr(expr[0])==parseExpr(expr[1]))
        cout<<"Y\n";
    else cout<<"N\n";
}
int main(){
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
*/