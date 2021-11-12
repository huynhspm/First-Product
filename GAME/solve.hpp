#ifndef _solve_
#define _solve_

#include<bits/stdc++.h>
#include "levelmonster.hpp"
#include "assign.hpp"
using namespace std;

void Solve_bullet(Moto &moto, Data &bullet, Bien &bien, Cnv &cnv, Ans &ans, Monster &monster){
    for(int i = 0; i < bullet.n; ++ i){
        Toado &a = bullet.td[i];
        a.row = (a.row - 1) % 22;

        if(monster.life > 0 && a.row >= 0){
            if(a.row < 5 && monster.col <= a.col && a.col <= monster.col + 4){
                monster.life --;
                a.row = -1;
                if(monster.life < 0) monster.life = 0;
            }
        }

        if(a.col < 0) continue;
        Thamso &b = cnv.t[a.col];

        if(b.rand < 14 && a.row - b.row <= 1 && a.row - b.row >= 0){
            if(b.rand == 13) bien.dem++;
            else if(b.rand == 0) ans.life ++;
            else ans.score ++;

            moto.color = color[b.rand];
            b.rand = 14;
        }
    }
    bullet.dem ++;
    if(bullet.dem % 2){
        bullet.n = min(11, (bullet.n + 1));
        bullet.st = (bullet.st + 1) % 11;
        bullet.td[bullet.st].col = (moto.td.col + bien.k) % 23;
        bullet.td[bullet.st].row = 21;
    }
}

void Solve_monster(Monster &monster, Ans &ans, Moto &moto, int &cnt){
    if(monster.life == -1){
        if(ans.score >= 10 && monster.dem == 0) Prepare_level1(monster);
        else if(ans.score >= 25 && monster.dem == 1) Prepare_level2(monster);
        else if(ans.score >= 45 && monster.dem == 2) Prepare_level3(monster, ans);
        else if(ans.score >= 70 && monster.dem == 3) Prepare_level4(monster, ans);
        else if(ans.score >= 99 && monster.dem == 4) Prepare_level5(monster);
    }
    else if(monster.life > 0) Bullet_monster(monster, ans, moto);
    else if(monster.life == 0){
        monster.sleep--;
        if(monster.sleep == -1){
            ans.level ++; cnt--;
            monster.life = -1;
            monster.t[0].n = monster.t[1].n = monster.t[2].n = 0;
        }
    }
}

void Solve_cnv(Cnv &cnv, Ans &ans, int kt, int id){
    for(int i = 0; i < 23; ++ i){
        Thamso &a = cnv.t[i];
        if(a.rand < 14){
            if(a.row >= 21){
                if(a.rand != 0 && a.rand != 13) ans.life -= ans.hack;
                a.rand = 14;
            }
            else a.row ++;
        }
    }
    if(kt < 0){
        if(cnv.time > cnv.limit){
            int x;
            while(true){
                x = rand() % 23;
                if(cnv.t[x].rand == 14) break;
            }
            while(true){
                cnv.t[x] = Thamso{0, (rand() + rand()) % 14};
                if(id && cnv.t[x].rand == 13)  continue;
                if(ans.life >= 15 && cnv.t[x].rand == 0) continue;
                break;
            }
            cnv.time = 0;
        }
        cnv.time++;
    }
}

bool Solve(Moto &moto, Bullet &bullet, Cnv &cnv, Ans &ans, Monster &monster, Phaohoa &ph){
    if(ans.level > ans.en){
        if(ph.td[0].row > 8) ph.td[0].row --, ph.td[1].row --;
        else ph.time ++;
        return false;
    }

    Bien bien = Bien{0, 0}; int cnt = ans.life;
    for(int i = 0; i < 3; ++ i)
        if(bullet.t[i].n > 0){
            bien.k = i;
            Solve_bullet(moto, bullet.t[i], bien, cnv, ans, monster);
        }

    Solve_monster(monster, ans, moto, cnv.limit);

    Solve_cnv(cnv, ans, monster.life, bullet.t[2].n);

    if(ans.life < 0) return true;

    while(bien.dem-- > 0){
        for(int i = 0; i < 3; ++ i){
            Data &a = bullet.t[i];
            if(a.n == 0){
                a.n = 1; bullet.t[i].st = 0; a.dem = bullet.t[1].dem % 2;
                a.td[0] = Toado{ 21, moto.td.col + i};
                break;
            }
        }
    }

    if(ans.life < cnt){
        if(bullet.t[2].n) bullet.t[2].n = 0;
        else bullet.t[0].n = 0;
    }

    return false;
}


#endif
