#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#include "console.hpp"
#include "public.hpp"
#include "prepare.hpp"
#include "assign.hpp"
#include "control.hpp"
#include "solve.hpp"
#include "table.hpp"
#include "constant.hpp"
#include "show.hpp"
#include "endgame.hpp"
using namespace std;

Screen screen;
int main(){
    srand(time(NULL));
    while(true){
        Table(); Constant();
        Moto moto; Bullet bullet; Cnv cnv; Ans ans;
        bool check = false; Monster monster; Phaohoa ph;
        Prepare(moto, bullet, cnv, ans, monster, ph);
        while(true){
            Assign(moto, screen, bullet, cnv, ans, monster, ph);
            Show(ans, monster, screen);
            if(check) { Endgame(ans); break; }
            Control(moto, monster, ans);
            if(Solve(moto, bullet, cnv, ans, monster, ph)) check = true;
            if(ph.time >= 5){ Sleep(1000); break; }
            Sleep(30);
        }
    }
}
