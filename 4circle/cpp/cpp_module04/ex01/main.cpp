#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    {
        std::cout << "===== 객체 배열 테스트 =====" << std::endl;
        const int arraySize = 10;
        Animal* animals[arraySize];

        // 절반은 Dog, 절반은 Cat으로 채우기
        for (int i = 0; i < arraySize; i++) {
            if (i < arraySize / 2) {
                animals[i] = new Dog();
            } else {
                animals[i] = new Cat();
            }
            std::cout << std::endl;
        }

        // 모든 Animal 객체 삭제
        for (int i = 0; i < arraySize; i++) {
            delete animals[i]; // 적절한 소멸자가 호출되어야 함
            std::cout << std::endl;
        }
    }

    std::cout << "\n===== 깊은 복사 테스트 =====" << std::endl;
    {
        // Dog 깊은 복사 테스트
        std::cout << "Dog 깊은 복사 테스트:" << std::endl;
        Dog* originalDog = new Dog();
        
        // 원본 Dog의 Brain에 아이디어 추가
        originalDog->getBrain()->setIdea(0, "I want to chase cats!");
        originalDog->getBrain()->setIdea(1, "Where is my bone?");
        
        // 복사 생성
        Dog* copyDog = new Dog(*originalDog);
        
        // 원본 삭제
        delete originalDog;
        
        // 복사본은 여전히 유효해야 함 (깊은 복사 확인)
        std::cout << "복사된 Dog의 Brain 아이디어:" << std::endl;
        std::cout << "아이디어 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
        std::cout << "아이디어 1: " << copyDog->getBrain()->getIdea(1) << std::endl;
        
        delete copyDog;
    }

    std::cout << "\n===== Cat 깊은 복사 테스트 =====" << std::endl;
    {
        // Cat 깊은 복사 테스트
        std::cout << "Cat 깊은 복사 테스트:" << std::endl;
        Cat originalCat;
        
        // 원본 Cat의 Brain에 아이디어 추가
        originalCat.getBrain()->setIdea(0, "I need to sleep on the couch");
        originalCat.getBrain()->setIdea(1, "Human should feed me now");
        
        // 대입 연산자를 통한 복사
        Cat copyCat;
        copyCat = originalCat;
        
        // 원본의 아이디어 변경
        originalCat.getBrain()->setIdea(0, "Changed idea");
        
        // 복사본의 아이디어는 변경되지 않아야 함 (깊은 복사 확인)
        std::cout << "원본 Cat의 아이디어 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "복사된 Cat의 아이디어 0: " << copyCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "복사된 Cat의 아이디어 1: " << copyCat.getBrain()->getIdea(1) << std::endl;
        
        // 자동으로 소멸자 호출됨
    }

    // 메모리 누수 확인을 위한 지연 (리눅스에서는 valgrind 사용 권장)
    // std::cout << "\n메모리 누수 확인을 위해 'leaks' 명령어를 실행할 수 있습니다." << std::endl;
    // system("leaks program_name");  // macOS에서만 동작

    return 0;
}