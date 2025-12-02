#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "Instructor.h"
#include "Wall.h"
using namespace std;
class Room
{
    public:
    Instructor * s;
    //Wall w[4]; //Allocation , Deallocation Automatic
    Wall* ptr;
    Room(Instructor * s){
            this->s=s;
            this->ptr=new Wall[4];
    }
    void enterInstructor(Instructor *s){
            this->s=s;//Assign Instructor
    }
        void openRoom(void){
            if(s == NULL) {
                cout<<"Can't Open Room"<<endl;
            }
            else{
                cout<<"Good Instructor Ok"<<endl;
            }
        }
        void lightOn(void){
            if(s == NULL) {
                cout<<"Can't ON Light"<<endl;
            }
            else{
                cout<<"Good Instructor Ok"<<endl;
            }
        }
       void airOn(void){
            if(s == NULL) {
                cout<<"Can't ON Air"<<endl;
            }
            else{
                cout<<"Good Instructor Ok";
            }
        }

        ~Room() {
            delete [] ptr;
        }

    protected:

    private:
};

#endif // ROOM_H
