#ifndef _levelmonster_
#define _levelmonster_

#include <bits/stdc++.h>
using namespace std;

int d_row[] = {-1, 1, 1, -1};
int d_col[] = {1, 1, -1, -1};

void Prepare_level1(Monster &monster){
    monster.dem ++; monster.col = monster.row = monster.time = 0;
    monster.life = monster.dem * monster.cons; monster.sleep = 10;
    monster.limit = 7;

    for(int i = 0; i < 3 ; i = i + 2){
        Data &a = monster.t[i];
        a.n = 1; a.st = 0;
        a.td[0].row = 0; a.td[0].col = i * 2;
    }
}

void Prepare_level2(Monster &monster){
    monster.dem ++; monster.col = monster.row = monster.time = 0;
    monster.life = monster.dem * monster.cons;
    monster.limit = 7; monster.sleep = 10;

    for(int i = 0; i < 3; ++ i){
        Data &a = monster.t[i];
        a.n = 1; a.st = 0;
        a.td[0].row = 0; a.td[0].col = i * 2;
    }
}


void Direct(Toado &td, Ans &ans){
    if(td.row == 0){
        if(td.col == 0) td.direct = 1;
        else if(td.col == 22) td.direct = 2;
        else td.direct = (rand() % 2) + 1;
        return;
    }

    if(ans.level == 3){
        if(td.col == 0) td.direct = 1;
        if(td.col == 22) td.direct = 2;
    }
    else if(ans.level == 4){
        if(td.col == 0){
            if(td.row == 0) td.direct = 1;
            else if(td.row == 19) td.direct = 0;
            else td.direct = (rand() % 2);
        }
        else if(td.col == 22){
            if(td.row == 0) td.direct = 2;
            else if(td.row == 19) td.direct = 3;
            else td.direct = (rand() % 2) + 2;
        }
        else if(td.row == 19){
            if(td.col == 22) td.direct = 3;
            else if(td.col == 0) td.direct = 0;
            else td.direct = ((rand() % 2) + 3) % 4;
        }
    }
}

void Prepare_level3(Monster &monster, Ans &ans){
    monster.dem ++; monster.col = monster.row = monster.time = 0;
    monster.life = monster.dem * monster.cons;
    monster.limit = 5; monster.sleep = 10;

    Data &a = monster.t[1];
    a.n = 1; a.st = 0;
    a.td[0].row = 0; a.td[0].col = 2;
    Direct(a.td[0], ans);

    monster.t[0].n = monster.t[2].n = 0;
}

void Prepare_level4(Monster &monster, Ans &ans){
    monster.dem ++; monster.col = monster.row = monster.time = 0;
    monster.life = monster.dem * monster.cons;
    monster.limit = 6; monster.sleep = 10;

    Data &a = monster.t[1];
    a.n = 1;
    a.td[0].row = 0; a.td[0].col = 2;
    Direct(a.td[0], ans);

    monster.t[0].n = monster.t[2].n = 0;
}

void Prepare_level5(Monster &monster){
    monster.dem ++; monster.col = 5; monster.row = 0; monster.time = 0;
    monster.life = monster.dem * monster.cons; monster.sleep = 10;
    monster.limit = 15;
}

void Bullet_monster(Monster &monster, Ans &ans, Moto &moto){
    monster.time ++;
    if(ans.level == 5){
        if(monster. time == monster.limit){
            for(int j = monster.col; j <= monster.col + 4; j += 2)
                for(int idem = 0; idem < 3; idem ++)
                    if(j == (moto.td.col + idem) % 23){
                        ans.life -= ans.hack; break;
                    }
        }
        return;
    }

    for(int i = 0; i < 3; ++ i){
        Data &a = monster.t[i];
        if(a.n > 0){
            for(int j = 0 ; j < a.n; ++ j){
                if(a.td[j].col == -1) continue;;
                if(ans.level < 3) a.td[j].row ++;
                else{
                    a.td[j].row += d_row[a.td[j].direct];
                    a.td[j].col += d_col[a.td[j].direct];
                    Direct(a.td[j], ans);
                }

                if(a.td[j].row > 19) a.td[j].col = -1;
                if(a.td[j].row >= 17 && a.td[j].col > -1){
                    for(int idem = 0; idem < 3; idem ++)
                    if(a.td[j].col == (moto.td.col + idem) % 23){
                        ans.life -= ans.hack; a.td[j].col = -1;
                        break;
                    }
                }
            }

            if(monster.time >= monster.limit){
                if(ans.level == 4){
                    if(a.n < 7 && i == 1){
                        a.td[a.n].row = 0; a.td[a.n].col = monster.col + 2;
                        Direct(a.td[a.n], ans); a.n++;
                    }
                    continue;
                }

                int k = i * 2;
                a.n = min(20, (a.n + 1));
                a.st = (a.st + 1) % 20;
                a.td[a.st].col = monster.col + k;
                a.td[a.st].row = 0;
                if(ans.level == 3) Direct(a.td[a.st], ans);
            }
        }
    }
}


#endif

