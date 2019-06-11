#include "Screen.h"
#include "Mountain.h"
#include "Lift.h"
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <queue>
#include "SafeQueue.cpp"



using namespace std;

condition_variable cv;
condition_variable cv1;
condition_variable cv2;

queue<int> peoplesIn;


condition_variable* queueCV;


Screen *screen;
Mountain *mountain;
Lift *lift;
People *p;
bool flag = true;
vector<thread> threads;
vector<People*> peoples;
condition_variable *con;
int peopleCounter = 0;
mutex mtx, mtx2;
SafeQueue<People*> peopleQueue; 

    int tempo=5;



void refreshScreen(){

    while(flag) {
        clear();
            mountain->drawMountain();
            mountain->drawSecondMountain();
            lift->drawLift();
                for (int i = 0; i < peoples.size(); i++) {
             
                     peoples[i]->drawPeople();
              
                 }
                 
        refresh();
        usleep(20000);
    }
    clear();
    endwin();
}

void escape(){
    int inputChar;
    while(flag){
        inputChar = getch();
        if(inputChar == 'q'){
            flag= false;
        }
    }
}

void makeMountain(){
    float x = screen->getScreenWidth();
    float y = screen->getScreenHeight();

     mountain = new Mountain(x, y);
     usleep(50000);

}



void moveLift(Lift *lift){
 while((flag)){

     lift->moveLift();
     usleep(90000);

     unique_lock<mutex> lck2(mtx2);


    if(lift->isLift(lift)){
        cv.wait(lck2);
        lift->releasePeople();
        //cv1.notify_one();
      //People* pe =peopleQueue.dequeue();
    }
   
     

    

     if(lift->y==0){
        lift->releasePeople();
        cv.wait(lck2);
        cv1.notify_one();    
 }    
         lck2.unlock();

 }

}

void makeNewLift(){
     float x = screen->getScreenWidth();
     float y = screen->getScreenHeight();

     lift=new Lift(x,y);
     moveLift(lift);

     usleep(50000);

}



void movePeople(People *people){
 while((flag)){
     people->movePeople();
     usleep(90000);


    unique_lock<mutex> lck2(mtx2);


    if(lift->isPeopleInLift(people)){

        lift->index=people->peopleId;
        lift->increaseCounter();
    }
    
    lck2.unlock();

     if(lift->hasPeople()){
        cv.notify_all();
     }

    unique_lock<mutex> lck(mtx);



    if(lift->isPeopleInLift(people)){
       people->changeVector();
         if(lift->y==78){
             peoples.erase(std::remove(peoples.begin(), peoples.end(), people), peoples.end());
         }
    }
     if(lift->hasPeople()&&people->x==tempo){
        cv1.wait(lck);  
     }

        lck.unlock();

 }
}

void makeNewPeople(){

    float x = screen->getScreenWidth();
    float y = screen->getScreenHeight();

    short tmp;

 
    while(flag)
    {

        tmp = rand() % 8 +1;
        People *people = new People(x, y, peopleCounter);
        people=new People(x,y, peopleCounter);
        peoples.push_back(people);
   
        threads.push_back(thread(movePeople, peoples.back()));
        peopleQueue.enqueue(people);
        
        usleep(5000000);

        tempo++;
        peopleCounter++;


    }
}


int main() {
    srand(time(NULL));
    screen= new Screen();
    thread generateNewLift(makeNewLift);
    thread generateNewPeople(makeNewPeople);
    thread generateMountain(makeMountain);
    thread refreshScreenThread(refreshScreen);
    thread escapeThread(escape);
    
    
    escapeThread.join();
    generateNewLift.join();
    generateNewPeople.join();
    refreshScreenThread.join();
    generateMountain.join();


    for(int i = 0; i<threads.size(); i++){
        threads[i].join();
    }
    

    endwin();
    return 0;

}

