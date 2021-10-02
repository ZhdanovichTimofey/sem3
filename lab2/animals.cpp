#include <iostream>

class Animal {
public:
        void make_a_sound();
};

void Animal::make_a_sound() {
        std::cout << "some abstract sound" << std::endl;
}

class Dog : public Animal {
public:
        unsigned int width;
        unsigned int height;
        void make_a_sound();
};

class Cat : public Animal {
public:
	void make_a_sound();
};

void Cat::make_a_sound() {
	std::cout << "meow" << '\n';
}

void Dog::make_a_sound() {
        std::cout << "woof-woof!" << std::endl;
}

int main()
{
        Animal anima;
        Dog rex;
        Cat cat;
        Animal *pRex = &rex;
        Animal& rRex = rex;
        anima.make_a_sound();
        rex.make_a_sound();
        pRex->make_a_sound();
        rRex.make_a_sound();
        cat.make_a_sound();
        return 0;
}
