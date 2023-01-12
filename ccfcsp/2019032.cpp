/**
 * @file 2019032.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-01-12
 * @version 0.1
 * @brief csp competition
 * @copyright Copyright (c) 2023
 */
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ite(it,s,e) for(auto it=s;it!=e;++it)
int n;
stack<int> num,tmpn,symbol,tmps;
char s[7];
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    rep(i,1,n){
        cin>>s;
        dwn(j,3,0) num.push(s[j+j]-'0');
        dwn(j,2,0) switch (s[j+j+1]){
            case 'x':symbol.push(0);break;
            case '/':symbol.push(1);break;
            case '+':symbol.push(2);break;
            case '-':symbol.push(3);break;
            default:break;
            }
        while(symbol.size()||tmps.size()){
            if(symbol.size()){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                int c=symbol.top();
                symbol.pop();
                if(!symbol.size()||((c/2)>(symbol.top()/2))){
                    tmpn.push(a);
                    tmps.push(c);
                    num.push(b);
                }else{
                    switch (c){
                    case 0:a*=b;break;
                    case 1:a/=b;break;
                    case 2:a+=b;break;
                    case 3:a-=b;break;
                    default:break;
                    }
                    num.push(a);
                }
            }else{
                int a=tmpn.top();
                tmpn.pop();
                int b=num.top();
                num.pop();
                int c=tmps.top();
                tmps.pop();
                switch (c){
                case 0:a*=b;break;
                case 1:a/=b;break;
                case 2:a+=b;break;
                case 3:a-=b;break;
                default:break;
                }
                num.push(a);
            }
        }
        // cout<<num.top()<<endl;
        if(num.top()==24) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}