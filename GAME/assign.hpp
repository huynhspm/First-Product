#ifndef _assign_
#define _assign_

int image[] = {3, 2, 14, 4, 5, 2, 14, 4, 5, 2, 14, 4, 5, 173, 10};
int color[] = {12, 6, 13, 10, 6, 12, 10, 13, 11, 6, 10, 13, 11, 7, 15};
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void Vemoto(int row, int col, char kitu, int color, Screen &screen){
    if(row > 24 || col > 24) return;
    screen.buffer[row][col].kitu = kitu;
    screen.buffer[row][col].color = color;
}

void Assign(Moto &moto, Screen& screen, Bullet &bullet, Cnv &cnv, Ans &ans, Monster &monster, Phaohoa &ph){
    for(int i = 0; i < 23 && ans.level <= ans.en; ++ i){
        Thamso &a = cnv.t[i];
        if(a.rand < 14) Vemoto(a.row, i, image[a.rand], color[a.rand], screen);
    }

    for(int i = 0; i < 3; ++ i){
        Data &bulti = bullet.t[i];
        for(int j = 0; j < bulti.n; ++ j)
            if(bulti.td[j].row >= 0){
                if(ans.level > ans.en) Vemoto(bulti.td[j].row, bulti.td[j].col, ' ', 0, screen);
                else Vemoto(bulti.td[j].row, bulti.td[j].col, 33, moto.color, screen);

            }
    }

    if(monster.life > 0){
        int a = 15, b = 9;
        if(ans.level > 2) a = 2, b = 3;
        if(ans.level == 5 && monster.time > 7) a = 12;

        if(ans.level == 4){
            for(int i = 0; i < 23; ++ i)
                Vemoto(4, i, '_', 14, screen);
        }

        for(int i = 0; i < 5; ++ i) for(int j = 0; j < 5; ++ j)
            Vemoto(monster.row + i, monster.col + j, monster.a[i][j], a, screen);

        if(ans.level ==  5 && monster. time == monster.limit){
            for(int i = monster.row + 5; i <= 24; ++i)
            for(int j = monster.col; j <= monster.col + 4; j += 2)
                Vemoto(i, j, 179, a, screen);
        }

        if(monster.time >= monster.limit) monster.time = 0;
        for(int i = 0; i < 3; ++ i){
            Data &a = monster.t[i];
            for(int j = 0; j < a.n; ++ j)
                if(a.td[j].row >= 0 && a.td[j].col >= 0)
                    Vemoto(a.td[j].row + 5, a.td[j].col, 15, b, screen);
        }
    }

    for(int i = 0; i < 3; ++ i)
        for(int j = 0; j < 3; ++ j){
            Toado &a = moto.td;
            Vemoto(a.row + i, (a.col + j) % 23, moto.a[i][j], moto.color, screen);
        }

    if(monster.life == 0 && ans.level < ans.en){
        Vemoto(10,  9, 'L', 12, screen);
        Vemoto(10, 10, 'E', 12, screen);
        Vemoto(10, 11, 'V', 12, screen);
        Vemoto(10, 12, 'E', 12, screen);
        Vemoto(10, 13, 'L', 12, screen);
        Vemoto(10, 14, ' ', 12, screen);
        Vemoto(10, 15, char(ans.level + 1 + 48) , 12, screen);
    }

    if(ans.level > ans.en){
        int color = 13;
        for(int i = 0; i < 2; ++ i){

            Vemoto(ph.td[i].row, ph.td[i].col, 15, color + i, screen);
            if(!ph.time) continue;

            for(int j = 0; j < 8; ++ j){

                int row1 = ph.td[i].row, row2 = ph.td[i].row + dx[j] * ph.time;
                int col1 = ph.td[i].col, col2 = ph.td[i].col + dy[j] * ph.time;

                while(row1 != row2 || col1 != col2){
                    Vemoto(row2, col2, 15, color + i, screen);
                    if(row1 == row2) col2 -= dy[j];
                    else if(col1 == col2) row2 -= dx[j];
                    else  row2 -= dx[j], col2 -= dy[j];
                }
            }
        }
    }
}

#endif
