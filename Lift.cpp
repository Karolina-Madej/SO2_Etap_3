#include <ncurses.h>
#include "Lift.h"

Lift::Lift( int initX, int initY) {
   

    screenX = initX;
    screenY = initY;

    x=4;
    y = screenY/2-39;

    xVectora = 0;
    yVectora = -1;

    stopX= x;
    

}


bool Lift::isPeopleInLift(People *people) {

        /*return (this->x == people->x) &&
        ((this->y == people->y) ||
        (this->y-1 == people->y ||
        (this->y+1 == people->y)));*/

    return (this->x == people->x);
 }


 bool Lift::hasPeople() {
     return this->index > -1;
 }

void Lift::releasePeople() {
    this->counter = 0;
    this->index = -1;
 }

  void Lift::increaseCounter() {
     if(this->hasPeople())
        this->counter++;
 }



 bool Lift::isLift(Lift *lift) {

        return (this->y == screenY/2-40) ;
      

 }

void Lift::moveLift() {
   

    x += xVectora;
    y += yVectora;


   if( x>= screenX ) {
        xVectora *= -1;
    }

   if(x<=0){
       xVectora *=-1;
     
    }

    if( y >= screenY  ) {
        yVectora *= -1;
    }

   if(y <= 0){
        yVectora *= -1;
        
    }
   
}

void Lift::drawLift() {
   
    move(x,y);
    printw("[ ]");
 }
