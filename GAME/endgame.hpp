#ifndef _endgame_
#define _endgame_

#include <bits/stdc++.h>
using namespace std;

 void Endgame(Ans &ans){
    Gotoxy(11, 60); Textcolor(12);
    printf("GAMEOVER %c %c %c",1 ,1, 1);
    Sleep(2000);

    int data[5];
    ifstream infile;
    infile.open("score.text");
    for(int i = 0; i < 5; ++ i) infile >> data[i];
    infile.close();

    for(int i = 0; i < 5; ++ i)
        if(ans.score > data[i]){
            for(int j = 4; j > i; -- j) data[j] = data[j - 1];
            data[i] = ans.score; break;
        }

    ofstream outfile;
    outfile.open("score.text");
    for(int i = 0; i < 5; ++ i) outfile << data[i] << endl;
    outfile.close();
}

#endif

