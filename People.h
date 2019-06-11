#include <condition_variable>


class People{
public:
    int x, y; 
    float screenX, screenY;
    //wspolrzedne wektora przesuniecia
    int xVectora, yVectora;
    std::condition_variable cv;    
    int stopX;
    int peopleId; 

    std::condition_variable* lastInQueue;
    std::condition_variable* firstInQueue;

    

    People( int, int,int);
    void movePeople();
    void drawPeople();
    void changeVector();
    bool arePeople(People *people);
    void deletePeople();
    

};