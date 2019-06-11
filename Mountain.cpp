#include <ncurses.h>
#include "Mountain.h"

Mountain::Mountain(int initX, int initY){

    screenX = initX;
    screenY = initY;

    x = 23;
    y = 60;
}

void Mountain::drawMountain() {
    
    for(int i =0;i<20;i++){
        move(x-i,y+i); 
        printw("/");
    }

   
 }

void Mountain::drawSecondMountain() {
    
    for(int i =0;i<20;i++){
        move(x-i,y-41-i); 
        printw("|");
    }

   
 }