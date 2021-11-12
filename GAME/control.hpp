#ifndef _control_
#define _control_

#include "levelmonster.hpp"
void Direct(int &row, int &col, int &direct, int limit_row, int limit_col){
    if(row == 0){
        if(col == 0) direct = 1;
        else if(col == limit_col) direct = 2;
        else direct = (rand() % 2) + 1;
        return;
    }
    else if(col == 0){
        if(row == limit_row) direct = 0;
        else direct = (rand() % 2);
    }
    else if(col == limit_col){
        if(row == limit_row) direct = 3;
        else direct = (rand() % 2) + 2;
    }
    else if(row == limit_row) direct = ((rand() % 2) + 3) % 4;
}

void Control(Moto &moto, Monster &monster, Ans& ans){
    int keyA = GetAsyncKeyState('A');
    int keyD = GetAsyncKeyState('D');
    int keyP = GetAsyncKeyState('P');
    int keyH = GetAsyncKeyState('H');
    int keyK = GetAsyncKeyState('K');


    if(keyH) ans.hack = 0; else if(keyK) ans.hack = 1;
    if(keyP){
        while(true){
            Sleep(1);
            if(GetAsyncKeyState('C')) break;
        }
    }

    if (keyA) moto.td.col = (moto.td.col - 1 + 23) % 23;
    else if (keyD) moto.td.col = (moto.td.col + 1) % 23;

    if(monster.life > 0){
        if(ans.level == 5){
            Direct(monster.row, monster.col, monster.direct, 7, 18);
            monster.row += d_row[monster.direct];
            monster.col += d_col[monster.direct];
            return;
        }

        if(monster.col >= 18) monster.cnt = -1;
        else if(monster.col <= 0) monster.cnt = 1;
        monster.col = monster.col + monster.cnt;
    }
}
#endif

