#include <Ice.hpp>

int main(void)
{
    ICharacter *me = new ICharacter("me");
    ICharacter *bob = new ICharacter("bob");
    AMateria *cure = new Cure();
    AMateria *ice = new Ice();

    me->equip(cure);
    me->equip(ice);
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->use(0, *bob);
    me->use(1, *bob);
    delete me;
    delete bob;
    delete cure;
    delete ice;
    return 0;
}