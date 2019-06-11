#include <ncurses.h>
#include "People.h"
#include <condition_variable>


People::People( int initX, int initY,int peopleId) {
   

    screenX = initX;
    screenY = initY;

    x=23;
    y=0;

    xVectora = -1;
    yVectora = 0;
    stopX= x;

   this->peopleId=peopleId;



}
 bool People::arePeople(People *people) {

        return (this->y == screenY/2-39) ;
      

 }
void People::changeVector(){

    this->xVectora=0;
    this->yVectora=1;
}
void People::movePeople() {
   

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

void People::drawPeople() {

  
    move(x,y);
    printw("cz");
 }

 void People::deletePeople() {

        printw("  "); 
    
 
 }

