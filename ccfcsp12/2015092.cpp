#include<bits/stdc++.h>
using namespace std;
int y,d;
int main(){
    cin>>y>>d;
    int t=28;
    if((y%4==0&&y%100)||y%400==0) t=29;
    int a[13]={0,31,t,31,30,31,30,31,31,30,31,30,31};
    for(int i=1;i<13;++i){
        a[i]+=a[i-1];
        if(a[i]>=d){
            cout<<i<<endl<<d-a[i-1];
            return 0;
        }
    }
}
/*
int md[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int main(){
    cin>>y>>d;
    if(d<=md[1]) cout<<"1\n"<<d;
    else if(d<=md[2]) cout<<"2\n"<<d-md[1];
    else{
        if((y%4==0&&y%100)||y%400==0) --d;
        if(d==md[2]) cout<<"2\n29";
        else if(d<=md[3]) cout<<"3\n"<<d-md[2];
        else if(d<=md[4]) cout<<"4\n"<<d-md[3];
        else if(d<=md[5]) cout<<"5\n"<<d-md[4];
        else if(d<=md[6]) cout<<"6\n"<<d-md[5];
        else if(d<=md[7]) cout<<"7\n"<<d-md[6];
        else if(d<=md[8]) cout<<"8\n"<<d-md[7];
        else if(d<=md[9]) cout<<"9\n"<<d-md[8];
        else if(d<=md[10]) cout<<"10\n"<<d-md[9];
        else if(d<=md[11]) cout<<"11\n"<<d-md[10];
        else cout<<"12\n"<<d-md[11];
    }
    return 0;
}*/