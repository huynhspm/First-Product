#ifndef _public_
#define _public_

struct Toado{
    int row, col, direct;
};

struct Moto{
    Toado td;
    int color;
    char a[3][3];
};

struct Data{
    int n, st, dem;
    Toado td[25];
};

struct Bullet{
    Data t[3];
};

struct Monster{
    int col, row, direct;
    int life, dem,  time, limit, cnt, sleep, cons;
    char a[5][5];
    Data t[3];
};

struct Buffer{
    char kitu;
    int color;
};

struct Screen{
    Buffer buffer[25][25];
};

struct Thamso{
    int row, rand;
};

struct Ans{
    int life, score, level, en, hack;
};

struct Cnv{
    int time, limit;
    Thamso t[23];
};

struct Bien{
    int k, dem;
};

struct Phaohoa{
    int time;
    Toado td[2];
};
#endif
