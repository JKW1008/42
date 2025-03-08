#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    // 기본 생성자를 사용한 FragTrap 생성
    FragTrap defaultFrag;
    
    // 이름을 지정한 FragTrap 생성
    FragTrap namedFrag("FR4G-TP");
	std::cout << "namedFrag name: " << namedFrag.getName() << std::endl;
    // 복사 생성자를 사용한 FragTrap 생성
    FragTrap copiedFrag(namedFrag);
    
    // 대입 연산자 테스트
    defaultFrag = namedFrag;
    
    std::cout << "\n--- Testing FragTrap Functions ---\n" << std::endl;
    
    // attack 함수 테스트
    namedFrag.attack("Enemy");
    
    // takeDamage 함수 테스트
    namedFrag.takeDamage(30);
    
    // beRepaired 함수 테스트
    namedFrag.beRepaired(20);
    
    // highFivesGuys 함수 테스트 (FragTrap의 특별 기능)
    namedFrag.highFivesGuys();
    
    // 에너지 포인트 소진 테스트
    std::cout << "\n--- Testing Energy Points Depletion ---\n" << std::endl;
    for (int i = 0; i < 11; i++) {
        std::cout << "Attempt " << i + 1 << ": ";
        namedFrag.attack("Target");
    }
    
    // 파괴 테스트 (소멸자 호출 확인)
    std::cout << "\n--- Destructors will be called now ---\n" << std::endl;
    
    return 0;
}