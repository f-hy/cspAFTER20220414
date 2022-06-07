#include <bits/stdc++.h>
#define rep(i, s, t) for(int i=s;i<=t;i++)
using namespace std;

/* 全局变量 */
int n;                   // 猪的数量
queue<char> allCards;    // 牌堆

struct Pig {
/* 属性 */
    int index;            // 当前猪下标
    int hp = 4;           // 血量
    char type;            // 猪的类型: M, Z, F
    char jumpType = 0;    // 跳的类型: Z(忠), F(反), f(MP视角的类反), 0(空), 注意对MP来说针对F更优先于f
    bool arming = false;  // 有无装备
    list<char> cards;     // 手中的牌
/* 方法定义, 这里是完成本题必须的方法, 可以不必多定义了 */
    void jump(){jumpType = type=='F'?'F':'Z';} // 跳阵营
    bool isJumpItsFriend(Pig* pig) { return pig->type == 'F' ? jumpType == 'F' : jumpType == 'Z'; } // 我跳它朋友了吗?
    Pig* getNextPig();    // 获取存活的下家
    void addCards(int num);// 从牌堆拿牌放到自己手右
    bool del(char c);     // 删掉手里一张牌, 删成功则返回true
    void hurt(Pig* attacker);// 被攻击掉一点血
    bool cost(Pig* attacker, char c);// 被迫消耗手中一张牌, 消耗成功返回true并不减血, 否则减血, 减血到0尝试用桃, 无则死亡, 根据身份对杀者做后续处理
    bool useP();          // 主动使用桃, 满足使用条件就使用, 使用后返回true
    bool useK();          // 主动使用杀, 满足使用条件就使用, 使用后返回true
    bool useF();          // 主动使用决斗, 满足使用条件就使用, 使用后返回true
    bool useN();          // 主动使用南猪入侵, 满足使用条件就使用, 使用后返回true
    bool useW();          // 主动使用万箭齐发, 满足使用条件就使用, 使用后返回true
    bool findJ(Pig* attacker); // 被迫去求无懈可击, 求到则返回true
    bool useJ(Pig* pig);  // 帮某个猪用无懈可击, 用成功返回true
} ps[15];

/* 全局方法 */
bool isGameEnd() {
    if (ps[0].hp <= 0) return true;
    rep(i, 1, n-1)
        if (ps[i].type == 'F' && ps[i].hp > 0)
            return false;
    return true;
}
int cnt = 0;
void judgeGameEnd() {
    if (isGameEnd()) {
        printf(ps[0].hp > 0 ? "MP\n" : "FP\n");
        rep(i, 0, n-1) {
            if (ps[i].hp <= 0) {
                printf("DEAD\n");
            } else {
                for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++)
                    printf(it==ps[i].cards.end()?"%c":"%c ", *it);
                printf("\n");
            }
        }

        exit(0);
    }
}

void solve() {
    ps[0].jump();
    while (true) {
        rep(i, 0, n-1) {
            if (ps[i].hp <= 0) continue;
            ps[i].addCards(2);
            bool usedK = false;
            for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++) {
                bool used = false;
                char c = *it;
                it = ps[i].cards.erase(it);
                switch (c) {
                    case 'P': used = ps[i].useP(); break;
                    case 'K': if (!usedK || ps[i].arming) used = usedK = ps[i].useK(); break;
                    case 'F': used = ps[i].useF(); break;
                    case 'N': used = ps[i].useN(); break;
                    case 'W': used = ps[i].useW(); break;
                    case 'Z': ps[i].arming = used = true; break;
                }
                if (used) it = --ps[i].cards.begin();
                else it = ps[i].cards.insert(it, c);
                if (ps[i].hp <= 0) break;
            }
        }
    }
}
/* 主控方法 */
int main() {
    // Input
    int m; scanf("%d%d", &n, &m);
    char s[5];
    rep(i, 0, n-1) {
        ps[i].index = i;
        scanf("%s", s), ps[i].type = s[0];
        rep(j, 1, 4) scanf("%s", s), ps[i].cards.push_back(s[0]);
    }
    while(m--) scanf("%s", s), allCards.push(s[0]);
    // To solve
    solve();
}

Pig* Pig::getNextPig() {
    int nxt = (index + 1) % n;
    while (ps[nxt].hp <= 0) {
        nxt = (nxt+1) % n;
    }
    return &ps[nxt];
}

void Pig::addCards(int num) {
    rep(i,1,num) {
        cards.push_back(allCards.front());
        allCards.pop();
    }
}

bool Pig::useP() {
    if (hp < 4) {
        hp ++;
        return true;
    }
    return false;
}

void Pig::hurt(Pig *attacker) {
    if (--hp == 0) {
        if (this->del('P')) {
            this->useP();
        } else {
            judgeGameEnd();
            switch(type) {
                case 'F': attacker->addCards(3); break;
                case 'Z': if (attacker->type == 'M') attacker->cards.clear(), attacker->arming=false; break;
            }
        }
    }
}

bool Pig::cost(Pig* attacker, char c) {
    if (this->del(c)) {
        return true;
    }
    hurt(attacker);
    return false;
}

bool Pig::findJ(Pig *attacker) {//
    Pig* nxt = attacker;
    do {
        // "找个好心的猪猪帮我挡刀"
        if (this->isJumpItsFriend(nxt) && nxt->del('J')) {
            nxt->jump();
            return !nxt->useJ(this);
        }
        nxt = nxt->getNextPig();
    } while (nxt != attacker);
    return false;
}

bool Pig::useJ(Pig *pig) {
    for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // "套娃指找找有没有猪猪会阻止我帮别人挡刀"
        if (!this->isJumpItsFriend(nxt) && nxt->del('J')) {
            nxt->jump();
            return !pig->findJ(nxt);
        }
    }
    return false;
}

bool Pig::useK() {
    // TODO: 补全代码
    bool flag=false;
    if(this->type=='M'){
//对于每种表敌意的方式，对逆时针方向能够执行到的第一只已跳反猪表；如果没有，对逆时针方向能够执行到的第一只类反猪表，再没有，那么就不表敌意；
        if(this->getNextPig()->jumpType=='F'||this->getNextPig()->jumpType=='f'){
            flag=true;
        }
    }else if(this->type=='Z'){
//对于每种表敌意的方式，对「逆时针方向能够执行到的第一只已经跳反的猪」表，如果没有，那么就不表敌意；
        if(this->getNextPig()->jumpType=='F'){
            flag=true;
        }
    }else if(this->type=='F'){
//对于每种表敌意的方式，如果有机会则对主猪表，否则，对「逆时针方向能够执行到的第一只已经跳忠的猪」表，如果没有，那么就不表敌意；
        if(this->getNextPig()->jumpType=='M'||this->getNextPig()->jumpType=='Z'){
            flag=true;
        }
    }
    if(flag){//表敌意则确认出牌
        this->jump();//跳身份
        this->getNextPig()->cost(this,'D');//被表敌意者被迫弃置闪
        return true;
    }
    return false;
}
bool Pig::useF(){
    // TODO: 补全代码
    if(this->type=='M'){
//对于每种表敌意的方式，对逆时针方向能够执行到的第一只已跳反猪表；如果没有，对逆时针方向能够执行到的第一只类反猪表，再没有，那么就不表敌意；
//决斗时，如果对方是主猪，那么不会弃置杀，否则，会不遗余力弃置杀；
        for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            if(nxt->jumpType=='F'){//主猪对反猪决斗
                if(nxt->findJ(this)){return true;}//寻求无懈可击
                while(nxt->cost(this,'K')){//决斗出杀阶段
                    if(!this->cost(nxt,'K')){
                        break;
                    }
                }
                return true;
            }
        }
        for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            if(nxt->jumpType=='f'){//没有已跳反猪，则主猪对类反猪决斗
                if(nxt->findJ(this)){return true;}//寻求无懈可击
                if(nxt->type=='Z'){//类反猪是忠猪
                    nxt->hurt(this);
                    return true;
                }
                while(nxt->cost(this,'K')){//决斗出杀阶段
                    if(!this->cost(nxt,'K')){
                        break;
                    }
                }
                return true;
            }
        }
    }else if(this->type=='Z'){
//对于每种表敌意的方式，对「逆时针方向能够执行到的第一只已经跳反的猪」表，如果没有，那么就不表敌意；
        for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            if(nxt->jumpType=='F'){
                this->jump();//跳身份
                if(nxt->findJ(this)){return true;}//寻求无懈可击
                while(nxt->cost(this,'K')){//决斗出杀阶段
                    if(!this->cost(nxt,'K')){
                        break;
                    }
                }
                return true;
            }
        }
    }else if(this->type=='F'){
//对于每种表敌意的方式，如果有机会则对主猪表，否则，对「逆时针方向能够执行到的第一只已经跳忠的猪」表，如果没有，那么就不表敌意；
        this->jump();//跳身份
        if(ps[0].findJ(this)){return true;}//寻求无懈可击
        while(ps[0].cost(this,'K')){//决斗出杀阶段
            if(!this->cost(&ps[0],'K')){
                break;
            }
        }
        return true;
    }
    return false;
}
bool Pig::useN() {
    for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // TODO: 补全代码
        if(nxt->findJ(this)){continue;}//寻求无懈可击
        if(!nxt->cost(this,'K')){//扣血
            if(nxt->type=='M'&&this->jumpType==0){//对象是主猪,且使用者未跳身份
                this->jumpType='f';
            }
        }
    }
    return true;
}
bool Pig::useW() {
    for (Pig* nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // TODO: 补全代码
        if(nxt->findJ(this)){continue;}//寻求无懈可击
        if(!nxt->cost(this,'D')){//扣血
            if(nxt->type=='M'&&this->jumpType==0){//对象是主猪,且使用者未跳身份
                this->jumpType='f';
            }
        }
    }
    return true;
}
bool Pig::del(char c) {
    // TODO: 补全代码
    for(auto it=this->cards.begin();it!=this->cards.end();++it){
        if(*it==c){//比较牌是否为c，是则删除并返回true
            this->cards.erase(it);
            return true;
        }
    }
    return false;
}
