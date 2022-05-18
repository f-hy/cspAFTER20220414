#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
struct file{
    bool isDir;//是否为目录
    ll ld,lr;//目录配额,后代配额
    ll sd,sr;//目录已用配额,后代已用配额
    map<string,file> children;//子一级文件、目录
    ll fileSize;//文件大小
    file(){//构造函数
        isDir=true;
        ld=lr=inf;
        sd=sr=0;
        fileSize=0;
    }
};
file root;
vector<string> split(string &path){//根据c对s分割
    stringstream ss(path);
    string read;
    vector<string> res;
    while(getline(ss,read,'/')){//从ss中读取字符串到read，直至遇见c
        res.push_back(read);//将分割后的片段放入res
    }
    return res;
}
vector<file *> findFile(vector<string> &fileNames){
    vector<file *> res;
    res.push_back(&root);
    for(int i=1;i<fileNames.size();++i){
        if(res.back()->isDir==false){break;}//该文件在此不是目录，无法进行操作
        if(res.back()->children.count(fileNames[i])==0){break;}//在该目录下未找到指定文件/目录
        res.push_back(&res.back()->children[fileNames[i]]);//在该目录下找到了指定文件/目录，加入res
    }
    return res;
}
/*C <file path> <file size>
创建普通文件的指令有两个参数，是空格分隔的字符串和一个正整数，分别表示需
要创建的普通文件的路径和文件的大小。
对于该指令，若路径所指的文件已经存在，且也是普通文件的，则替换这个文件；
若路径所指文件已经存在，但是目录文件的，则该指令不能执行成功。
当路径中的任何目录不存在时，应当尝试创建这些目录；若要创建的目录文件与已
有的同一双亲目录下的孩子文件中的普通文件名称重复，则该指令不能执行成功。
另外，还需要确定在该指令的执行是否会使该文件系统的配额变为不满足，如果会
发生这样的情况，则认为该指令不能执行成功，反之则认为该指令能执行成功。
*/
bool create(){//创建文件
    string path;
    ll fileSize;
    cin>>path>>fileSize;
    vector<string> fileNames=split(path);//
    vector<file *> filePtrs=findFile(fileNames);//查找能找到的符合的路径
    ll inc;
    if(fileNames.size()==filePtrs.size()){//若路径所指的文件已经存在
        if(filePtrs.back()->isDir){return false;}//是目录文件,不能执行成功
        else{inc=fileSize-filePtrs.back()->fileSize;}//是普通文件,替换这个文件
    }else{//路径中的某些目录不存在
        //要创建的目录文件与已有的同一双亲目录下的孩子文件中的普通文件名称重复，则该指令不能执行成功
        if(!filePtrs.back()->isDir){return false;}
        else{inc=fileSize;}//尝试创建这些目录
    }

    //检查该指令的执行是否会使该文件系统的配额变为不满足
    //后代配额检查
    for(int i=0;i<filePtrs.size();++i){
        if(filePtrs[i]->sr+inc>filePtrs[i]->lr){return false;}
    }
    //目录配额检查
    int i=fileNames.size()-2;
    if(i<filePtrs.size()&&filePtrs[i]->sd+inc>filePtrs[i]->ld){return false;}
    //补齐路径
    for(int i=filePtrs.size();i<fileNames.size();++i){
        filePtrs.push_back(&filePtrs.back()->children[fileNames[i]]);
    }
    //创建的文件基本信息的写入
    filePtrs.back()->isDir=false;
    filePtrs.back()->fileSize=fileSize;
    //修改祖先的后代已用配额
    for(auto &i:filePtrs){
        i->sr+=inc;
    }
    //修改父亲的目录已用配额
    filePtrs.end()[-2]->sd+=inc;
    return true;
}
/*R <file path>
移除文件的指令有一个参数，是字符串，表示要移除的文件的路径。
若该路径所指的文件不存在，则不进行任何操作。若该路径所指的文件是目录，
则移除该目录及其所有后代文件。在上述过程中被移除的目录（如果有）上设置的
配额值也被移除。
该指令始终认为能执行成功
*/
bool remove(){
    string path;cin>>path;
    vector<string> fileNames=split(path);
    vector<file *> filePtrs=findFile(fileNames);
    if(filePtrs.size()!=fileNames.size()){return true;}//该路径所指的文件不存在
    if(filePtrs.back()->isDir){//该路径所指的文件是目录
        for(auto &i:filePtrs){//对路径上的祖先的后代已用配额修减去最后一级目录的后代已用配额
            i->sr-=filePtrs.back()->sr;
        }
    }else{//该路径所指的文件是普通文件
        for(auto &i:filePtrs){//对路径上的祖先的后代已用配额修减去普通文件的文件大小
            i->sr-=filePtrs.back()->sr;
        }
        filePtrs.end()[-2]->sd-=filePtrs.back()->fileSize;//被移除文件的父亲的目录已用配额减去普通文件的文件大小
    }
    filePtrs.end()[-2]->children.erase(fileNames.back());//移除文件
    return true;
}
/*Q <file path> <LD> <LR>
设置配额值的指令有三个参数，是空格分隔的字符串和两个非负整数，分别表示需
要设置配额值的目录的路径、目录配额和后代配额。
该指令表示对所指的目录文件，分别设置目录配额和后代配额。若路径所指的文件
不存在，或者不是目录文件，则该指令执行不成功。
若在该目录上已经设置了配额，则将原配额值替换为指定的配额值。
特别地，若配额值为 0，则表示不对该项配额进行限制。若在应用新的配额值后，
该文件系统配额变为不满足，那么该指令执行不成功。
*/
bool quota(){
    string path;
    long long ld,lr;
    cin>>path>>ld>>lr;
    //若配额值为 0，则表示不对该项配额进行限制
    ld=(ld==0)?inf:ld;
    lr=(lr==0)?inf:lr;
    vector<string> fileNames=split(path);
    vector<file *> filePtrs=findFile(fileNames);
    if(filePtrs.size()!=fileNames.size()){return false;}//没有该目录
    if(!filePtrs.back()->isDir){return false;}//不是一个目录文件
    //若在应用新的配额值后，该文件系统配额变为不满足，那么该指令执行不成功。
//
    if(filePtrs.back()->sd>ld||filePtrs.back()->sr>lr){return false;}//判断修改后该目录的sd、sr是否溢出
    //完成配额修改操作（配额更新）
    filePtrs.back()->ld=ld;
    filePtrs.back()->lr=lr;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    int n;cin>>n;
    while(n--){
        char op;cin>>op;
        bool res;
        switch(op){
            case 'C':{res=create();break;}
            case 'R':{res=remove();break;}
            case 'Q':{res=quota();break;}
        }
        if(res){cout<<"Y\n";}
        else{cout<<"N\n";}
    }
    return 0;
}