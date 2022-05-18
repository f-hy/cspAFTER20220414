#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

int vi[8]={0};
typedef long long ll;
const int maxn = 5e3+3;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
int n;//1,n,5e3
struct cursor{// record current cursor position
    int x;// xth row
    int y;// yth column
    cursor(int _x=1,int _y=1):x(_x),y(_y){}// start from (1,1)
    bool operator==(cursor _cs){return x==_cs.x&&y==_cs.y;}
    cursor& operator=(cursor _cs){x=_cs.x,y=_cs.y;return *this;}
}cs;
struct noteBook{// the notebook
    deque<string> notes;// its content
    noteBook(){notes.push_back("\n");}// initial function
    int lineLen(int _x=cs.x){return notes.at(_x-1).size();}// get the line length, default line is cs.x
    void _ini(deque<string> _notes){
        notes.clear();
        for(auto &x:_notes) notes.push_back(x);
    }
}note;
void noteInfo(){//test for print the notebooks content in a line
    cout<<"--"<<note.notes.size()<<'('<<cs.x<<','<<cs.y<<')'<<"-- ";
    int i=0;
    for(auto &x:note.notes){
        cout<<'-'<<++i<<'.'<<x.size()<<'.'<<x.substr(0,x.size()-1)<<' ';
    }
    cout<<endl;
}
pair<cursor,cursor> sortse(cursor &_sc,cursor &_ec,bool directlyChange=false){// compare two coordinate points
    pair<cursor,cursor> res;
    if(_sc.x==_ec.x){//一行之内
        res.first.x=_sc.x;
        res.second.x=_sc.x;
        res.first.y=_sc.y<_ec.y?_sc.y:_ec.y;
        res.second.y=_sc.y>_ec.y?_sc.y:_ec.y;
    }else{// no less than two rows
        if(_sc.x<_ec.x){
            res.first.x=_sc.x;
            res.second.x=_ec.x;
            res.first.y=_sc.y;
            res.second.y=_ec.y;
        }else{
            res.first.x=_ec.x;
            res.second.x=_sc.x;
            res.first.y=_ec.y;
            res.second.y=_sc.y;
        }
    }
    if(directlyChange){
        _sc=res.first;
        _ec=res.second;
    }
    return res;
}
struct shiftOthers{
    deque<string> clipBoard;//粘贴板
    bool shift;//粘滞功能
    bool selected;//选中状态
    cursor recordPoint;//记录点
    pair<cursor,cursor> selectArea;//leftCursor, rightCursor
    shiftOthers(bool _shift=false,bool _selected=false):shift(_shift),selected(_selected){}
    void turnArea(){
        selectArea=sortse(recordPoint,cs);
    }
}so;
void printselectedArea(pair<cursor,cursor> sa){// test function, print the selected area's two borders
    cout<<'('<<sa.first.x<<','<<sa.first.y<<") ("<<sa.second.x<<','<<sa.second.y<<")\n";
}
bool paste0(const string _s,cursor &_cs,bool movey=true){//paste within one line and no '\n'
    note.notes.at(_cs.x-1).insert(_cs.y-1,_s);
    if(movey){
        _cs.y+=_s.size();
    }
    if(_cs.x>note.notes.size()||_cs.y>note.notes.at(_cs.x-1).size()) return false;
    return true;
}
bool paste1(const deque<string> _note,cursor &_cs,bool move=true){//paste with no less than one line and a '\n' or deal with the head and tail
    bool hasTail=(_note.back()[_note.back().size()-1]!='\n');
    if(hasTail){
        paste0(_note.back(),_cs,false);//insert the tail
    }
    string tmp=note.notes.at(_cs.x-1).substr(_cs.y-1,note.lineLen(_cs.x)-_cs.y+1);//a copy of the line tail
    note.notes.at(_cs.x-1).erase(_cs.y-1);//erase the line tail
    note.notes.at(_cs.x-1)+=_note.front();//join the head line
    //join the tail line
    if(_cs.x==note.notes.size()){//end of the notes
        note.notes.push_back(tmp);
    }else{//rather if not the end of the notes
        note.notes.insert(note.notes.begin()+_cs.x,tmp);
    }
    //move cursor position
    ++_cs.x;
    if(hasTail){
        _cs.y=_note.back().size()+1;
    }else{
        _cs.y=1;
    }
    return hasTail;
}
void paste2(const deque<string> _note,cursor &_cs,bool move=true){//paste with no less than three rows
    bool hasTail=paste1(_note,_cs);//deal with the head and tail
    for(int i=_note.size()-hasTail-1;i>0;--i){//deal with the middle lines
        note.notes.insert(note.notes.begin()+_cs.x-1,_note.at(i));
    }
    _cs.x+=_note.size()-hasTail-1;//move the cursor
}
void remove0(pair<cursor,cursor> se){//remove within one line and no '\n'
    note.notes.at(se.first.x-1).erase(se.first.y-1,se.second.y-se.first.y);
}
void remove1(pair<cursor,cursor> se){//remove head and tail
    note.notes.at(se.first.x-1).erase(se.first.y-1);//remove head part
    note.notes.at(se.second.x-1).erase(0,se.second.y-1);//remove tail part
    note.notes.at(se.first.x-1)+=note.notes.at(se.second.x-1);//join the tail to head
    note.notes.erase(note.notes.begin()+se.second.x-1);//erase the tail line
}
void remove2(pair<cursor,cursor> se){//remove no less than three rows
    remove1(se);//remove head and tail
    auto it=note.notes.begin()+se.first.x;
    note.notes.erase(it,it+se.second.x-se.first.x-1);
}
void del(const cursor _cs){// del a character
    pair<cursor,cursor> se;
    se.first=_cs;
    if(se.first.y==note.notes.at(se.first.x-1).size()){
        if(_cs.x==note.notes.size()){//note tail, del failed
            return ;
        }
        se.second=cursor(_cs.x+1,1);
        remove1(se);
    }else{
        se.second=cursor(_cs.x,_cs.y+1);
        remove0(se);
    }
}
void backspace(cursor &_cs){// backspace a character
    pair<cursor,cursor> se;
    se.second=_cs;
    if(se.second.y==1){
        if(_cs.x==1){//note head, failed
            return ;
        }
        --_cs.x;
        _cs.y=note.notes.at(_cs.x-1).size();
        se.first=_cs;
        remove1(se);
    }else{
        --_cs.y;
        se.first=_cs;
        remove0(se);
    }
}
void remove(pair<cursor,cursor> se){//[s,e) summary
    if(se.first.x==se.second.x){
        remove0(se);
    }else if(se.second.x==se.first.x+1){
        remove1(se);
    }else{
        remove2(se);
    }
}
void opmove(string op){// operation of "MOVE"
    if(so.selected){
        so.selected=false;
    }
    if(op=="Home"){
        cs.y=1;
    }else if(op=="End"){
        cs.y=note.lineLen();
    }else if(op=="Up"){
        if(cs.x>1){
            int tmp=note.lineLen(--cs.x);
            if(cs.y>tmp){
                cs.y=tmp;
            }
        }
    }else if(op=="Down"){
        if(cs.x<note.notes.size()){
            int tmp=note.lineLen(++cs.x);
            if(cs.y>tmp){
                cs.y=tmp;
            }
        }
    }else if(op=="Left"){
        if(cs.y>1){
            --cs.y;
        }else if(cs.x>1){
            cs.y=note.lineLen(--cs.x);
        }
    }else if(op=="Right"){
        if(cs.y<note.lineLen()){
            ++cs.y;
        }else if(cs.x<note.notes.size()){
            cs.y=1;
            ++cs.x;
        }
    }
}
void paste(){// paste the clipBoard to the correct position of the notebook
    if(so.clipBoard.front()[so.clipBoard.front().size()-1]!='\n'){//within one line
        paste0(so.clipBoard.front(),cs);
    }else if((so.clipBoard.back()[so.clipBoard.back().size()-1]=='\n'&&so.clipBoard.size()==1)||
             (so.clipBoard.back()[so.clipBoard.back().size()-1]!='\n'&&so.clipBoard.size()==2)){
        paste1(so.clipBoard,cs);
    }else{
        paste2(so.clipBoard,cs);
    }
}
void opinsert(string op){// operation of "INSERT"
    if(so.selected){
        bool cskeep=(so.selectArea.first==cs);
        if(!cskeep){
            cs=so.selectArea.first;
        }
        remove(so.selectArea);
        so.selected=false;
    }
    if(op=="Char"){
        string c;
        cin>>c;
        paste0(c,cs);
    }else if(op=="Enter"){
        deque<string> ent;
        ent.push_back("\n");
        paste1(ent,cs);
    }else if(op=="Space"){
        paste0(" ",cs);
    }else if(op=="Paste"){
        if(so.clipBoard.size()>0){
            paste();
        }
    }
}
void opremove(string op){// operation of "REMOVE"
    if(so.selected){
        bool cskeep=(so.selectArea.first==cs);
        if(!cskeep){
            cs=so.selectArea.first;
        }
        remove(so.selectArea);
        so.selected=false;
        return ;
    }
    if(op=="Del"){
        del(cs);
    }else if(op=="Backspace"){
        backspace(cs);
    }
}
void opshift(){// operation of "SHIFT"
    if(so.selected){
        so.selected=false;
        so.shift=true;
        return ;
    }
    if(so.shift){//粘滞功能关闭时
        if(so.recordPoint.x!=cs.x||so.recordPoint.y!=cs.y){//此时的光标位置与记录点的位置不同，进入选中状态
            so.turnArea();
            so.selected=true;
        }
        so.shift=false;
    }else{//粘滞功能启动时
        so.recordPoint=cs;
        so.shift=true;
        //so.selected=false;
    }
}
ll cntWord(string word,bool global=true){// count word in the chosed area
    int wordSize=word.size();
    ll res=0;
    int tmpi,tmpj;
    if(global){
        for(auto &x:note.notes){
            tmpi=x.size()-wordSize+1;//c1
            for(int i=0;i<tmpi;++i){
                if(word==x.substr(i,wordSize)){
                    ++res;
                }
            }
        }
    }else{
        int lx=so.selectArea.first.x,
            ly=so.selectArea.first.y,
            rx=so.selectArea.second.x,
            ry=so.selectArea.second.y;
        if(lx+1<rx){//mid lies
            tmpi=rx-1;
            for(int i=lx;i<tmpi;++i){
                tmpj=note.notes.at(i).size()-wordSize+1;//c1
                for(int j=0;j<tmpj;++j){
                    if(word==note.notes.at(i).substr(j,wordSize)){
                        ++res;
                    }
                }
            }
        }
        if(note.notes.at(lx-1).size()-ly+1>=wordSize){//head row
            int maxj=note.notes.at(lx-1).size()-wordSize;
            if(lx==rx) tmpj=(ry-wordSize)<maxj?(ry-1):maxj;
            else tmpj=maxj;//c1
            for(int j=ly-1;j<tmpj;++j){
                if(word==note.notes.at(lx-1).substr(j,wordSize)){
                    ++res;
                }
            }
        }
        if(ry>wordSize){//tail row
            tmpj=note.notes.at(rx-1).size()-wordSize+1;//c1
            for(int j=0;j<ry-wordSize;++j){
                if(word==note.notes.at(rx-1).substr(j,wordSize)){
                    ++res;
                }
            }
        }
    }
    return res;
}
void opfind(string word){// operation of "FIND"
    if(so.selected){//当前处于选中状态
        cout<<cntWord(word,false)<<"\n";
    }else{
        cout<<cntWord(word)<<"\n";
    }
}
ll cntChs(bool global=true){// count visible character in the chosed area
    ll res=0;
    int l=32,r=127;//(l,r)
    // '\0':32  '\n':10
    int tmpi,tmpj;
    if(global){
        for(auto &x:note.notes){
            for(int i=0;i<x.size();++i){//c1
                if(x[i]>l&&x[i]<r){
                    ++res;
                }
            }
        }
    }else{
        int lx=so.selectArea.first.x,
            ly=so.selectArea.first.y,
            rx=so.selectArea.second.x,
            ry=so.selectArea.second.y;
        if(lx+1<rx){//no less than 3 rows
            for(int i=lx;i<rx-1;++i){
                for(int j=0;j<note.notes.at(i).size();++j){//c1
                    if(note.notes.at(i)[j]>l&&note.notes.at(i)[j]<r){
                        ++res;
                    }
                }
            }
        }
        int i=lx-1;//head line
        if(note.notes.at(i).size()-ly>0){//has words
            if(lx==rx) tmpj=ry-1;
            else tmpj=note.notes.at(i).size();//c1
            for(int j=ly-1;j<tmpj;++j){
                if(note.notes.at(i)[j]>l&&note.notes.at(i)[j]<r){
                    ++res;
                }
            }
        }
        if(rx-lx>0&&ry>1){//has words
            i=rx-1;//tail line
            for(int j=0;j<ry-1;++j){
                if(note.notes.at(i)[j]>l&&note.notes.at(i)[j]<r){
                    ++res;
                }
            }
        }
    }
    return res;
}
void opcount(){// operation of "COUNT"
    if(so.selected){
        cout<<cntChs(false)<<"\n";
    }else{
        cout<<cntChs()<<'\n';
    }
}
void opcopy(){// operation of "COPY"
    if(so.selected){// selected
        int lx=so.selectArea.first.x,
            ly=so.selectArea.first.y,
            rx=so.selectArea.second.x,
            ry=so.selectArea.second.y;
        so.clipBoard.clear();// clear the clip board
        if(lx==rx){//一行之内
            so.clipBoard.push_back(note.notes.at(lx-1).substr(ly-1,ry-ly));
        }else{//超过一行
            so.clipBoard.push_back(note.notes.at(lx-1).substr(ly-1,note.notes.at(lx-1).size()-ly+1));//Head
            if(lx+1<rx){//超过2行, >=3行
                for(int i=lx;i<rx-1;++i){
                    so.clipBoard.push_back(note.notes.at(i));
                }
            }
            if(ry>1) so.clipBoard.push_back(note.notes.at(rx-1).substr(0,ry-1));//Tail
        }
    }else{// not selected, then copy current row, '\n' is not included
        int lineLen=note.lineLen();
        if(lineLen>1){
            so.clipBoard.clear();
            so.clipBoard.push_back(note.notes.at(cs.x-1));
            so.clipBoard.back().erase(so.clipBoard.back().size()-1);
        }
    }
}
void opprint(){// operation of "PRINT"
    for(auto &x:note.notes)
        cout<<x;
}
void chOp(string op){// summary of operations
    string s;
    if(op=="MOVE"){
        cin>>s;
        opmove(s);++vi[0];
    }else if(op=="INSERT"){
        cin>>s;
        opinsert(s);++vi[1];
    }else if(op=="REMOVE"){
        cin>>s;
        opremove(s);++vi[2];
    }else if(op=="SHIFT"){
        opshift();++vi[3];
    }else if(op=="FIND"){
        cin>>s;
        opfind(s);++vi[4];
    }else if(op=="COUNT"){
        opcount();++vi[5];
    }else if(op=="COPY"){
        opcopy();++vi[6];
    }else if(op=="PRINT"){
        opprint();++vi[7];
    }
}
int main(){// main function
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    string op;
    while(n--){
        cin>>op;
        chOp(op);
        //noteInfo();
    }
    return 0;
}
