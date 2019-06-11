#include "Screen.h"
#include <ncurses.h>

Screen::Screen(){

    initScreen();
}

Screen::~Screen(){
    endwin(); //zakonczenie curses;
}

float Screen::getScreenWidth() {
    return screenWidth;
}

float Screen::getScreenHeight(){
    return screenHieght;
}

void Screen::initScreen(){
    initscr(); //inicjacja trybu curses
    //raw();// blokuje wyłącznie się programu poprzez naciśnięcie kombinacji klawiczy CTRL + C, CTRL + Z.
    curs_set(FALSE); //wyłączanie kursora
    //clear();
    refresh(); //
    getmaxyx(stdscr, screenWidth, screenHieght);//pobiera właściwości okna stdscr, a dokładniej jego wysokość i szerokość.
    

}