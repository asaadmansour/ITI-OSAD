#ifndef CAR_H
#define CAR_H

class Engine{

};

class Car{
  Engine * eng;
  public:
  Car(Engine * eng ){
      this->eng=eng;
  }
  void setEninge(Engine * eng ){
      this->eng=eng;
  }


};
// car has a Engine
//Engine part of Car
/*int main() {
  Engine Electric;
  Engine Water;
  Car c(&Electric);
  c.setEninge(&Water);
  }*/

#endif // CAR_H
