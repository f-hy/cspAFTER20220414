#include<bits/stdc++.h>
using namespace std;
int n;string s;
stack<char> st;
bool vowel(int i){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        return true;
    else return false;
}
bool judge(int i,int j){
    if(vowel(i)&&vowel(j))
        return true;
    if(!vowel(i)&&!vowel(j)&&s[i]==s[j])
        return true;
    return false;
}
int main(){
    cin>>n;//1,n,5e3
    cin>>s;
    int res=1;
    for(int i=1;i<n-1;++i){//奇数个
        int j=i-1;
        while(j>=0&&(2*i-j<n)){
            if(!judge(j,2*i-j)) break;
            --j;
        }
        res=max(res,2*i-2*j-1);
    }
    for(int i=0;i<n;++i){//偶数个
        int j=i;
        while(j>=0&&(2*i-j+1<n)){
            if(!judge(j,2*i-j+1)) break;
            --j;
        }
        res=max(res,2*i-2*j);
    }
    cout<<res<<'\n';
    return 0;
}