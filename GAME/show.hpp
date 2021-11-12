#ifndef _show_
#define _show_

#include <stdio.h>

void Show(Ans &ans,Monster &monster, Screen &screen){
    for(int i = 0 ; i < 25; ++ i){
        Gotoxy(i, 30);
        for(int j = 0 ; j < 23; ++ j){
            Buffer &a = screen.buffer[i][j];
            Textcolor(a.color); putchar(a.kitu);
            a.kitu = ' '; a.color = 15;
        }
    }

    Textcolor(11);
    if(monster.life != 0){ Gotoxy(9, 17); printf("%d ", ans.level); }

    Gotoxy(11, 17); printf("%d", ans.score);

    Gotoxy(13, 16); printf("   ");
    Gotoxy(13, 16); printf("%d", ans.life);

    if(monster.life > 0){
        Textcolor(11);
        Gotoxy(15, 19); printf("          ");
        Gotoxy(15, 10); printf("MONSTER: %d", monster.life);
    }
    else{ Gotoxy(15, 10); printf("              "); }

    if(ans.level > ans.en){
        Gotoxy(11, 60); Textcolor(11); printf("CONGRATULATE !!!.");
        Gotoxy(12, 65); Textcolor(11); printf("YOU WIN");
    }
}


#endif
