#include <bits/stdc++.h>
using namespace std;
using std::list;
list<char> notes;
#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
typedef long long ll;
int n;

bool sel_ing = false;//
bool sel_ed = false;//
list<char>::iterator sl;//
list<char>::iterator sr;//
ll slen=0;//
list<char>::iterator cursor;
string clipBoard;
enum insertType{CH, ENTER, SPACE};
void init(){cursor=notes.begin();}
void del_sel();
void insert(insertType it,char c){
    if(sel_ing) return;
    if(sel_ed){del_sel();}
    if(it==ENTER)c='\n';
    if(it==SPACE)c=' ';
    cursor=notes.insert(cursor,c);
    cursor++;
}
void paste(){
    if(sel_ing||clipBoard.size()==0) return;
    if(sel_ed){del_sel();}
    for (auto &c:clipBoard){insert(CH, c);}
}
bool left(){
    if(sel_ed)sel_ed=false;
    if (cursor!=notes.begin())cursor--;
    else return false;
    slen--;
    return true;
}
bool right(){
    if(sel_ed)sel_ed=false;
    if(cursor!=notes.end()) cursor++;
    else return false;
    slen++;
    return true;
}
ll home(){
    list<char>::iterator cc=cursor;
    if(sel_ed) sel_ed=false;
    ll t=0;
    if(*(--cc)!='\n') t+=left();
    else return t;
    while(*(--cc)!='\n'&&left()){ t++;}
    return t;
}
ll end(){
    list<char>::iterator cc=cursor;
    if(sel_ed) sel_ed=false;
    ll t=0;
    if(*(cc++)!='\n') t+=right();
    else return t;
    while(*(cc++)!='\n'&&right()){t++;}
    return t;
}
void up(){
    ll ind=home();
    left();
    home();
    while(ind>0&&*cursor!='\n'){right();ind--;}
}
void down(){
    ll ind = home();
    end();
    if (!right()) home();
    while (ind > 0 && *cursor != '\n'){right();ind--;}
}
void del(bool mask = true);
void del_sel(){
    if (sel_ed){
        cursor = sl;
        for (ll i = 0; i < std::abs(slen); i++){del(false);}
    }
    sel_ed = false;
}
void del(bool mask){
    if(sel_ing) return;
    if(sel_ed && mask) return del_sel();
    if(cursor != notes.end()) cursor = notes.erase(cursor);
}
void backspace(){
    if (sel_ing) return;
    if (sel_ed) return del_sel();
    if (left()) del();
}
void print(bool end = false){
    bool preisln = false;
    if (end) std::cout << "\n<<\n";
    for (list<char>::iterator it = notes.begin(); it != notes.end(); it++){
        if (cursor == it && end) cout << "|";
        if (sl == it && sel_ed && end) cout << "{";
        if (sl == it && sel_ing && end) cout << "^";
        if (sr == it && sel_ed && end) cout << "}"; cout << *it;
        preisln = *it == '\n';
    }
    if (cursor == notes.end() && end) cout << "|";
    if (sl == notes.end() && sel_ed && end) cout << "{";
    if (sl == notes.end() && sel_ing && end) cout << "^";
    if (sr == notes.end() && sel_ed && end) cout << "}";
    if (!preisln) cout<<endl;
    if (end) cout << "\n>>" << " S L " << slen << " |" << "\n";
}
int find(string s){
    ll t = 0;
    list<char>::iterator fl = notes.begin(), fr = notes.end();
    if (sel_ed){fl = sl;fr = sr;}
    while (fl != fr){
        bool same = true;
        list<char>::iterator it = fl;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != *it){same = false;break;}
            it++;
        }
        t += same;
        fl++;
    }
    return t;
}
void copy(){
    if (sel_ed){
        list<char>::iterator it = sl;
        clipBoard = "";
        while (it != sr){clipBoard.push_back(*it++);}
    }else{
        ll pos = home();
        string backup = clipBoard;
        list<char>::iterator cl, cr;
        cl = cursor;
        end();
        cr = cursor;
        clipBoard = "";
        while (cl != cr){clipBoard.push_back(*cl++);}
        if (clipBoard.size() == 0) clipBoard = backup;
        home();
        for (ll i = 0; i < pos; i++){right();}
    }
}
ll count(){
    ll t = 0;
    list<char>::iterator fl = notes.begin(), fr = notes.end();
    if (sel_ed){fl = sl;fr = sr;}
    while (fl != fr){
        if (*fl != ' ' && *fl != '\n') t++;
        fl++;
    }
    return t;
}
void base(string s, ll c){
    for (auto i : s){insert(CH, i);}
    for (ll i = 0; i < c; i++){left();}
}
void chOp(string op){
    string cmd;
    if(op=="MOVE"){
        cin>>cmd;
        if(cmd=="Home"){
            left();
        }else if(cmd=="End"){
            end();
        }else if(cmd=="Up"){
            up();
        }else if(cmd=="Down"){
            down();
        }else if(cmd=="Left"){
            left();
        }else if(cmd=="Right"){
            right();
        }
    }else if(op=="INSERT"){
        cin>>cmd;
        if(cmd=="Char"){
            char c;cin>>c;
            insert(CH,c);
        }else if(cmd=="Enter"){
            insert(ENTER,0);
        }else if(cmd=="Space"){
            insert(SPACE,0);
        }else if(cmd=="Paste"){
            paste();
        }
    }else if(op=="REMOVE"){
        cin>>cmd;
        if(cmd=="Del"){
            del();
        }else if(cmd=="Backspace"){
            backspace();
        }
    }else if(op=="SHIFT"){
        if(sel_ing){
            sel_ing=false;
            sr=cursor;
            if(slen<0){
                swap(sl,sr);
            }
            if(slen!=0) sel_ed=true;
            else sel_ed=false;
        }else if(sel_ed){
            sel_ing=true;
            sel_ed=false;
            sl=cursor;
            slen=0;
        }else{
            sel_ing=true;
            sel_ed=false;
            if(slen<0){
                swap(sl,sr);
            }
        }
    }else if(op=="FIND"){
        cin>>cmd;
        cout<<find(cmd)<<'\n';
    }else if(op=="COUNT"){
        cout<<count()<<'\n';
    }else if(op=="COPY"){
        copy();
    }else if(op=="PRINT"){
        print();
    }
}
int main(){
    ios::sync_with_stdio(false);
    file(data);
    cin>>n;
    string op;
    while(n--){
        cin>>op;
        chOp(op);
    }
    return 0;
}