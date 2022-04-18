#include <iostream>

class Animal{
public:
    virtual void voiceBro()=0;
    virtual void voice()=0;

};
class Dog:virtual public Animal{
public:
    virtual void voiceBro(){
        std::cout<<"Woof ";
    }
    virtual void voice(){
        std::cout<<"Bark ";
    }
};

class Cat:virtual public Animal{
public:
    virtual void voiceBro(){
        std::cout<<"Purr ";
    }
    virtual void voice(){
        std::cout<<"Meow ";
    }
};

void meeting1(Cat& c1,Cat& c2){
    c1.voiceBro();
    c2.voiceBro();
    std::cout<<std::endl;
}
void meeting2(Cat& c,Dog& d) {
    c.voice();
    d.voice();
    std::cout << std::endl;
}
void meeting3(Dog& d1,Dog& d2) {
    d1.voiceBro();
    d2.voiceBro();
    std::cout << std::endl;
}
void meeting4(Dog& d,Cat& c) {
    d.voice();
    c.voice();
    std::cout << std::endl;
}

void meetings (Animal& a,Animal& b) {
    if(Cat* animal1=dynamic_cast<Cat*>(&a)){
        if(Cat* animal2=dynamic_cast<Cat*>(&b)){
            meeting1(*animal1,*animal2);
        }
        else if (Dog*animal2=dynamic_cast<Dog*>(&b)){
            meeting2(*animal1,*animal2);
        }
    }else if(Dog* animal1=dynamic_cast<Dog*>(&a)){
        if(Dog* animal2=dynamic_cast<Dog*>(&b)){
            meeting3(*animal1,*animal2);
        }
        else if(Cat* animal2=dynamic_cast<Cat*>(&b)){
            meeting4(*animal1,*animal2);
        }
    }

}
int main() {
    Dog d;
    Cat c;
    meetings(d,d);
    meetings(c,d);
    meetings(c,c);
    meetings(d,c);
    return 0;
}
