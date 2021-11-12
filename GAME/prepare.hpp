#ifndef _prepare_
#define _prepare_

void Prepare(Moto &moto, Bullet &bullet, Cnv &cnv, Ans &ans, Monster &monster, Phaohoa &ph){
    moto.td.row = 22; moto.td.col = 10; moto.color = 15;
    moto.a[0][0] = moto.a[0][2] = moto.a[2][0] = moto.a[2][2] = 'O';
    moto.a[1][0] = moto.a[1][2] = 179;
    moto.a[0][1] = '^'; moto.a[2][1] = '_'; moto.a[1][1] = 'x';

    monster.life = 0; monster.dem = 0; monster.sleep = 10; monster.cons = 20;
    monster.t[0].n = monster.t[1].n = monster.t[2].n = 0;
    monster.a[0][0] = monster.a[4][0] = monster.a[0][4] = monster.a[4][4] = monster.a[2][1]
    = monster.a[1][2] = monster.a[1][3] = monster.a[3][1] = monster.a[3][3] = monster.a[2][3] = ' ';
    monster.a[0][1] = monster.a[0][2] = monster.a[0][3] = '_';
    monster.a[4][1] = monster.a[4][2] = monster.a[4][3] = '=';
    monster.a[1][0] = monster.a[3][4] = 47;
    monster.a[2][0] = monster.a[2][4] = 179;
    monster.a[3][0] = monster.a[1][4] = 92;
    monster.a[1][1] = monster.a[1][3] = 'o';
    monster.a[2][2] = '^'; monster.a[3][2] = '-';

    bullet.t[1].n = 1; bullet.t[1].st = 0; bullet.t[1].dem = 1;
    bullet.t[1].td[0] = Toado{21, 11};
    bullet.t[0].n = bullet.t[2].n = 0;

    ph.td[0] = Toado{24, 6}; ph.td[1] = Toado{24, 17}; ph.time = 0;

    ans.level = 0; ans.life = 5; ans.score =  ans.hack = 1;
    ans.en = 5; cnv.time = 0; cnv.limit = 10;
    for(int i = 0; i < 23; ++ i) cnv.t[i].rand = 14;
}

#endif

