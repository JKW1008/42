#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal* animal = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    
    animal->makeSound(); // "Animal makes a generic sound!"
    dog->makeSound();    // "Woof! Woof!"
    cat->makeSound();    // "Meow! Meow!"
    
    delete animal;
    delete dog;
    delete cat;
    
    return 0;
}