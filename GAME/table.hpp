#ifndef _table_
#define _table_

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void Guide(){
    Gotoxy(6, 6);
    printf("MOVE BY (A, D). CHOOSE 'B' TO BACK.");
    Gotoxy(8, 6);
    printf("YOU SHOULD SHOOT HEARTS (%c) AND BULLETS (%c) TO INCREASE LIFE AND BULLET.", 3, 173);
    Gotoxy(10, 6);
    printf("YOU MUST MOVE TO SHOOT ANY THINGS.");
    Gotoxy(12, 6);
    printf("BUT BULLET OF MONSTER (%c) YOU MUST AVOID.", 15);
    Gotoxy(14, 6);
    printf("YOU CAN CHOOSE 'P' TO PAUSE AND 'C' TO CONTINUE.");
    Gotoxy(16, 6);
    printf("PLEASE TURN OFF UNIKEY BEFORE START");
    while(true){
        Sleep(100);
        int keyB = GetAsyncKeyState('B');
        if(keyB) break;
    }
    clrscr();
}

void Output(){
    ifstream infile; int data;
    infile.open("score.text");
    for(int i = 1; i <= 5; ++ i){
        infile >> data;
        Gotoxy(6 + i * 2, 35);
        printf("Rank %d: %d      \n", i, data);
    }
    infile.close();
}

void Reset(){
    int data = 0;
    ofstream outfile;
    outfile.open("score.text");
    for(int i = 0; i < 5; ++ i) outfile << data << endl;
    outfile.close();
    Output();
}

void Score(){
    Gotoxy(14, 35); Textcolor(0); printf("HIGH SCORE");
    Textcolor(15);
    Gotoxy(12, 15); printf("HIGH SCORE :");
    Gotoxy(11, 53); printf("CHOOSE 'B' TO BACK.");
    Gotoxy(13, 53); printf("CHOOSE 'R' TO RESET.");

    Output();
    while(true){
        Sleep(100);

        int keyB = GetAsyncKeyState('B');
        int keyR = GetAsyncKeyState('R');

        if(keyB) break;
        else if(keyR) Reset();
    }
    clrscr();
}

void Table(){
    clrscr();
    string s[3];
    s[0] = "NEW GAME";
    s[1] = "GUIDE";
    s[2] = "HIGH SCORE";
    int cnt = 0;
    while(true){
        for(int i = 0; i < 3; ++ i){
            if(i == cnt) Textcolor(31);
            else Textcolor(15);
            Gotoxy(10 + i * 2, 35);
            cout << s[i];
        }

        if(kbhit()){
            char key = _getch();

            int keyW = GetAsyncKeyState('W');
            int keyS = GetAsyncKeyState('S');
            int keyE = GetAsyncKeyState(char(13));

            if(keyW) cnt = (cnt + 2) % 3;
            else if(keyS) cnt = (cnt + 1) % 3;
            else if(keyE){
                clrscr();
                if(cnt == 0) break;
                else if(cnt == 1) Guide();
                else if(cnt == 2) Score();
            }
        }
        Sleep(50);
    }
}

#endif
