#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== Creating DiamondTrap objects =====" << std::endl;
    
    // 기본 생성자로 DiamondTrap 생성
    DiamondTrap default_diamond;
    
    // 이름이 있는 생성자로 DiamondTrap 생성
    DiamondTrap named_diamond("D4C");
    
    // 복사 생성자로 DiamondTrap 생성
    DiamondTrap copy_diamond(named_diamond);
    
    std::cout << "\n===== Testing DiamondTrap functionality =====" << std::endl;
    
    // whoAmI() 함수 테스트
    std::cout << "\nTesting whoAmI():" << std::endl;
    default_diamond.whoAmI();
    named_diamond.whoAmI();
    copy_diamond.whoAmI();
    
    // attack() 함수 테스트 (ScavTrap에서 상속)
    std::cout << "\nTesting attack() (inherited from ScavTrap):" << std::endl;
    named_diamond.attack("Enemy");
    
    // FragTrap의 특수 능력 테스트
    std::cout << "\nTesting highFivesGuys() (inherited from FragTrap):" << std::endl;
    named_diamond.highFivesGuys();
    
    // ScavTrap의 특수 능력 테스트
    std::cout << "\nTesting guardGate() (inherited from ScavTrap):" << std::endl;
    named_diamond.guardGate();
    
    // 속성 테스트
    std::cout << "\n===== Testing DiamondTrap attributes =====" << std::endl;
    
    // 공격 테스트
    std::cout << "\nAttack damage test (should be from FragTrap: 30):" << std::endl;
    named_diamond.attack("Target");
    
    // 에너지 포인트 테스트
    std::cout << "\nEnergy points test (should be from ScavTrap: 50):" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Attack " << i + 1 << ": ";
        named_diamond.attack("Enemy");
    }
    
    // 히트 포인트 테스트
    std::cout << "\nHit points test (should be from FragTrap: 100):" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Taking damage " << 20 << ": ";
        named_diamond.takeDamage(20);
    }
    
    // 수리 테스트
    std::cout << "\nRepair test:" << std::endl;
    named_diamond.beRepaired(50);
    
    std::cout << "\n===== End of tests, destructors will be called =====" << std::endl;
    
    return 0;
}