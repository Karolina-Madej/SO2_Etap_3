#include "People.h"
#include <condition_variable>


class Lift {
public:
    int x, y; 
    float screenX, screenY;
    //wspolrzedne wektora przesuniecia
    int xVectora, yVectora;
     std::condition_variable cv;
     int stopX;
     int index=-1;
     int counter;

    

    Lift( int, int);
    ~Lift();
    void moveLift();
    void drawLift();
    bool isPeopleInLift(People *people);
    bool isLift(Lift *lift);
    bool hasPeople();
    void releasePeople();
    void increaseCounter();
 


};