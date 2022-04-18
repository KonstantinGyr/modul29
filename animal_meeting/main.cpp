#include <iostream>
class Dog;
class Cat;

class Animal{
public:
    virtual void meeting(Dog* dog)=0;
    virtual void meeting(Cat* cat)=0;
    virtual void meeting(Animal* animal)=0;
};

class Dog : public Animal{
public:
    Dog(){};
    void meeting(Dog* dog) {
        std::cout << "Woof Woof\n";
    }
    void meeting(Cat* cat){
        std::cout<<"Meow Bark \n";
    }
    void meeting (Animal* animal){
        animal->meeting(this);
    }
};

class Cat : public Animal{
public:
    Cat()=default;
    void meeting(Dog* dog){
        std::cout<<"Bark Meow \n";
    }
    void meeting(Cat* cat) {
        std::cout << "Purr Purr\n";
    }
    void meeting (Animal* animal){
        animal->meeting(this);
    }
};

void meetings (Animal& a,Animal& b){
    a.meeting(&b);
}

int main() {
    Dog d;
    Cat c;
    meetings(d,d);
    meetings(c,d);
    meetings(d,c);
    meetings(c,c);
    return 0;
}
