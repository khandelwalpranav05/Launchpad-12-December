#include <iostream>

using namespace std;

class Car {
    int speed;
public:
    string name;
    int modelNo;

    Car() {
        cout<<"Starting Empty"<<endl;
    }

    Car(int speed, string name, int modelNo) {
        this->speed = speed;
        this->name = name;
        this->modelNo = modelNo;
        cout<<"Starting with input"<<endl;
    }

    Car(string name,int speed){
        this->name = name;
        this->speed = speed;
    }

    void start() {
        cout << "Starting " << name << endl;
    }

    void setSpeed(int speed){
        if(speed<0){
            return;
        }
        this->speed = speed;
    }

    int getSpeed(){
        return this->speed;
    }

    void displayProperty(){
        cout<<this->name<<endl;
        cout<<this->speed<<endl;
    }

    Car(Car &X){
        this->speed = X.speed;
        this->name = X.name;
        this->modelNo = X.modelNo;
        cout<<"Mera Copy Constructor"<<endl;
    }

    ~Car(){
        cout<<this->name<<" Destroyed!"<<endl;
    }
};

void fun(){
    Car c;
    int a;
}

int main() {

//    cout<<"****** CAR C *******"<<endl;
//    Car c;
////    cout << "**********" << endl;
////    c.speed = 100;
//    c.name = "Honda";
//    c.modelNo = 1;
//
//    c.start();
//    c.setSpeed(-150);
//    cout<<c.getSpeed()<<endl;
//
//    cout<<"*****************"<<endl;

//    cout<<"****** CAR D*******"<<endl;
//    Car d(150,"Ford",2);
//    d.start();
//    cout<<"*****************"<<endl;
//
//    d.displayProperty();
//
//    cout<<"**************"<<endl;
//    Car e(d);
//    Car f = d;
//
//    e.name = "Jaguar";
//    f.name = "Jazz";
//
//    e.displayProperty();
//    int a;
//    float f;
//    char ch;
//    bool b;
//
//    string s1 = "Coding";
//    string s2 = "Blocks";

//    cout<< sizeof(Car)<<endl;
//
//    Car arr[33];

//    sort(arr,arr+n)

    Car* c = new Car("Honda",100);

    delete c;

    return 0;
}