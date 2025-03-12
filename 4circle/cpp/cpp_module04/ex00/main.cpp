#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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
    
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* wrong = new WrongCat();
    
    std::cout << wrong->getType() << " " << std::endl;
    wrong->makeSound();  // WrongAnimal의 makeSound가 호출됨 (WrongCat이 아님)
    meta->makeSound();
    
    delete meta;
    delete wrong;
    
    return 0;
}