#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    stringstream stream;
    cin>>s;
    int sum = (s[0]-'0');
    for(int i=2;i<5;++i)
        sum=sum+(s[i]-'0')*i;
    for(int i=5;i<10;++i)
        sum=sum+(s[i+1]-'0')*i;
    sum%=11;
    bool flag=false;
    if(s[12]=='X'){
        if(sum==10)
            flag=true;
    }else if(sum==(s[12]-'0'))
        flag=true;
    if(flag) cout<<"Right";
    else{
        cout<<s.substr(0,12);
        if(sum==10) cout<<'X';
        else cout<<sum;
    }
    // int a=atoi(s.substr(0,1).c_str());
    // int a,b,c,d;
    // stream << s.substr(0,1);
    // stream >> a;
    // stream.clear();
    // stream << s.substr(2,3);
    // stream >> b;
    // stream.clear();
    // stream << s.substr(6,5);
    // stream >> c;
    // stream.clear();
    // stream << s.substr(12,1);
    // stream >> d;
    // int res=a+b*2+c*3;
    return 0;
}