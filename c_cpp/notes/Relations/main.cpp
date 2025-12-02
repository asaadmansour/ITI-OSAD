#include <iostream>
#include "Instructor.h"
#include "Room.h"
#include "Marker.h"

using namespace std;
// Cat IS A Animal ;
// Mina IS A Instructor , Employee , BadPerson , GoodPerson , Human
class Base {
    protected:
    int x;
    int y;
    public :
       /* Base():x(0),y(0){
            cout<<"No Parameter Constuctor Base "<<endl;
               // x=0;
               // y=0;
        }*/
        Base(int a, int b):x(a),y(b){
           cout<<"Parameter Constuctor Base "<<endl;
           cout<<"x= " <<x <<"y = "<<y<<endl;
        }
        virtual int sum() const { //this Read Only  Pointer to const
            //this ->x=10;
            cout<<"sum Base "<<endl;
            return x+y;
        }
        ~Base(){
            cout<<"Destructor Base "<<endl;
        }

};

class Derived : public Base {
    int c;
    public :
        Derived(int r, int a ,int b):Base(a,b),c(r){
            //c=r;
           // Base::Base(a,b);
            //c=r;
            cout<<"Constuctor Derived "<<endl;
            cout<<"x= " <<x <<" y = "<<y<<" c= "<<c<<endl;
        }
        //Overriding Static binding
        int sum()const{ //Sum(void)
            cout<<"sum Derived "<<endl;
            //return x+y+c;
            //this   ==> currect Object
            //super  ==> Parent
            //return 0;
            return Base::sum()+c;//Extend Action = Parent Action +New Action

        }
        ~Derived(){
            cout<<"Destructor Derived "<<endl;
        }
};
class Derived2: public Derived {
public :
 Derived2():Derived(0,0,0){
            cout<<"Constructor Derived2 "<<endl;
    }

 ~Derived2(){
            cout<<"Destructor Derived2 "<<endl;
}
};

void display(Base b){
    cout<<b.sum()<<endl;
}
void display2(Derived d){
    cout<<d.sum()<<endl;
}

int main()
{

    Base b(2,5);
    Derived d(3,2,5);
    Derived * pD=&d;
    pD->sum();//CHild
    Base * pB=&b;
    pB->sum();//Base

    //Derived * pD =&b;//Not Valid
    Base * ptr = &d;
    ptr->sum();//Enable Dynamic Binding (use Virtual [With parent] (RunTime)) : sum child
    ptr->sum();//disable Dynamic Binding (don't use Virtual) : Static Binding :sum parent

    //display(d);//Valid
    //display2(b);//Compiler Error
   // Derived * ptr=new Base(2,5);//Compiler Error
    Base * ptr =new Derived(3,2,5);
    ptr->sum(); //Call ??? sum Base , Sum Derived ???
    // cout<<d.sum()<<endl;
    // cout<<d.Base::sum()<<endl;
    //Derived2 d;

    /*
    Instructor mina;
    Room r1;
    Marker m;
    mina.drawOnBoard(m);
    //Association ==> use
    //Aggration Weak ownerShip
    r1.enterInstructor(&mina);
    r1.openRoom();
    r1.lightOn();*/


    cout << "Hello world!" << endl;
    return 0;
}


//              OwnerClass          Dervied Class              Out of class main
//public             yes                  yes                          yes
//private            yes                  No                           No
//protected          yes                  yes                          No
