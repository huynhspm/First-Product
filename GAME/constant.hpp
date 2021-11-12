#ifndef _constant_
#define _constant_

#include <stdio.h>
void Constant(){
    for(int i = 0; i < 25; ++ i){
        Textcolor(14);
        Gotoxy(i, 29); putchar(179);
        Gotoxy(i, 53); putchar(179);
    }

    Textcolor(11);
    Gotoxy(9, 10);
    printf("LEVEL:");

    Gotoxy(11, 10);
    printf("SCORE:");

    Gotoxy(13, 10);
    printf("LIFE:");
}

#endif
